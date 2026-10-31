"""MicroEvolve: iteratively improve a C++ solver via single-change LLM mutations.

Each iteration the model proposes ONE small search/replace edit to the solver.
We apply it, compile, run, and score it with the external validator. If the new
score is >= the best so far we keep the change; if strictly worse we revert.
The model runs as a single continuous conversation so it remembers prior diffs
and accept/reject decisions.
"""

import json
import os
import re
import shutil
import sys
import time
from argparse import ArgumentParser
from datetime import datetime

from dotenv import load_dotenv

import providers
from solver_run import compile_solver, run_and_score

# One search/replace block, matching the exact protocol the templates define.
BLOCK_RE = re.compile(
    r'<<<<<<< SEARCH\n(.*?)\n=======\n(.*?)\n>>>>>>> REPLACE',
    re.DOTALL,
)
FENCE_RE = re.compile(r'(?m)^\s*```.*$')

# Per-million-token prices (USD): input, output, cache read, cache write.
# OpenAI/Gemini cache prompt tokens automatically (no separate write surcharge),
# so their adapters always report cache_write=0 and the 'cache_write' value below
# is unused for them. VERIFY all non-Claude prices against each vendor's current
# pricing page before trusting the reported cost.
PRICES = {
    # Anthropic
    'claude-opus-4-8': {'in': 5.0, 'out': 25.0, 'cache_read': 0.5, 'cache_write': 6.25},
    'claude-opus-4-7': {'in': 5.0, 'out': 25.0, 'cache_read': 0.5, 'cache_write': 6.25},
    'claude-sonnet-4-6': {'in': 3.0, 'out': 15.0, 'cache_read': 0.3, 'cache_write': 3.75},
    'claude-haiku-4-5': {'in': 1.0, 'out': 5.0, 'cache_read': 0.1, 'cache_write': 1.25},
    # OpenAI
    'gpt-5': {'in': 1.25, 'out': 10.0, 'cache_read': 0.125, 'cache_write': 1.25},
    'gpt-5-mini': {'in': 0.25, 'out': 2.0, 'cache_read': 0.025, 'cache_write': 0.25},
    'o4-mini': {'in': 1.1, 'out': 4.4, 'cache_read': 0.275, 'cache_write': 1.1},
    # Google Gemini
    'gemini-2.5-pro': {'in': 1.25, 'out': 10.0, 'cache_read': 0.31, 'cache_write': 1.25},
    'gemini-2.5-flash': {'in': 0.30, 'out': 2.5, 'cache_read': 0.075, 'cache_write': 0.30},
    'gemini-2.5-flash-lite': {'in': 0.10, 'out': 0.40, 'cache_read': 0.025, 'cache_write': 0.10},
}

RULES = """\
You are an expert competitive programmer specializing in combinatorial \
optimization heuristics.

You are given the problem statement for the Mentorship and Teamwork problem from \
Google Hash Code and the complete source of a state-of-the-art C++ solver. The \
solver is evaluated exclusively on the single input instance `{instance}`. Your \
goal is to maximize the solver's score on this one instance; performance on other \
instances is irrelevant.

Rules, which apply for this entire conversation:
1. Propose exactly ONE change per response: a single, small, incremental \
modification to the solver.
2. Return the change as one or more search/replace blocks, and nothing else - no \
explanation, no rationale, no full source file.

Each block must have exactly this form:
<<<<<<< SEARCH
(lines copied VERBATIM from the current version of the solver, including all \
whitespace and indentation)
=======
(the replacement lines)
>>>>>>> REPLACE

The SEARCH text must appear exactly once in the current solver; include enough \
surrounding lines to make it unique. The blocks are applied programmatically by \
exact string replacement, so any deviation (paraphrased code, altered whitespace, \
line numbers, markdown fences inside the block) will cause the change to be \
rejected.

3. The modified solver must remain fully deterministic: repeated runs must produce \
the identical score. Do not introduce randomness; any pseudo-random generator must \
use a hard-coded fixed seed.
4. The solver must produce its final output within a fixed budget of 10 minutes; \
changes that exceed this budget will be rejected.
5. Do not re-propose a change that has already been attempted in this conversation, \
nor a trivial variant of one.
6. After each change I will apply it, compile and run the solver on `{instance}`, \
and report the resulting score and my accept/reject decision. A change is accepted \
only if its score is >= the best score so far; otherwise it is reverted. Your next \
diff must always apply to the current accepted version of the solver, which I will \
keep you informed of.

Problem statement:
{problem}

Current solver (version 0, score on `{instance}`: {baseline}):
```cpp
{source}
```
"""


