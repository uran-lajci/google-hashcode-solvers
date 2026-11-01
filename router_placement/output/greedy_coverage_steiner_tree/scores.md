# greedy_coverage_steiner_tree: scores

Solver: [`solvers/greedy_coverage_steiner_tree/`](../../solvers/greedy_coverage_steiner_tree/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,464 | 21,962,464 | 1 | 2 |
| rue_de_londres | 57,419,007 | 57,419,007 | 3 | 2 |
| opera | 170,251,075 | 170,251,075 | 38 | 2 |
| lets_go_higher | 289,471,682 | 289,471,682 | 373 | 2 |

The sum of means is 539,104,228. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. In `GHC17/`: `g++ -std=c++17 -O2 -fpermissive -w -I. -ICSolver -ICReferee -ICReferee/modeles -ICTimer $(find . -name '*.cpp' | grep -v CTimer) -o solve`, then `./solve <input> <output>`.
- **Code changes.** We fixed three things for GCC. `maxm`, `minm` and `SPoint::min` in `SPoint.h` returned references to local variables, which crashed on Linux. `SCell::operator==` had no `return`. `CSolver.cpp` uses `std::filesystem` in place of the old experimental namespace.
