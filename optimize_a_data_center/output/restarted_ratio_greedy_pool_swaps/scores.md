# restarted_ratio_greedy_pool_swaps: scores

Solver: [`solvers/restarted_ratio_greedy_pool_swaps/`](../../solvers/restarted_ratio_greedy_pool_swaps/). The single instance of Hash Code 2015 Qualification, 10 runs.

## Scores

| Instance | Best | Mean | Worst |
|---|---:|---:|---:|
| hashcode_2015_qualification_round | 400 | 400.0 | 400 |

This would place 4th of the 230 teams. The top team has 407.

Output files are `run_<n>.out`.

## Run setup

- Scored with the official judge, `google-hashcode-judge/optimize_a_data_center/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built in `qualification/` with `g++ -O2 -std=c++17 -fpermissive -include bits/stdc++.h -o solve main.cpp aux.cpp io.cpp`, and run as `./solve < input`. It writes `best.out`.
- **Code change:** the original loops forever and never reaches its output, so `main.cpp` now writes `best.out` each time a restart beats the best so far. The search is unchanged.
- The program seeds `rand()` from the clock, so the runs differ and cannot be repeated exactly. Runs were started at least 3 seconds apart.
- **It crashes.** 5 of the 10 runs ended in a memory error (`double free or corruption` or `malloc(): invalid size`) after 5 to 119 seconds, and the other 5 reached the 10-minute limit. We did not fix this. The stored `best.out` is valid either way, because each is written in full before the next restart.
