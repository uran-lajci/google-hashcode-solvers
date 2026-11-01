# gaussian_blur_placement: scores

Solver: [`solvers/gaussian_blur_placement/`](../../solvers/gaussian_blur_placement/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,350 | **21,962,533** | 35 | 10 |
| rue_de_londres | 57,867,314 | 57,921,109 | 296 | 10 |
| opera | no output in 10 minutes | | | |
| lets_go_higher | not run: stopped at `opera` | | | |

The sum of means is 79,829,664. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. In `Strategie/Strategie/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve *.cpp`, then `./solve <input> <output>`.
- **Code changes.** `main.cpp` now builds the `gaussian_blur` method. It was set to `bigcase`, and the method is chosen by a string in that line.
