# Assembling Smartphones: choosing the three best solvers

Google Hash Code 2020, Final round. Twelve public solvers were collected, benchmarked under the same rules, and cut down to the three that win on at least one instance.

## What we did

1. **Collected.** We searched GitHub and GitLab and found 12 solver repositories for this problem. Duplicate downloads were dropped. Files byte-identical to the official inputs were deleted (they are listed in [README.md](README.md)).
2. **Benchmarked (first round, all 12).** Instances B–F. A is a toy example and was left out.
   - Deterministic solvers got 1 run each. Randomized ones got 10 runs, with seeds 1, 12, 23, 34, 45, 56, 67, 78, 89, 100.
   - Each run had a 10-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/assembling_smartphones/judge.py`.
   - Code changes were limited to the seed, the input path and the 10-minute stop. Programs that wrote nothing or were stubs were marked unusable, not scored as 0.
3. **Selected.** We ranked the solvers by mean score on each instance. Only three are first on any instance, and only these three have totals that would place in the top 8 of the 45 finalist teams. The other nine were deleted:
   - four scored too low: `flo` 3.31 M over B–F, `avie41` 2.24 M, `AlexeyZhuravlev` 1.71 M, `indjev99` 1.05 M;
   - one crashes on every instance (`Neltab`);
   - four never write a submission (`Hyperion2023`, `FilipePintoReis`, `Michael-Kuria`, `ivan-mitb`). Their `solve()` is empty or unfinished, or they only print a score.

   Within Nanored4498's repo we kept `yoann_old.cpp` and dropped `yoann.cpp`, the later version, which totals 4.00 M against 4.53 M.
4. **Renamed and re-ran.** The three solvers that were kept now live in [solvers/](solvers/). Each is named after its method and starts with a header that gives the source URL and an overview of the method. All three were run again under the same protocol. The outputs and the per-seed scores are in [output/](output/).

| Solver | Upstream | Method |
|---|---|---|
| [greedy_bfs_arm_scheduler](solvers/greedy_bfs_arm_scheduler.cpp) | Nanored4498/HashCode2022, `yoann_old.cpp` (C++) | Prunes tasks by score per length, then greedily gives each arm the task with the best score per step. Moves are planned with BFS around the other arms. |
| [local_search_greedy_dijkstra](solvers/local_search_greedy_dijkstra.cpp) | rilindmehmeti/local-search-assembly (C++) | A greedy with five tunable parameters, wrapped in a local search over those parameters (annealing-style acceptance). Moves are planned with a time-ordered Dijkstra search. |
| [random_restart_greedy_astar](solvers/random_restart_greedy_astar/) | slavi010/polyhash-2020 (Python) | Simulates the arms step by step. Tasks are assigned around clusters of mount points, collisions are handled, and parameters are randomized on each restart. |

## Best scores (B–F, best of 10 seeds, official judge)

| Solver | B | C | D | E | F | Sum of bests | Sum of means |
|---|---:|---:|---:|---:|---:|---:|---:|
| greedy_bfs_arm_scheduler | **1,069,979** | 1,191,681 | 1,344,440 | 1,096,473 | 95,586 | 4,798,159 | 4,520,631 |
| local_search_greedy_dijkstra | 1,069,810 | 1,204,084 | **1,385,368** | 719,321 | 118,295 | 4,496,878 | 4,130,326 |
| random_restart_greedy_astar | 353,434 | **1,446,935** | 1,344,679 | **1,105,254** | **1,767,691** | 6,017,993 | 5,645,647 |

Taking the best output for each instance gives 6,775,227 over B–F. Weak spots: the two C++ solvers hit the 10-minute limit on F, and local_search_greedy_dijkstra also hits it on E, so those scores come from partial plans. random_restart_greedy_astar is weak on B. Per-seed tables and timings are in `output/<solver>/scores.md`.

## How we ran them

All three need the official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) (`archive/2020/final/hashcode_2020_final_round.in/`). Each benchmark run was wrapped as `taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/assembling_smartphones/judge.py -i <input>.txt -o <output>.out
```

| Solver | Build and run | Changes for the benchmark (made to a copy; `solvers/` is untouched) |
|---|---|---|
| greedy_bfs_arm_scheduler | `g++ -O2 -o gbas greedy_bfs_arm_scheduler.cpp`<br>`./gbas < b_single_arm.txt > b.out` | `mt19937 mt(420)` → `mt(HC_SEED)`, one binary per seed (`-DHC_SEED=<s>`); stops before 590 s and writes the plan it has so far |
| local_search_greedy_dijkstra | `g++ -O2 -std=c++17 -o lsgd local_search_greedy_dijkstra.cpp`<br>`./lsgd -m B --local-search --seed <s>` (default 50 iterations) | Needs `input/<official name>.txt` and an existing `output/` folder in the working directory. Added a 590 s deadline that stops the greedy and the search, then writes the best plan |
| random_restart_greedy_astar | `python main.py -m B` (Python 3.12 + Pillow, `PYTHONHASHSEED=0`) | Inputs go in `data/input/`. Added `random.seed(int(os.environ["HC_SEED"]))` after `import random` in `main.py` (upstream never seeds) |

Instances C–F use the same commands with the letter or the file name changed. The full setup notes for each solver are in the *Run setup* section of its `scores.md`.
