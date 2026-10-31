# instance_specific_greedy: scores

Solver: [`solvers/instance_specific_greedy/`](../../solvers/instance_specific_greedy/). Instances B–F of Hash Code 2022 Qualification. Five greedy programs, scored as one solver by taking the best program per instance.

## Best per instance

| Instance | Score | Program | Time (s) |
|---|---:|---|---:|
| b_better_start_small | 1,032,469 | `b.cpp` | 0 |
| c_collaboration | 273,810 | `f.cpp` | 3 |
| d_dense_schedule | 2,608,736 | `d.cpp` | 2 |
| e_exceptional_skills | 1,648,976 | `e.cpp` | 0 |
| f_find_great_mentors | 899,143 | `f.cpp` | 379 |

Sum over B–F: 6,463,134, which is 153.1% of the top team's 4,220,236. The top team's total also includes A, which is worth at most 33.

## Every program

Output files are `<instance>/<program>_deterministic.out`. The bold cell is the best on that instance.

| Program | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|
| `b.cpp` | **1,032,469 (0 s)** | 57,238 (315 s) | 2,178,519 (10 s) | no output at the limit | no output at the limit |
| `c.cpp` | 859,726 (0 s) | 255,918 (2 s) | 591,528 (0 s) | 1,109,173 (15 s) | 466,387 (67 s) |
| `d.cpp` | 1,011,400 (0 s) | 242,898 (3 s) | **2,608,736 (2 s)** | 1,353,350 (7 s) | 542,013 (94 s) |
| `e.cpp` | 894,161 (0 s) | 110,356 (0 s) | 372,996 (0 s) | **1,648,976 (0 s)** | 483,104 (5 s) |
| `f.cpp` | 870,345 (0 s) | **273,810 (3 s)** | 119,838 (0 s) | crash | **899,143 (379 s)** |

The repository's README gives 255,918 on C and 542,013 on F, and says the old F score did not reproduce. In our runs `f.cpp` scored 273,810 on C and 899,143 on F, twice each. `f.cpp` crashes on E with a segmentation fault.

## Run setup

- Built with `g++ -O3 -std=c++20 -w`. Each program reads the input from stdin and writes the submission to stdout.
- Scored with the official judge, `google-hashcode-judge/mentorship_and_teamwork/judge.py`.
- Each run was pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), at most 6 at a time, with a 10-minute wall-clock limit.
- All the programs are deterministic: they use no RNG or a fixed seed. 38 of the 40 first-run outputs that finished inside the limit were repeated and were byte-identical.
- The solver code is unchanged.
