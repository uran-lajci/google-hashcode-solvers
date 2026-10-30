# subset_sum_partition_scheduler: scores

Solver: [`solvers/subset_sum_partition_scheduler/`](../../solvers/subset_sum_partition_scheduler/). Hash Code 2019 Final, instance C, 10 runs each. Every output was scored with `google-hashcode-judge/compiling_google/judge.py`; a run the judge rejects counts as 0 in the statistics. Outputs are in the instance folders next to this file.

## Scores per run

| Seed | C (`c_urgent`) | Sum |
|---:|---:|---:|
| 1 | 1,941,613 | 1,941,613 |
| 12 | 1,950,379 | 1,950,379 |
| 23 | 1,943,500 | 1,943,500 |
| 34 | 1,950,354 | 1,950,354 |
| 45 | 1,943,383 | 1,943,383 |
| 56 | 1,945,577 | 1,945,577 |
| 67 | 1,941,613 | 1,941,613 |
| 78 | 1,941,752 | 1,941,752 |
| 89 | 1,943,949 | 1,943,949 |
| 100 | 1,937,085 | 1,937,085 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| c_urgent | 1,950,379 | 1,943,920 | 1,943,442 | 4,060 | 1,937,085 | 10/10 | 3.8 |

Sum of means: 1,943,920. Sum of best runs: 1,950,379.

## Run setup

- Run as `pypy main.py c_urgent -s <seed> -i -f -l error --solve module=solve_c_la` with PyPy 2.7.18 (7.3.17), as the upstream README recommends, and the instance in `in/c_urgent.in`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes. `-i -f` make the harness write the plan even if the program's own scorer disagrees.
- Written for C only. In the first round it crashed on B, D and E and scored 0 on F, so it was re-run on C only.
- The outputs are byte-identical to the first benchmark round.
