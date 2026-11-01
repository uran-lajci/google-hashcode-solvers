# scored_greedy_with_mst_backbone: scores

Solver: [`solvers/scored_greedy_with_mst_backbone/`](../../solvers/scored_greedy_with_mst_backbone/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,197 | 21,962,197 | 0 | 2 |
| rue_de_londres | 58,301,019 | **58,301,019** | 2 | 2 |
| opera | 168,673,084 | 168,673,084 | 5 | 2 |
| lets_go_higher | 290,201,347 | **290,201,347** | 16 | 2 |

The sum of means is 539,137,647. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve main.cpp`, then `./solve charleston_road.in`, which writes `charleston_road.in.out`.
- **Re-listing.** Some outputs list the backbone cells in an order the statement does not allow, or list the initial cell. Our benchmark re-listed the same cells outward from the initial cell and dropped the initial cell before judging, and the output files here are those re-listed ones. The solver's own output fails the judge on those instances.
