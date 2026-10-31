> **Greedy solvers evolved by an LLM, one per instance**
>
> Source: https://github.com/uran-lajci/MicroEvolve
>
> Method overview:
> - Starts from a strong C++ greedy solver and asks an LLM for small, local edits to the code.
> - Compiles and scores each edit on one instance, and keeps it only if the score improves.
> - The result is a separate program for each instance, in `best_solvers/`. The programs are deterministic.
> - `evolve.py` is the method; `experiments/` holds the runs that produced the programs.
>
> Best per instance in our runs: B 1,057,446, C 285,714, D 2,853,365, E 1,656,494, F 1,381,929 ([scores](../../output/llm_evolved_greedy/scores.md)).

# MicroEvolve
An LLM-in-the-loop method that iteratively improves an existing high-performance C++ solver for the Mentorship and Teamwork problem (Google Hash Code 2022). It proposes localized edits, keeps score-improving changes, and sets new best-known scores on 4/5 instances—no training, fine-tuning, or human intervention required.

## Why "MicroEvolve"?

In biology, microevolution is the gradual change within a population through small mutations, with selection keeping the beneficial ones. MicroEvolve applies the same idea to code: the LLM introduces small mutations to an algorithm, and a fitness function selects the improvements — letting better solutions emerge one tiny change at a time.

## Installation

```bash
uv sync
```

## Configuration

Put the API key(s) for the provider(s) you want to use in `.env.local`:

```
ANTHROPIC_API_KEY=...
OPENAI_API_KEY=...
GEMINI_API_KEY=...
```

## Usage

Point the agent at a solver file and a validator directory, and name the
instance to optimize. The solver and validator live in their own repositories;
nothing about them is hard-coded here.

```bash
# Anthropic (default)
uv run evolve.py \
  --solver /path/to/solvers/b.cpp \
  --validator /path/to/validator \
  --instance b_better_start_small \
  --iterations 20

# OpenAI (use a reasoning model)
uv run evolve.py --solver /path/to/solvers/c.cpp --validator /path/to/validator \
  --instance c_collaboration --provider openai --model gpt-5

# Google Gemini
uv run evolve.py --solver /path/to/solvers/d.cpp --validator /path/to/validator \
  --instance d_dense_schedule --provider google --model gemini-2.5-pro
```

The instance name resolves to `<validator>/data/<instance>.in.txt`. The original
`--solver` file is never modified: each run creates
`runs/<solver>__<instance>__<timestamp>/` containing `solver_v0.cpp` (the
baseline), `best_solver.cpp` (the evolved result), `history.jsonl`, and a
`checkpoint.json` (kept after the run finishes so it can be extended later).

### Resuming or extending a run

Every iteration is checkpointed (the full conversation plus best score and token
usage), so you can always continue from where a run left off — whether it was
interrupted or finished normally:

```bash
# Continue a run that stopped early (API outage, Ctrl-C, reboot): picks up at
# the exact iteration it stopped on, with the agent's full memory intact.
uv run evolve.py --resume runs/d__d_dense_schedule__20260626-193024

# Extend a finished run with more iterations. --iterations is the new TOTAL,
# so to run 100 more after an initial 100, pass 200:
uv run evolve.py --resume runs/b__b_better_start_small__20260623-200111 --iterations 200
```

Resume reads everything (provider, model, effort, instance, iteration target)
from the checkpoint; pass `--validator` only if the validator directory has
moved. Resuming a finished run *without* raising `--iterations` does nothing and
prints how to extend it.

Flags:

- `--solver` — path to the `.cpp` solver to evolve (read-only; the result is
  written to the run directory).
- `--validator` — path to the validator directory (contains `index.js` and
  `data/`).
- `--instance` — instance name, resolved to `<validator>/data/<instance>.in.txt`.
- `--resume RUN_DIR` — continue a stopped run from its `runs/<...>` directory
  (replaces `--solver`/`--validator`/`--instance`).

- `--provider {anthropic,openai,google}` — which API to call (default `anthropic`).
- `--model` — a model id for the chosen provider (e.g. `claude-opus-4-8`,
  `gpt-5`, `gemini-2.5-pro`). Equivalent tiers across providers:

  | Tier     | Anthropic         | OpenAI       | Gemini                  |
  |----------|-------------------|--------------|-------------------------|
  | Frontier | claude-opus-4-8   | gpt-5        | gemini-2.5-pro          |
  | Mid      | claude-sonnet-4-6 | gpt-5-mini   | gemini-2.5-flash        |
  | Small    | claude-haiku-4-5  | o4-mini      | gemini-2.5-flash-lite   |

- `--effort {auto,low,medium,high}` — reasoning effort, mapped to each
  provider's own control (Anthropic thinking, OpenAI `reasoning_effort`, Gemini
  `thinking_budget`). Default `auto`.
