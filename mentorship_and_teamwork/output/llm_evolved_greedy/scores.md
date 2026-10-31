# llm_evolved_greedy: scores

Solver: [`solvers/llm_evolved_greedy/`](../../solvers/llm_evolved_greedy/). Instances B–F of Hash Code 2022 Qualification. One program per instance, each evolved for that instance.

## Best per instance

| Instance | Score | Program | Time (s) |
|---|---:|---|---:|
| b_better_start_small | 1,057,446 | `b.cpp` | 10 |
| c_collaboration | 285,714 | `c.cpp` | 2 |
| d_dense_schedule | 2,853,365 | `d.cpp` | 77 |
| e_exceptional_skills | 1,656,494 | `e.cpp` | 448 |
| f_find_great_mentors | 1,381,929 | `f.cpp` | 574 |

Sum over B–F: 7,234,948, which is 171.4% of the top team's 4,220,236. The top team's total also includes A, which is worth at most 33.

## Every program

Output files are `<instance>/<program>_deterministic.out`. The bold cell is the best on that instance.

| Program | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|
| `b.cpp` | **1,057,446 (10 s)** | no output at the limit | no output at the limit | no output at the limit | no output at the limit |
| `c.cpp` | 870,109 (0 s) | **285,714 (2 s)** | 608,260 (0 s) | 1,274,032 (34 s) | 539,585 (145 s) |
| `d.cpp` | 1,011,820 (0 s) | 251,174 (226 s) | **2,853,365 (77 s)** | 1,651,883 (467 s) | no output at the limit |
| `e.cpp` | 942,383 (0 s) | 39,231 (284 s) | 673,268 (33 s) | **1,656,494 (448 s)** | no output at the limit |
| `f.cpp` | 870,345 (0 s) | 227,572 (3 s) | 119,838 (0 s) | crash | **1,381,929 (574 s)** |

`e.cpp` on E and `f.cpp` on F are from a run with only two programs on the machine, which took 448 s and 574 s. With six programs running at once, as in the rest of the table's runs, the same two did not finish within 10 minutes, so these two scores depend on the machine being lightly loaded.
In the six-at-a-time runs the best results on those instances were 1,651,883 on E (`d.cpp`) and 539,585 on F (`c.cpp`). `f.cpp` crashes on E with a segmentation fault.

## Run setup

- Built with `g++ -O3 -std=c++20 -w`. Each program reads the input from stdin and writes the submission to stdout.
- Scored with the official judge, `google-hashcode-judge/mentorship_and_teamwork/judge.py`.
- Each run was pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), at most 6 at a time, with a 10-minute wall-clock limit.
- All the programs are deterministic: they use no RNG or a fixed seed. 38 of the 40 first-run outputs that finished inside the limit were repeated and were byte-identical.
- The solver code is unchanged.
