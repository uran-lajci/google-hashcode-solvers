# smallest_piece_walk_then_expand: scores

Solver: [`solvers/smallest_piece_walk_then_expand/`](../../solvers/smallest_piece_walk_then_expand/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 40 | 40 | 0 | 2 |
| medium | 48,940 | 48,940 | 2 | 2 |
| big | 902,212 | 902,212 | 20 | 2 |

The sum of means is 951,192.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** With the instances at `a_example.in`, `b_small.in`, `c_medium.in` and `d_big.in`: `python3 main.py`, which writes `<name>.out` for each.
