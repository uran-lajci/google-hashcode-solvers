# greedy_bfs_arm_scheduler: scores

Solver: [`solvers/greedy_bfs_arm_scheduler.cpp`](../../solvers/greedy_bfs_arm_scheduler.cpp). Instances B–F of Hash Code 2020 Final, 10 seeds each. Every output was scored with `google-hashcode-judge/assembling_smartphones/judge.py`. Outputs: `<instance>/seed_<s>.out`.

## Scores per run

| Seed | B (`b_single_arm`) | C (`c_few_arms`) | D (`d_tight_schedule`) | E (`e_dense_workspace`) | F (`f_decentralized`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1,069,860 | 990,245 | 1,308,118 | 1,093,717 | 81,662 | 4,543,602 |
| 12 | 1,066,958 | 873,465 | 1,332,068 | 1,084,976 | 84,491 | 4,441,958 |
| 23 | 1,056,423 | 919,238 | 1,282,303 | 1,082,912 | 81,067 | 4,421,943 |
| 34 | 1,066,527 | 970,815 | 1,344,440 | 1,087,246 | 89,164 | 4,558,192 |
| 45 | 1,067,378 | 920,735 | 1,195,790 | 1,076,438 | 80,468 | 4,340,809 |
| 56 | 1,069,979 | 1,056,080 | 1,305,821 | 1,052,983 | 85,100 | 4,569,963 |
| 67 | 1,069,679 | 1,098,134 | 1,344,174 | 1,047,860 | 85,160 | 4,645,007 |
| 78 | 1,067,911 | 1,191,681 | 1,294,493 | 1,096,473 | 79,974 | 4,730,532 |
| 89 | 1,060,919 | 907,546 | 1,340,034 | 1,045,859 | 95,586 | 4,449,944 |
| 100 | 1,067,048 | 1,023,514 | 1,240,744 | 1,091,164 | 81,887 | 4,504,357 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| b_single_arm | 1,069,979 | 1,066,268 | 1,067,213 | 4,332 | 1,056,423 | 10/10 | 221.9 |
| c_few_arms | 1,191,681 | 995,145 | 980,530 | 98,964 | 873,465 | 10/10 | 64.2 |
| d_tight_schedule | 1,344,440 | 1,298,798 | 1,306,970 | 48,714 | 1,195,790 | 10/10 | 205.7 |
| e_dense_workspace | 1,096,473 | 1,075,963 | 1,083,944 | 19,574 | 1,045,859 | 10/10 | 381.9 |
| f_decentralized | 95,586 | 84,456 | 83,189 | 4,817 | 79,974 | 10/10 | 584.4 |

Sum of means: 4,520,631. Sum of best runs: 4,798,159.

## Run setup

- Seeds: 1, 12, 23, 34, 45, 56, 67, 78, 89, 100.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Compiled with `g++ -O2`.
- Code changes, applied to a copy only (the file in `solvers/` is unchanged):
  - the fixed seed `mt19937 mt(420)` becomes `mt19937 mt(HC_SEED)`, with one binary per seed (`-DHC_SEED=<s>`);
  - a 10-minute limit: the main loop stops once the longest iteration so far would no longer fit before 590 s, then writes the plan it has so far. This changes only the long runs. It cuts every F run short (see the times above).
