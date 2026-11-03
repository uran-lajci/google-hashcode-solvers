# filter_grow_up_greedy: scores

Solver: [`solvers/filter_grow_up_greedy/`](../../solvers/filter_grow_up_greedy/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 40 | 40 | 0 | 2 |
| medium | 48,922 | 48,922 | 1 | 2 |
| big | 901,839 | 901,839 | 6 | 2 |

The sum of means is 950,801.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** Compile the sources under `src/main/java/` with `javac`, then `java com.msagi.hashcode.pizza.Main <input>`, which prints the submission.
