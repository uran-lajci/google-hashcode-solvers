# instance_tailored_target_scheduler: scores

Solver: [`solvers/instance_tailored_target_scheduler/`](../../solvers/instance_tailored_target_scheduler/). Instances B–F of Hash Code 2019 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/compiling_google/judge.py`. Outputs are in the instance folders next to this file.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| b_narrow | 1,530,065 | 0.0 |
| c_urgent | 1,934,841 | 0.1 |
| d_typical | 1,250,354 | 0.1 |
| e_intriguing | 524,288 | 0.0 |
| f_big | 840,971 | 0.1 |

Sum over B–F: 6,080,519 (7th of the 41 finalist teams, whose totals also include A).

## Run setup

- Built with `g++ -O2 -std=c++17 -o <program> <program>.cpp` and run as `./<program> < <input> > <output>`. `acd.cpp` runs C and D, and `b.cpp`, `e.cpp` and `f.cpp` run their own instance.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes. The programs have no parameters and no randomness.
- The outputs are byte-identical to the first benchmark round.
