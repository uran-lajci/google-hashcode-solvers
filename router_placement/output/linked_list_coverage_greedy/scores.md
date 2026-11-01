# linked_list_coverage_greedy: scores

Solver: [`solvers/linked_list_coverage_greedy/`](../../solvers/linked_list_coverage_greedy/). The four instances of Hash Code 2017 Final.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| charleston_road | 21,962,412 | 21,962,412 | 2 | 2 |
| rue_de_londres | 56,449,071 | 56,449,071 | 7 | 2 |
| opera | 169,222,092 | 169,222,092 | 39 | 2 |
| lets_go_higher | 290,106,517 | 290,106,517 | 50 | 2 |

The sum of means is 537,740,092. The top team's total is 548,065,447, and the 5% line is 520,662,175. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/router_placement/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as follows. `python3 main.py <input> <output>`.
