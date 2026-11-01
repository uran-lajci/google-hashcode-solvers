# per_balloon_dp_hill_climbing: scores

Solver: [`solvers/per_balloon_dp_hill_climbing/`](../../solvers/per_balloon_dp_hill_climbing/). The single instance of Hash Code 2015 Final, 10 runs.

## Scores

| Instance | Best | Mean | Worst |
|---|---:|---:|---:|
| hashcode_2015_final_round | 683,482 | 682,207.0 | 680,904 |

The best run would place 6th of the 65 teams. The top team has 700,913.

Output files are `run_<n>.out`.

## Run setup

- Scored with the official judge, `google-hashcode-judge/loon/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as `make`, then `mkdir -p results` and `./loon < input`. It runs until stopped and keeps its best plan in `results/best.txt`.
- **Code changes.** We changed two things. The original driver plans only up to 6 balloons, so `loon.cpp` now plans all 53 and then repeats the hill climbing step, writing `results/best.txt` as the score improves. The arrays in `DynamicProgramming.cpp` were one altitude too small, which crashed the program, so they now have room for it. We also added the missing `#include <cstddef>` to `Coordz.h`, so it compiles.
- Without our driver, with only the array and include fixes, the program scores 140,494 and stops after 56 seconds.
- The program seeds `rand()` from the clock, so the runs differ and cannot be repeated exactly. Runs were started a few seconds apart.
- All 10 runs reached the limit. Planning the 53 balloons takes most of the 10 minutes, so there is little time left for hill climbing, and a longer run should score higher.
