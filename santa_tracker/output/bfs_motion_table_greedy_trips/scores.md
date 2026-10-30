# bfs_motion_table_greedy_trips: scores

Solver: [`solvers/bfs_motion_table_greedy_trips/`](../../solvers/bfs_motion_table_greedy_trips/). Instances B–F of Hash Code 2022 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/santa_tracker/judge.py`. Outputs are in the instance folders next to this file.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| b_better_hurry | 122,311 | 52.3 |
| c_carousel | 1,692,098 | 397.8 |
| d_decorated_houses | 621,478 | 1.7 |
| e_excellent_weather | 229,363 | 590.2 |
| f_festive_flyover | 870,893 | 590.0 |

Sum over B–F: 3,536,143 (6th of the 39 finalist teams, whose totals also include A).

## Run setup

- Built per instance with `g++ -O2 -std=c++17 -o <letter> <letter>.cpp` and run as `./<letter> < <input> > <output>`. Without `-fopenmp` the `#pragma omp` lines have no effect, so each run uses one core.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- Code changes, applied to a copy only (the folder in `solvers/` is unchanged): `c.cpp`, `e.cpp` and `f.cpp` got a 590 s stop, checked in the main loop and per row of the target search. The program then writes the current trip and the plan so far. `b.cpp` and `d.cpp` are unchanged.
- The stop cut E at game time 158 of 1,200 and F at game time 407 of 600, so those two scores come from partial plans. C finishes (375–398 s) and its output is byte-identical to a run without the patch.
- F depends on the machine's speed, so it differs between runs: an unpatched run finished in 576 s and scored 1,061,182, a patched first-round run stopped at game time 520 with 967,522, and this run stopped at 407 with 870,893. The other four outputs are byte-identical to the first round.
- The upstream README reports E 1,109,883, reached with no 10-minute limit. Under the limit, on one core, this program scores 229,363.
