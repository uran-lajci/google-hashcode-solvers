# density_greedy_worst_pool_improvement: scores

Solver: [`solvers/density_greedy_worst_pool_improvement/`](../../solvers/density_greedy_worst_pool_improvement/). The single instance of Hash Code 2015 Qualification. One program with five modes, 10 runs per mode.

## Scores

| Mode | Best | Mean | Worst |
|---|---:|---:|---:|
| `full-2-3` | 398 | 397.8 | 397 |
| `full-1-2` | 398 | 397.2 | 397 |
| `full-3-4` | 397 | 396.4 | 394 |
| `mockplacement` | 396 | 394.8 | 394 |
| `full-1` | 394 | 390.0 | 382 |

The best mode, `full-2-3`, would place 7th of the 230 teams at 398. The top team has 407.

Output files are `<mode>_run_<n>.out`.

## Run setup

- Scored with the official judge, `google-hashcode-judge/optimize_a_data_center/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built in `datacenter/` with `g++ -O2 -std=c++20 -fpermissive -o solve code/main.cpp`, and run as `./solve <mode> < input > output`. The modes are the `STRATEGIES` in `datacenter/Makefile`.
- No code changes. Each run takes about 3 seconds. The runs differ because the program's random choices are not fixed by us.
