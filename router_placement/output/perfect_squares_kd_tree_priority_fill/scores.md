# perfect_squares_kd_tree_priority_fill: scores

Solver: [`solvers/perfect_squares_kd_tree_priority_fill/`](../../solvers/perfect_squares_kd_tree_priority_fill/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 20,347,830 | 20,347,830 | 0 | 2 |
| rue_de_londres | 54,095,059 | 54,095,059 | 1 | 2 |
| opera | 168,251,035 | 168,251,035 | 1 | 2 |
| lets_go_higher | 278,207,727 | 278,207,727 | 3 | 2 |

The sum of means is 520,901,651. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. Needs the libkdtree++ headers, which the repository does not include (`libkdtree++-dev`). In `sol3/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -fopenmp -I/usr/include/kdtree++ -o solve main.cpp`, then, with the instance in the current folder, `HC_INST=charleston_road ./solve`.
- **Code changes.** `sol3/main.cpp` now reads the one instance named by `HC_INST` from the current folder and writes `sub_<instance>` there, where it used to loop over four fixed paths.
- **Re-listing.** Some outputs list the backbone cells in an order the statement does not allow, or list the initial cell. Our benchmark re-listed the same cells outward from the initial cell and dropped the initial cell before judging, and the output files here are those re-listed ones. The solver's own output fails the judge on those instances.
