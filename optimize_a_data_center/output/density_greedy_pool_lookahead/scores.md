# density_greedy_pool_lookahead: scores

Solver: [`solvers/density_greedy_pool_lookahead/`](../../solvers/density_greedy_pool_lookahead/). The single instance of Hash Code 2015 Qualification.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| hashcode_2015_qualification_round | 387 | under 1 |

This would place 22nd of the 230 teams. The top team has 407. It is exactly on the 5% line of 387 (95% of 407 is 386.65).

## Run setup

- Scored with the official judge, `google-hashcode-judge/optimize_a_data_center/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Run from the repository root as `node hashcode_qualif_2015/solver/solver.js`, with the instance as `dc.in` in that root. It writes `submission.out`. The `solver/dc.in` in the repository was not used.
- No code changes. All 10 runs gave a byte-identical output.
