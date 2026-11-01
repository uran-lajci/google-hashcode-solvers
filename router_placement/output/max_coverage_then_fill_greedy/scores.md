# max_coverage_then_fill_greedy: scores

Solver: [`solvers/max_coverage_then_fill_greedy/`](../../solvers/max_coverage_then_fill_greedy/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,312 | 21,962,312 | 3 | 2 |
| rue_de_londres | 56,263,059 | 56,263,059 | 9 | 2 |
| opera | 169,156,094 | 169,156,094 | 7 | 2 |
| lets_go_higher | 290,125,827 | 290,125,827 | 9 | 2 |

The sum of means is 537,507,292. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. In `googleHashCode2017/`: `g++ -std=c++17 -O2 -fpermissive -w *.cpp -o solve`, then `./solve charleston_road.in`, which writes `charleston_road.out`.
- **Code changes.** We fixed one thing for GCC. `distance` in `Coordinate.h` and `Coordinate.cpp` returned a reference to a local variable, which crashed on Linux.
