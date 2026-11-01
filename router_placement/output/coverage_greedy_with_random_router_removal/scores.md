# coverage_greedy_with_random_router_removal: scores

Solver: [`solvers/coverage_greedy_with_random_router_removal/`](../../solvers/coverage_greedy_with_random_router_removal/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | invalid: places a router twice | | | |
| rue_de_londres | 57,991,063 | 57,991,063 | 67 | 2 |
| opera | 171,942,099 | **171,942,099** | 476 | 2 |
| lets_go_higher | no output in 10 minutes | | | |

The sum of means is 229,933,162. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o aleksey aleksey.cpp`, then, with the instance in the current folder, `./aleksey charleston_road`, which writes `charleston_road.out`. The other programs in the folder were not kept for themselves.
