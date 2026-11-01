# coverage_minus_cable_greedy: scores

Solver: [`solvers/coverage_minus_cable_greedy/`](../../solvers/coverage_minus_cable_greedy/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,313 | 21,962,313 | 1 | 2 |
| rue_de_londres | 58,144,021 | 58,144,021 | 5 | 2 |
| opera | 171,912,009 | 171,912,009 | 22 | 2 |
| lets_go_higher | 290,168,757 | 290,168,757 | 391 | 2 |

The sum of means is 542,187,100. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. In `Resolution/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve *.cpp`, then `./solve <input> <output>`.
- **Re-listing.** Some outputs list the backbone cells in an order the statement does not allow, or list the initial cell. Our benchmark re-listed the same cells outward from the initial cell and dropped the initial cell before judging, and the output files here are those re-listed ones. The solver's own output fails the judge on those instances.
