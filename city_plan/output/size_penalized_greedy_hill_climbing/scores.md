# size_penalized_greedy_hill_climbing: scores

Solver: [`solvers/size_penalized_greedy_hill_climbing/`](../../solvers/size_penalized_greedy_hill_climbing/). Hash Code 2018 Final, instances B, C, D, E, F, 10 runs each. Every output was scored with `google-hashcode-judge/city_plan/judge.py`; all 50 are valid. Outputs are in the instance folders next to this file.

## Scores per run

| Seed | B (`b_short_walk`) | C (`c_going_green`) | D (`d_wide_selection`) | E (`e_precise_fit`) | F (`f_different_footprints`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 4,903,074 | 8,607,000 | 7,746,652 | 4,803,835 | 7,003,342 | 33,063,903 |
| 12 | 4,903,567 | 8,609,199 | 7,749,734 | 4,803,700 | 7,003,792 | 33,069,992 |
| 23 | 4,906,081 | 8,608,576 | 7,749,714 | 4,803,805 | 7,001,933 | 33,070,109 |
| 34 | 4,902,968 | 8,606,819 | 7,741,552 | 4,803,745 | 7,003,009 | 33,058,093 |
| 45 | 4,903,273 | 8,607,684 | 7,749,771 | 4,803,860 | 7,003,182 | 33,067,770 |
| 56 | 4,903,418 | 8,609,832 | 7,750,271 | 4,803,810 | 7,003,284 | 33,070,615 |
| 67 | 4,901,959 | 8,610,985 | 7,750,808 | 4,803,915 | 7,003,625 | 33,071,292 |
| 78 | 4,902,508 | 8,612,123 | 7,742,521 | 4,803,975 | 7,003,912 | 33,065,039 |
| 89 | 4,903,206 | 8,616,236 | 7,750,264 | 4,803,955 | 7,003,975 | 33,077,636 |
| 100 | 4,899,900 | 8,614,505 | 7,749,617 | 4,803,980 | 7,004,244 | 33,072,246 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs |
|---|---:|---:|---:|---:|---:|---:|
| b_short_walk | 4,906,081 | 4,902,995 | 4,903,140 | 1,529 | 4,899,900 | 10/10 |
| c_going_green | 8,616,236 | 8,610,296 | 8,609,516 | 3,179 | 8,606,819 | 10/10 |
| d_wide_selection | 7,750,808 | 7,748,090 | 7,749,724 | 3,386 | 7,741,552 | 10/10 |
| e_precise_fit | 4,803,980 | 4,803,858 | 4,803,848 | 97 | 4,803,700 | 10/10 |
| f_different_footprints | 7,004,244 | 7,003,430 | 7,003,484 | 656 | 7,001,933 | 10/10 |

Sum of means over B–F: 33,068,670, which is 86.8% of the top team's 38,102,788. Sum of bests: 33,081,349 (11th of the 40 finalist teams, whose totals also include A).

## Run setup

- Built in `sol2/` with `g++ -O3 -std=c++23 -w -o solve main.cpp -lgomp` and run as `./solve <input> <output>`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- Built without `-fopenmp`, so each run used one thread. Upstream uses 20 threads, so it does more hill-climbing steps in the same time. `-lgomp` only resolves `omp_set_num_threads`.
- Changes, made to a copy; the `solvers/` copy is unpatched:
  - `main.cpp` takes one input and one output path, because upstream loops over fixed paths.
  - The hill climbing stops after 570 s instead of upstream's 10 minutes, so the output is written before the limit. Each run took about 570 s.
  - The seed: `std::random_device` now reads `HC_SEED`. The generator is `static`, so it is created once instead of on every step.
