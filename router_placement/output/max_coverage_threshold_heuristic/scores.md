# max_coverage_threshold_heuristic: scores

Solver: [`solvers/max_coverage_threshold_heuristic/`](../../solvers/max_coverage_threshold_heuristic/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,952,139 | 21,952,139 | 22 | 2 |
| rue_de_londres | 52,898,074 | 52,898,074 | 123 | 2 |
| opera | 162,479,089 | 162,479,089 | 30 | 2 |
| lets_go_higher | 289,785,712 | 289,785,712 | 135 | 2 |

The sum of means is 527,115,014. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. With the instance in the current folder, `HC_INST=charleston_road php router.php`.
- **Code changes.** `router.php` now solves the one instance named by `HC_INST`, where it used to loop over all four.
