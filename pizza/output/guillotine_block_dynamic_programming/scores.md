# guillotine_block_dynamic_programming: scores

Solver: [`solvers/guillotine_block_dynamic_programming/`](../../solvers/guillotine_block_dynamic_programming/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 38 | 38 | 0 | 2 |
| medium | 49,998 | **49,998** | 53 | 2 |
| big | no output in 10 minutes (2 runs) | | 600 | 2 |

The sum of means is 50,036.

It is kept because it is first on `medium`. Its sum leaves out `big`, where it wrote nothing in 10 minutes.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** `g++ -O2 progdyn_bloc.cpp`, then `./a.out < <input> > <output>`.
