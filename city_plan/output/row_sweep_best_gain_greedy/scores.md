# row_sweep_best_gain_greedy: scores

Solver: [`solvers/row_sweep_best_gain_greedy/`](../../solvers/row_sweep_best_gain_greedy/). Instances B–F of Hash Code 2018 Final, one run each (the solver is deterministic on one core). Every output was scored with `google-hashcode-judge/city_plan/judge.py`. Outputs are in the instance folders next to this file.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| b_short_walk | 3,999,070 | 5.6 |
| c_going_green | 8,693,408 | 103.2 |
| d_wide_selection | 7,740,180 | 116.8 |
| e_precise_fit | 4,799,060 | 55.8 |
| f_different_footprints | 5,134,486 | 55.1 |

Sum over B–F: 30,366,204 (14th of the 40 finalist teams, whose totals also include A). That is 79.7% of the top team's 38,102,788.

## Run setup

- Built in `sol1/` with `g++ -O3 -std=c++23 -w -o solve main.cpp -lgomp` and run as `./solve <input> <output>`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- Built without `-fopenmp`, so each run used one thread. Upstream uses 12 threads. `-lgomp` only resolves `omp_set_num_threads`.
- One code change, made to a copy: `main.cpp` takes one input and one output path, because upstream loops over fixed paths. `Solver.h` is unchanged and the `solvers/` copy is unpatched.
- The outputs are byte-identical to the first run of the program, at the screen.
