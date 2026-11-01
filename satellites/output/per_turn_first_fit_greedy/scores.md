# per_turn_first_fit_greedy: scores

Solver: [`solvers/per_turn_first_fit_greedy/`](../../solvers/per_turn_first_fit_greedy/). The four instances of Hash Code 2016 Final.

## Scores

| Instance | Score | Time (s) | Runs |
|---|---:|---:|---:|
| forever_alone | 43,328 | 1 | 1 (screen) |
| weekend | **68,495** | 103 | 10 |
| constellation | **91,222** | 60 | 10 |
| overlap | invalid | 401 | 2 |

The sum without `overlap` is 203,045. The top team's total is 1,017,218. Bold marks a best score across all programs we ran. Every run on an instance gave the same score.

**It fails on `overlap`.** A satellite takes two images in one turn, so the judge rejects the file.

Output files are `<instance>/deterministic.out`, or `run_1.out` where the bytes differ between runs. `forever_alone` was not given the full protocol, because it is far from first there, so it has no published output.

## Run setup

- Scored with the official judge, `google-hashcode-judge/satellites/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as In `Satellite/Satellite/`: `g++ -std=c++14 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve $(ls *.cpp | grep -v mainArbitre)`, then `./solve input output`.
- No code changes.
- It starts threads, and each run was held to one core.
