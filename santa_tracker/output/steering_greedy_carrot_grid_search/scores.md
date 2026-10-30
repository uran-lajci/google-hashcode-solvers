# steering_greedy_carrot_grid_search: scores

Solver: [`solvers/steering_greedy_carrot_grid_search/`](../../solvers/steering_greedy_carrot_grid_search/). Instances B–F of Hash Code 2022 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/santa_tracker/judge.py`. Outputs are in the instance folders next to this file.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| b_better_hurry | 89,815 | 0.3 |
| c_carousel | 1,664,854 | 26.9 |
| d_decorated_houses | 0 | 11.0 |
| e_excellent_weather | 1,050,706 | 7.9 |
| f_festive_flyover | 1,352,019 | 4.4 |

Sum over B–F: 4,157,394 (3rd of the 39 finalist teams, whose totals also include A).

## Run setup

- Built with `g++ -O2 -std=c++17 -o santa santa.cpp`. Each run gets the instance as `b.txt` to `f.txt` in a fresh working directory and its number on stdin (1 = B … 5 = F), and writes `sol_<letter>.txt`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes. The program has no parameters and no randomness.
- The outputs are byte-identical to the first benchmark round.
- D scores 0: D has range 0, and this steering never places the sleigh exactly on a gift's cell.