def parse_blocks(text):
    """Return a list of (search, replace) tuples parsed from the model reply."""
    cleaned = FENCE_RE.sub('', text)
    return BLOCK_RE.findall(cleaned)


def apply_blocks(source, blocks):
    """Apply blocks to source. Returns (new_source, error). error is None on success."""
    out = source
    for i, (search, replace) in enumerate(blocks):
        count = out.count(search)
        if count != 1:
            head = search.splitlines()[0] if search.splitlines() else '(empty)'
            return None, (
                f'block {i + 1}: SEARCH text matched {count} times in the current '
                f'accepted solver (must match exactly once). First SEARCH line: {head!r}'
            )
        out = out.replace(search, replace, 1)
    return out, None


def cost_usd(model, usage):
    """Dollar cost for accumulated token usage, or None if the model is unpriced."""
    p = PRICES.get(model)
    if p is None:
        return None
    return (usage['input'] * p['in'] + usage['output'] * p['out']
            + usage['cache_read'] * p['cache_read']
            + usage['cache_write'] * p['cache_write']) / 1e6


# How many times to attempt one model call before giving up the run. The SDKs
# already retry internally; this is a coarser outer net that survives sustained
# transient outages (e.g. a multi-minute 529 overload window).
API_MAX_ATTEMPTS = 8


def _status_of(exc):
    """Best-effort HTTP status code from a provider SDK exception, or None."""
    for attr in ('status_code', 'code', 'status'):
        v = getattr(exc, attr, None)
        if isinstance(v, int):
            return v
    v = getattr(getattr(exc, 'response', None), 'status_code', None)
    return v if isinstance(v, int) else None


def _is_retryable(exc):
    """True for transient errors worth retrying: 5xx (incl. 529 overloaded),
    408/409/429, and network/unknown errors that carry no HTTP status."""
    s = _status_of(exc)
    if s is None:
        return True
    return s in (408, 409, 429) or s >= 500


def complete_with_retry(provider, model, system, messages, max_tokens, effort,
                        log, it, max_attempts=API_MAX_ATTEMPTS):
    """Call ``provider.complete`` with exponential backoff on transient errors.

    Permanent errors (e.g. 400/401/404) are raised immediately. After
    ``max_attempts`` transient failures the last exception is re-raised so the
    caller can stop the run cleanly; the best solver is already saved on disk.
    """
    delay = 5
    for attempt in range(1, max_attempts + 1):
        try:
            return provider.complete(model, system, messages, max_tokens, effort)
        except Exception as exc:
            if attempt == max_attempts or not _is_retryable(exc):
                raise
            wait = min(delay, 60)
            print(f'[{it:02d}] transient API error '
                  f'({type(exc).__name__}: {str(exc)[:100]}); '
                  f'retry {attempt}/{max_attempts - 1} in {wait}s')
            log({'iter': it, 'event': 'api_retry', 'attempt': attempt,
                 'wait': wait, 'error': f'{type(exc).__name__}: {str(exc)[:300]}'})
            time.sleep(wait)
            delay *= 2


def build_system(problem, instance, baseline_score, source):
    """Render the system prompt. `source` is always the version-0 solver, so the
    prompt is identical whether a run starts fresh or resumes from a checkpoint."""
    return RULES.format(instance=instance, problem=problem,
                        baseline=f'{baseline_score:,}', source=source)


def save_checkpoint(run_dir, data):
    """Atomically persist the run state so a crash mid-write never corrupts it."""
    path = os.path.join(run_dir, 'checkpoint.json')
    tmp = path + '.tmp'
    with open(tmp, 'w') as f:
        json.dump(data, f)
    os.replace(tmp, path)


