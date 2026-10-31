# row_balanced_greedy_pool_coloring: scores

Solver: [`solvers/row_balanced_greedy_pool_coloring/`](../../solvers/row_balanced_greedy_pool_coloring/). The single instance of Hash Code 2015 Qualification.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| hashcode_2015_qualification_round | 391 | under 1 |

This would place 12th of the 230 teams. The top team has 407.

## Run setup

- Scored with the official judge, `google-hashcode-judge/optimize_a_data_center/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Compiled with `javac -d out src/*.java`, and run from `src/` as `java -cp ../out Test`. It reads `data/dc.in` and writes `results/result.out`, so copy the instance to `src/data/dc.in` and create `src/results/`.
- No code changes. All 10 runs gave a byte-identical output.
