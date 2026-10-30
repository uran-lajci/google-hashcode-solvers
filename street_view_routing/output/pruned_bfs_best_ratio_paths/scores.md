# pruned_bfs_best_ratio_paths: scores

Solver: [`solvers/pruned_bfs_best_ratio_paths/`](../../solvers/pruned_bfs_best_ratio_paths/). The single instance of Hash Code 2014 Final (Paris), one run (the solver is deterministic). The output was scored with `google-hashcode-judge/street_view_routing/judge.py`. It is in the instance folder next to this file.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| hashcode_2014_final_round | 1,930,138 | 11.5 |

This would place 1st of the 54 finalist teams. The winner has 1,923,588.

## Run setup

- Built in `src/` with `g++ -O2 -std=gnu++11 -w -o solve main.cpp` and run from `src/` as `./solve paris`, with the instance copied to `data/paris.in`. It writes `out/paris.out`. The upstream Makefile builds without `-O2`.
- One run at a time, pinned with `taskset` to a physical core (CPU 0), with a 10-minute wall-clock limit (`timeout -k 10 600`). The run used a fresh working directory.
- No code changes. The program has no parameters and no randomness.
- The output is byte-identical to the two earlier benchmark runs. The screen run took 7.5 s.