def main():
    parser = ArgumentParser(description=__doc__)
    parser.add_argument('--solver', help='path to the .cpp solver to evolve')
    parser.add_argument('--validator', help='path to the validator directory')
    parser.add_argument('--instance',
                        help='instance name, resolved to <validator>/data/<instance>.in.txt')
    parser.add_argument('--iterations', type=int, default=None,
                        help='total iterations (default 20 for a fresh run; on '
                             '--resume, defaults to the original target)')
    parser.add_argument('--provider', default='anthropic',
                        choices=['anthropic', 'openai', 'google'])
    parser.add_argument('--model', default='claude-opus-4-8',
                        help='must be a model of the chosen --provider')
    parser.add_argument('--effort', default='auto',
                        choices=['auto', 'low', 'medium', 'high'],
                        help='reasoning effort, mapped to each provider')
    parser.add_argument('--resume', metavar='RUN_DIR',
                        help='resume a stopped run from its runs/<...> directory')
    args = parser.parse_args()

    load_dotenv('.env.local')
    problem = open('problem_definition.md').read()

    if args.resume:
        # --- Resume an existing run from its checkpoint ---
        run_dir = args.resume.rstrip('/')
        ckpt_path = os.path.join(run_dir, 'checkpoint.json')
        if not os.path.exists(ckpt_path):
            sys.exit(f'Nothing to resume in {run_dir}: checkpoint.json is missing '
                     '(wrong directory, or the run was killed before finishing its '
                     'first iteration).')
        ckpt = json.load(open(ckpt_path))
        # The checkpoint is the source of truth for run parameters; --validator
        # may be re-supplied in case the validator directory has moved.
        args.provider = ckpt['provider']
        args.model = ckpt['model']
        args.effort = ckpt['effort']
        instance = ckpt['instance']
        validator = args.validator or ckpt['validator']
        iterations = args.iterations if args.iterations is not None else ckpt['iterations']
        baseline_score = ckpt['baseline_score']
        solver_basename = ckpt['solver_basename']
        solver_name = os.path.splitext(solver_basename)[0]

        if ckpt['next_iter'] > iterations:
            sys.exit(f'This run already completed {ckpt["iterations"]} iterations. '
                     f'Re-run with --iterations N (a new total greater than '
                     f'{ckpt["iterations"]}) to evolve it further.')

        input_path = os.path.join(validator, 'data', f'{instance}.in.txt')
        if not os.path.exists(input_path):
            sys.exit(f'Instance not found: {input_path} (pass --validator if it moved).')

        work_path = os.path.join(run_dir, solver_basename)
        output_path = os.path.join(run_dir, 'output.txt')
        # Restore the accepted (best) source and the v0 source for the system prompt.
        accepted_source = open(os.path.join(run_dir, 'best_solver.cpp')).read()
        open(work_path, 'w').write(accepted_source)
        system = build_system(problem, instance, baseline_score,
                              open(os.path.join(run_dir, 'solver_v0.cpp')).read())
        messages = ckpt['messages']
        best_score = ckpt['best_score']
        accepts = ckpt['accepts']
        usage = ckpt['usage']
        start_iter = ckpt['next_iter']
        history = open(os.path.join(run_dir, 'history.jsonl'), 'a')

        def log(record):
            history.write(json.dumps(record) + '\n')
            history.flush()

        log({'event': 'resume', 'from_iter': start_iter, 'best': best_score})
        print(f'[resume] {solver_name} on {instance} from iter {start_iter} '
              f'(best so far {best_score:,}, target {iterations} iters)')
    else:
        # --- Fresh run ---
        if not (args.solver and args.validator and args.instance):
            sys.exit('A fresh run needs --solver, --validator and --instance '
                     '(or pass --resume RUN_DIR to continue a stopped run).')
        validator = args.validator
        instance = args.instance
        iterations = args.iterations if args.iterations is not None else 20
        solver_basename = os.path.basename(args.solver)
        solver_name = os.path.splitext(solver_basename)[0]

        input_path = os.path.join(validator, 'data', f'{instance}.in.txt')
        if not os.path.exists(input_path):
            sys.exit(f'Instance not found: {input_path}')
        accepted_source = open(args.solver).read()

        # Evolve a working copy inside the run dir; the original --solver file is
        # read once and never modified. The run dir name records solver + instance.
        run_dir = os.path.join(
            'runs', f'{solver_name}__{instance}__{datetime.now():%Y%m%d-%H%M%S}')
        os.makedirs(run_dir, exist_ok=True)
        work_path = os.path.join(run_dir, solver_basename)
        open(work_path, 'w').write(accepted_source)
        shutil.copy2(work_path, os.path.join(run_dir, 'solver_v0.cpp'))
        history = open(os.path.join(run_dir, 'history.jsonl'), 'w')
        output_path = os.path.join(run_dir, 'output.txt')

        def log(record):
            history.write(json.dumps(record) + '\n')
            history.flush()

        # Baseline: compile + score version 0.
        ok, binary, stderr = compile_solver(work_path)
        if not ok:
            sys.exit(f'Baseline solver does not compile:\n{stderr}')
        best_score, detail = run_and_score(binary, input_path, output_path, validator)
        if best_score is None:
            sys.exit(f'Baseline solver failed to score: {detail}')
        print(f'[baseline] {solver_name} on {instance}: {best_score:,}')
        log({'iter': 0, 'event': 'baseline', 'score': best_score})
        shutil.copy2(work_path, os.path.join(run_dir, 'best_solver.cpp'))

        baseline_score = best_score
        system = build_system(problem, instance, baseline_score, accepted_source)
        messages = [{
            'role': 'user',
            'content': 'Propose your first change now: the single modification you '
                       'expect to have the highest positive impact on the score.',
        }]
        accepts = 0
        usage = {'input': 0, 'output': 0, 'cache_read': 0, 'cache_write': 0}
        start_iter = 1

    provider = providers.get(args.provider)

    def checkpoint(next_iter):
        """Persist the full run state (atomically), keyed by the next iteration."""
        save_checkpoint(run_dir, {
            'next_iter': next_iter, 'best_score': best_score, 'accepts': accepts,
            'usage': usage, 'baseline_score': baseline_score, 'iterations': iterations,
            'provider': args.provider, 'model': args.model, 'effort': args.effort,
            'instance': instance, 'validator': os.path.abspath(validator),
            'solver_basename': solver_basename, 'messages': messages,
        })

    aborted = False
    for it in range(start_iter, iterations + 1):
        # Checkpoint the consistent state from the previous iteration *before* the
        # next (failure-prone) model call, so a crash here resumes exactly at `it`.
        checkpoint(it)
        try:
            result = complete_with_retry(
                provider, args.model, system, messages, 16000, args.effort, log, it)
        except Exception as exc:
            print(f'\n[aborted] model call failed after {API_MAX_ATTEMPTS} attempts '
                  f'({type(exc).__name__}: {str(exc)[:200]}).')
            print(f'[saved] best score {best_score:,} is preserved in '
                  f'{run_dir}/best_solver.cpp')
            print(f'[resume] continue from iter {it} with:\n'
                  f'         uv run evolve.py --resume {run_dir}')
            log({'iter': it, 'event': 'aborted',
                 'error': f'{type(exc).__name__}: {str(exc)[:300]}'})
            aborted = True
            break
        reply = result.text
        messages.append({'role': 'assistant', 'content': reply})

        turn = result.usage
        for k, v in turn.items():
            usage[k] += v
        log({'iter': it, 'event': 'usage', **turn})

        blocks = parse_blocks(reply)
        if not blocks:
            feedback = (
                'Your response contained no valid search/replace block. Reply with '
                'one or more blocks in the exact required format, applied to the '
                'current accepted version of the solver.'
            )
            print(f'[{it:02d}] no parseable diff -> REJECTED')
            log({'iter': it, 'event': 'parse_error', 'reply': reply[:2000]})
            messages.append({'role': 'user', 'content': feedback})
            continue

        candidate, err = apply_blocks(accepted_source, blocks)
        if err is not None:
            feedback = (
                f'Your change could not be applied: {err}. Remember the next diff '
                f'must apply verbatim to the current accepted version. The accepted '
                f'version is unchanged; propose a different single change.'
            )
            print(f'[{it:02d}] apply failed -> REJECTED ({err})')
            log({'iter': it, 'event': 'apply_error', 'detail': err, 'blocks': blocks})
            messages.append({'role': 'user', 'content': feedback})
            continue

        open(work_path, 'w').write(candidate)
        ok, binary, stderr = compile_solver(work_path)
        if not ok:
            open(work_path, 'w').write(accepted_source)  # revert disk
            feedback = (
                'Your change was applied but the solver failed to compile. Compiler '
                f'errors:\n{stderr.strip()[:1500]}\nThis change is REJECTED; the '
                'accepted version is unchanged. Propose a different single change '
                'that compiles.'
            )
            print(f'[{it:02d}] compile failed -> REJECTED')
            log({'iter': it, 'event': 'compile_error', 'stderr': stderr[:2000], 'blocks': blocks})
            messages.append({'role': 'user', 'content': feedback})
            continue

        score, detail = run_and_score(binary, input_path, output_path, validator)
        if score is None:
            open(work_path, 'w').write(accepted_source)  # revert disk
            feedback = (
                f'Your change compiled but failed at runtime/validation: {detail}. '
                'REJECTED; the accepted version is unchanged. Propose a different '
                'single change.'
            )
            print(f'[{it:02d}] runtime/validation failed -> REJECTED ({detail})')
            log({'iter': it, 'event': 'run_error', 'detail': detail, 'blocks': blocks})
            messages.append({'role': 'user', 'content': feedback})
            continue

        if score >= best_score:
            prev = best_score
            best_score = score
            accepted_source = candidate
            accepts += 1
            shutil.copy2(work_path, os.path.join(run_dir, 'best_solver.cpp'))
            feedback = (
                f'Applied. New score: {score:,} (previous best: {prev:,}). ACCEPTED '
                f'- this is now the current accepted version. Propose your next '
                f'single change.'
            )
            print(f'[{it:02d}] score {score:,} >= best {prev:,} -> ACCEPTED')
            log({'iter': it, 'event': 'accept', 'score': score, 'best': best_score, 'blocks': blocks})
        else:
            open(work_path, 'w').write(accepted_source)  # revert disk
            feedback = (
                f'Applied. New score: {score:,} (previous best: {best_score:,}). '
                f'REJECTED - strictly worse than the best, so reverted. The accepted '
                f'version remains the previous best. Propose a different single change.'
            )
            print(f'[{it:02d}] score {score:,} < best {best_score:,} -> REJECTED')
            log({'iter': it, 'event': 'reject', 'score': score, 'best': best_score, 'blocks': blocks})

        messages.append({'role': 'user', 'content': feedback})

    # The working copy already holds the best accepted version (every reject
    # reverts it on disk); best_solver.cpp in the run dir is the deliverable.
    open(work_path, 'w').write(accepted_source)
    total_cost = cost_usd(args.model, usage)
    log({'event': 'totals', 'provider': args.provider, 'model': args.model,
         **usage, 'cost_usd': total_cost})
    history.close()

    # Persist the final state so the run can be extended later with more
    # iterations (--resume --iterations N). On abort, the checkpoint for the
    # unfinished iteration is already on disk, so leave it untouched.
    if not aborted:
        checkpoint(iterations + 1)

    prompt_total = usage['input'] + usage['cache_read'] + usage['cache_write']
    print(f'\n[done] baseline -> best: improvement = {best_score:,}; '
          f'accepted {accepts}/{iterations} changes. Best solver in {run_dir}/best_solver.cpp')
    print(f"[tokens] prompt={prompt_total:,} (uncached {usage['input']:,}, "
          f"cache-read {usage['cache_read']:,}, cache-write {usage['cache_write']:,}) "
          f"| output={usage['output']:,}")
    cost_str = f'${total_cost:.4f}' if total_cost is not None else 'n/a (unpriced model)'
    print(f'[cost] {cost_str} ({args.provider}:{args.model})')


if __name__ == '__main__':
    main()
