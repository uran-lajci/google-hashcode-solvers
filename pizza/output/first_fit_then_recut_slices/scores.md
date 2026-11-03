# first_fit_then_recut_slices: scores

Solver: [`solvers/first_fit_then_recut_slices/`](../../solvers/first_fit_then_recut_slices/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 40 | 40 | 0 | 2 |
| medium | 49,194 | 49,194 | 0 | 2 |
| big | 905,436 | 905,436 | 10 | 2 |

The sum of means is 954,670.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** Python 2. In `practice/`, with the instance copied to `medium.in`: `pypy practice.py`, which writes `medium.txt`.
