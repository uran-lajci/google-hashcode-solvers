# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

An LLM-in-the-loop optimizer for a single C++ solver of the "Mentorship and Teamwork" problem (Google Hash Code 2022). Each iteration the model proposes ONE search/replace edit; the harness applies it, compiles, runs, scores it against an external validator, and keeps it only if `score >= best_score`. There is no training and no ML pipeline — the entire "evolution" is a conversation loop plus a fitness gate.

## External dependencies (not in this repo)

- **A validator directory** containing `index.js` and `data/<instance>.in.txt`. Lives in a separate repo; `--validator` points at it. `node` must be on PATH.
- **`g++`** — solvers are compiled with `-O2`, trying `c++17` then `c++20` (first standard that compiles wins).
- **API keys** in `.env.local` (`ANTHROPIC_API_KEY` / `OPENAI_API_KEY` / `GEMINI_API_KEY`), loaded via `load_dotenv('.env.local')`. `.env.local` is gitignored.

`pyproject.toml` has only `[tool.ruff]` / `[tool.mypy]` — no `[project]` table and no lockfile, so `uv sync` (per the README) installs nothing. Runtime deps are implicit: `python-dotenv`, plus `anthropic` / `openai` / `google-genai` for whichever provider is used (each is imported lazily inside its adapter's `__init__`, so only the selected provider's SDK needs to be installed).

## Commands

```bash
# Fresh run (cwd must be the repo root — problem_definition.md is opened by relative path)
uv run evolve.py --solver best_solvers/c.cpp --validator /path/to/validator \
  --instance c_collaboration --iterations 100

# Other providers (--model must belong to --provider)
uv run evolve.py ... --provider openai --model gpt-5
uv run evolve.py ... --provider google --model gemini-2.5-pro

# Resume / extend. --iterations is the new TOTAL, not a delta.
uv run evolve.py --resume runs/c__c_collaboration__20260626-193024 --iterations 200

# Score a solver once, no LLM
uv run solver_run.py -s best_solvers/c.cpp -i /path/to/validator/data/c_collaboration.in.txt \
  -o /tmp/out.txt -V /path/to/validator

# Analysis of a completed run (summarize_run takes a directory NAME under runs/, the
# other two take history.jsonl paths or globs)
uv run data_analysis/summarize_run.py -f c__c_collaboration__20260626-193024
uv run data_analysis/extract_traces.py 'experiments/*/run_*/history.jsonl' -o traces.csv
uv run data_analysis/extract_improving.py 'experiments/*/run_*/history.jsonl'

# Lint / typecheck (configured but no CI, no test suite)
uv run ruff check . && uv run ruff format --check .
uv run mypy .
```

There are no tests. The de-facto smoke test is a short run: `--iterations 2` on any instance.

## Architecture

Three modules, deliberately thin:

- [evolve.py](evolve.py) — the whole loop and all state. Owns the prompt (`RULES`), block parsing/application, accept/reject policy, checkpointing, and cost accounting.
- [providers.py](providers.py) — the only place a vendor SDK is imported. Each adapter's `complete()` returns a `Result(text, usage)` with usage normalized to `input`/`output`/`cache_read`/`cache_write`. The loop never sees provider-specific shapes. `--effort` is a neutral level mapped per provider (Anthropic adaptive/`budget_tokens`, OpenAI `reasoning_effort`, Gemini `thinking_budget`); the `_BUDGETS` table serves the two that take token budgets.
- [solver_run.py](solver_run.py) — compile + run + validate + score-parse. Also standalone-runnable.

Invariants worth preserving when editing:

- **`--solver` is never modified.** Everything happens in `runs/<solver>__<instance>__<timestamp>/`, which holds `solver_v0.cpp` (baseline), the working copy `<solver>.cpp`, `best_solver.cpp` (deliverable), `history.jsonl`, `output.txt`, `checkpoint.json`.
- **The system prompt always embeds version 0**, never the current accepted source — that keeps the cached prefix stable across all iterations and identical between a fresh run and a resume. Accepted diffs live in the conversation turns instead. Changing this destroys prompt caching (cache reads dominate cost: a 100-iteration Opus run is ~$6).
- **Diffs apply to `accepted_source` in memory**, not to what's on disk. Every rejection path rewrites `work_path` back to `accepted_source`, so the working copy on disk always mirrors the accepted version.
- **`score >= best_score` accepts** — ties are accepted deliberately, letting the solver drift laterally through plateaus. `summarize_run.py` reports improving accepts and tie accepts separately.
- **Every failure mode feeds back as a user turn and continues the loop**, never crashes it: unparseable reply, SEARCH matching ≠ 1 time, compile error, runtime/validation failure. Each also logs a distinct `event` to `history.jsonl` (`parse_error`, `apply_error`, `compile_error`, `run_error`, `accept`, `reject`, `usage`, `api_retry`, `aborted`, `totals`).
- **Checkpoint is written *before* each model call**, keyed by the iteration about to run, so a crash resumes at exactly that iteration with the conversation intact. Written atomically via tmp + `os.replace`. A normal finish writes a final checkpoint at `iterations + 1` so the run can be extended later.
- **Two retry layers**: the SDKs retry internally (`max_retries=6`), and `complete_with_retry` adds an outer exponential backoff (8 attempts, capped 60s) for sustained outages. Only transient errors retry — `_is_retryable` treats 408/409/429/5xx and status-less network errors as transient; 4xx like 401/404 raise immediately and abort the run cleanly with a printed `--resume` command.

`run_and_score` has a validator quirk baked in: the validator's `readFile` joins `__dirname` with its argument, so the input path must be passed *relative to the validator dir* and the submission must be copied next to the input as `<input>.in.txt.out.txt`. Score is parsed from the `Score:` line after stripping ANSI colour codes. Solver stdout is the submission, stderr is discarded; the run timeout is 600s, matching rule 4 in the prompt.

## Data layout

`best_solvers/{b,c,d,e,f}.cpp` are the best-known solvers, one per instance letter. `experiments/<name>/run_{1..5}/` are archived completed runs (5 seeds each) with the same file layout as `runs/`, where `<name>` is the instance suffix: `better_start_small`→b, `collaboration`→c, `dense_schedule`→d, `exceptional_skills`→e, `find_great_mentors`→f. Instance names passed to `--instance` are the full `b_better_start_small` form. Committed checkpoints have their `validator` path scrubbed to `<VALIDATOR_PATH>`, so resuming an archived run requires passing `--validator`.

`runs/` (fresh output) is not gitignored — only `.env.local` and compiled binaries under `experiments/*/run_*/` are.

## Prompt changes

`RULES` in [evolve.py](evolve.py) encodes the contract the loop enforces: exactly one change per response, search/replace blocks only with no prose, determinism (fixed seeds), the 10-minute budget, and no re-proposing prior attempts. If you change the block format there, `BLOCK_RE`/`FENCE_RE` and `data_analysis/extract_improving.py` must change with it.

`PRICES` is hand-maintained per-million-token pricing. Non-Anthropic entries carry a "verify before trusting" warning; OpenAI/Gemini adapters always report `cache_write=0`, so those rows' `cache_write` values are unused. An unpriced model reports cost as `n/a` rather than failing.
