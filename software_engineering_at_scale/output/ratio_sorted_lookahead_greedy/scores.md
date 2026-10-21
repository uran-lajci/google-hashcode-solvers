# ratio_sorted_lookahead_greedy: scores

Solver: [`solvers/ratio_sorted_lookahead_greedy/`](../../solvers/ratio_sorted_lookahead_greedy/). Instances B–F of Hash Code 2021 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/software_engineering_at_scale/judge.py`. Outputs: `<instance>/deterministic.out`.

## Scores

| Instance | Score | Time (s) | Best of the 26 feature orders (judge) | Program's own pick (judge score) |
|---|---:|---:|---|---|
| b_breadth_of_choice | 5,543,662 | 44.7 | `Users/Diff/Bin` (ties with `Users/Diff/Services`, `Users/Diff`) | `Users/Diff` (5,543,662) |
| c_constrained_optimisation | 24,881,270 | 14.5 | `Users` | `Users` (24,881,270) |
| d_distinction | 73,185,071 | 6.6 | `Users/Diff/Services` | `Users/Diff/Services` (73,185,071) |
| e_expectation_maximisation | 35,821,807 | 1.5 | `Users/Bin` | `Users/Bin` (35,821,807) |
| f_five_thousand | 111,280,279 | 3.0 | `Users/Diff/Bin` | `Users/Diff/Bin` (111,280,279) |

Sum over B–F: 250,712,089.

## Run setup

- Command: `python3 polyhash.py <input>`, run from a fresh folder with an empty `solutions/` subfolder. Python 3.12.3 with `PYTHONHASHSEED=0`; no third-party packages.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes: the code is as published (`main()` calls `strategie2`).
- Each run writes 26 plans, one per feature order (13 sort keys × 2 directions). All 26 were scored with the judge, and the best is `<instance>/deterministic.out`; the table names its order. On every instance the file the program ranks first by its own score scores the same, so the choice changes no number.
- The outputs (all 26 files) are byte-identical to the first benchmark round.
