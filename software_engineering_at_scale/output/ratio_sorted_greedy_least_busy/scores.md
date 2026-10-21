# ratio_sorted_greedy_least_busy: scores

Solver: [`solvers/ratio_sorted_greedy_least_busy/`](../../solvers/ratio_sorted_greedy_least_busy/). Instances B–F of Hash Code 2021 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/software_engineering_at_scale/judge.py`. Outputs: `<instance>/deterministic.out`.

## Scores

| Instance | Score | Time (s) | Best of the 26 feature orders (judge) | Program's own pick (judge score) |
|---|---:|---:|---|---|
| b_breadth_of_choice | 11,552,060 | 44.0 | `Users/Diff/Bin` (ties with `Users/Diff/Services`) | `Users/Diff/Services` (11,552,060) |
| c_constrained_optimisation | 24,778,969 | 10.8 | `Users` | `Users` (24,778,969) |
| d_distinction | 73,298,662 | 5.5 | `Users/Diff/Services` | `Users/Diff/Services` (73,298,662) |
| e_expectation_maximisation | 35,821,807 | 0.4 | `Users/Bin` | `Users/Bin` (35,821,807) |
| f_five_thousand | 111,567,670 | 2.6 | `Users/Diff/Bin` | `Users/Diff/Bin` (111,567,670) |

Sum over B–F: 257,019,168.

## Run setup

- Command: `python3 polyhash.py <input>`, run from a fresh folder with an empty `solutions/` subfolder. Python 3.12.3 with `PYTHONHASHSEED=0`; no third-party packages.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes for the benchmark. The solver folder itself calls `strategie1` in `main()`, where upstream calls `strategie2` (see its README).
- Each run writes 26 plans, one per feature order (13 sort keys × 2 directions). All 26 were scored with the judge, and the best is `<instance>/deterministic.out`; the table names its order. On every instance the file the program ranks first by its own score scores the same, so the choice changes no number.
- The outputs (all 26 files) are byte-identical to the first benchmark round.
