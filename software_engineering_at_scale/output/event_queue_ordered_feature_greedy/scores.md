# event_queue_ordered_feature_greedy: scores

Solver: [`solvers/event_queue_ordered_feature_greedy/`](../../solvers/event_queue_ordered_feature_greedy/). Instances B–F of Hash Code 2021 Final, one run each (the solver is deterministic). Every output was scored with `google-hashcode-judge/software_engineering_at_scale/judge.py`. Outputs: `<instance>/deterministic.out`.

## Scores

| Instance | Score | Time (s) |
|---|---:|---:|
| b_breadth_of_choice | 11,591,350 | 0.1 |
| c_constrained_optimisation | 23,600,735 | 0.8 |
| d_distinction | 73,226,608 | 0.1 |
| e_expectation_maximisation | 35,650,621 | 1.9 |
| f_five_thousand | 111,540,577 | 0.0 |

Sum over B–F: 255,609,891.

## Run setup

- Built with `g++ -O2 -std=c++17 -I. -include stdexcept -include algorithm` from the sources of the Bazel target `//binary:run_solution` (Bazel was not used). GCC 13 needs the two `-include` flags because two files use `std::runtime_error` and `std::sort` without including their headers; the source is unchanged. Command: `./run_solution < <input> > <instance>/deterministic.out`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- No code changes. The program has no parameters and no randomness.
- The outputs are byte-identical to the first benchmark round.
