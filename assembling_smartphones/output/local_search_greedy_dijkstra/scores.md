# local_search_greedy_dijkstra: scores

Solver: [`solvers/local_search_greedy_dijkstra.cpp`](../../solvers/local_search_greedy_dijkstra.cpp). Instances B–F of Hash Code 2020 Final, 10 seeds each. Every output was scored with `google-hashcode-judge/assembling_smartphones/judge.py`. Outputs: `<instance>/seed_<s>.out`.

## Scores per run

| Seed | B (`b_single_arm`) | C (`c_few_arms`) | D (`d_tight_schedule`) | E (`e_dense_workspace`) | F (`f_decentralized`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1,065,320 | 1,204,084 | 1,352,045 | 657,300 | 99,158 | 4,377,907 |
| 12 | 1,056,283 | 892,326 | 1,295,867 | 614,447 | 97,372 | 3,956,295 |
| 23 | 1,052,232 | 885,519 | 1,329,111 | 707,519 | 103,979 | 4,078,360 |
| 34 | 1,063,651 | 985,435 | 1,242,310 | 704,673 | 118,295 | 4,114,364 |
| 45 | 1,069,200 | 932,188 | 1,369,888 | 719,321 | 114,557 | 4,205,154 |
| 56 | 1,069,728 | 879,769 | 1,382,288 | 714,905 | 92,295 | 4,138,985 |
| 67 | 1,069,810 | 891,349 | 1,327,114 | 675,907 | 94,997 | 4,059,177 |
| 78 | 1,068,154 | 942,275 | 1,322,984 | 653,264 | 94,592 | 4,081,269 |
| 89 | 1,068,769 | 1,069,847 | 1,385,368 | 532,612 | 104,005 | 4,160,601 |
| 100 | 1,069,492 | 1,070,759 | 1,354,359 | 542,804 | 93,738 | 4,131,152 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| b_single_arm | 1,069,810 | 1,065,264 | 1,068,462 | 5,897 | 1,052,232 | 10/10 | 590.0 |
| c_few_arms | 1,204,084 | 975,355 | 937,232 | 102,257 | 879,769 | 10/10 | 590.1 |
| d_tight_schedule | 1,385,368 | 1,336,133 | 1,340,578 | 41,239 | 1,242,310 | 10/10 | 590.0 |
| e_dense_workspace | 719,321 | 652,275 | 666,604 | 65,218 | 532,612 | 10/10 | 590.0 |
| f_decentralized | 118,295 | 101,299 | 98,265 | 8,498 | 92,295 | 10/10 | 590.0 |

Sum of means: 4,130,326. Sum of best runs: 4,377,907.

## Run setup

- Seeds: 1, 12, 23, 34, 45, 56, 67, 78, 89, 100.
- Command: `./lsgd -m <B|C|D|E|F> --local-search --seed <s>`, with the default parameters and the default 50 iterations. Each run used its own working directory, with the official input linked as `input/<instance>.txt`. Compiled with `g++ -O2 -std=c++17`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`).
- One code change, applied to a copy only (the file in `solvers/` is unchanged): a 10-minute limit. A deadline is set 590 s after `main()` starts. Once it passes, the greedy stops assigning tasks and keeps its plan so far (still a valid plan), the local search starts no new iterations, and the best plan is written out.
- The limit cuts every run: all 50 runs stopped at about 590 s. One greedy pass takes about 140 s on C, 180 s on D and 280 s on B, and more than 10 minutes on E and F. So the local search has little time to run. On B the initial greedy finishes and the local search gets about one iteration, which improved the score in 1 of 10 runs. C gets up to 4 iterations (improved 7 of 10 runs) and D up to 2 (improved 5 of 10 runs). On E and F the initial greedy itself is cut, and those scores come from partial plans.
- The output file of each run (`output/<x>_<score>.out`) was copied to `<instance>/seed_<s>.out`.
