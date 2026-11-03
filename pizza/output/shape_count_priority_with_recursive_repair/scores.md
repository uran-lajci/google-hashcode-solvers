# shape_count_priority_with_recursive_repair: scores

Solver: [`solvers/shape_count_priority_with_recursive_repair/`](../../solvers/shape_count_priority_with_recursive_repair/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 34 | 34 | 0 | 2 |
| medium | 48,887 | 48,887 | 2 | 2 |
| big | 902,584 | 902,584 | 7 | 2 |

The sum of means is 951,505.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** In `src/`: `gcc -O2 main.c -lm`. With the four instances at `inputs/a_example.in`, `inputs/b_small.in`, `inputs/c_medium.in` and `inputs/d_big.in`, `./a.out` writes `inputs/<name>.out` for each.
