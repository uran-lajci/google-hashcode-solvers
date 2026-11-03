# distance_priority_queue_with_improvement: scores

Solver: [`solvers/distance_priority_queue_with_improvement/`](../../solvers/distance_priority_queue_with_improvement/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 38 | 38 | 0 | 2 |
| medium | 49,255 | 49,255 | 1 | 2 |
| big | 905,295 | 905,295 | 13 | 2 |

The sum of means is 954,588.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** `g++ -O2 lontano.cpp`, then `./a.out < <input> > <output>`.
