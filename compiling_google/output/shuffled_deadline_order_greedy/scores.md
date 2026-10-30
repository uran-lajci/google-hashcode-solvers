# shuffled_deadline_order_greedy: scores

Solver: [`solvers/shuffled_deadline_order_greedy/`](../../solvers/shuffled_deadline_order_greedy/). Hash Code 2019 Final, instances B, C, D, E, F, 10 runs each. Every output was scored with `google-hashcode-judge/compiling_google/judge.py`; a run the judge rejects counts as 0 in the statistics. Outputs are in the instance folders next to this file.

## Scores per run

| Seed | B (`b_narrow`) | C (`c_urgent`) | D (`d_typical`) | E (`e_intriguing`) | F (`f_big`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1,477,575 | 1,434,573 | 1,080,541 | 1 | invalid | 3,992,690 |
| 12 | 1,477,098 | 1,439,814 | 1,095,626 | 1 | invalid | 4,012,539 |
| 23 | 1,480,471 | 1,438,972 | 1,109,772 | 1 | invalid | 4,029,216 |
| 34 | 1,477,230 | 1,413,996 | 1,155,198 | 1 | invalid | 4,046,425 |
| 45 | 1,478,714 | 1,456,275 | 1,277,337 | 1 | invalid | 4,212,327 |
| 56 | 1,480,802 | 1,449,667 | 1,271,599 | 1 | invalid | 4,202,069 |
| 67 | 1,482,186 | 1,426,590 | 1,095,485 | 1 | invalid | 4,004,262 |
| 78 | 1,478,508 | 1,446,557 | 1,120,680 | 1 | invalid | 4,045,746 |
| 89 | 1,480,392 | 1,434,219 | 1,142,822 | 1 | invalid | 4,057,434 |
| 100 | 1,479,909 | 1,422,422 | 1,155,550 | 1 | invalid | 4,057,882 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| b_narrow | 1,482,186 | 1,479,288 | 1,479,312 | 1,719 | 1,477,098 | 10/10 | 8.6 |
| c_urgent | 1,456,275 | 1,436,308 | 1,436,772 | 12,884 | 1,413,996 | 10/10 | 5.1 |
| d_typical | 1,277,337 | 1,150,461 | 1,131,751 | 70,190 | 1,080,541 | 10/10 | 0.8 |
| e_intriguing | 1 | 1 | 1 | 0 | 1 | 10/10 | 0.5 |
| f_big | 0 | 0 | 0 | 0 | 0 | 0/10 | 63.1 |

Sum of means: 4,066,059. Sum of best runs: 4,215,799.

## Run setup

- Run as `pypy main.py <instance> -s <seed> -i -f -l error --solve module=mm_sort_shuffle` with PyPy 2.7.18 (7.3.17), as the upstream README recommends, and the instance in `in/<instance>.in`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes. `-i -f` make the harness write the plan even if the program's own scorer disagrees.
- Every F run writes an empty plan (`0` steps), and the judge rejects it because at least 1 step is required. Those files are kept as `seed_<n>.invalid.out`.
- The valid outputs are byte-identical to the first benchmark round.
