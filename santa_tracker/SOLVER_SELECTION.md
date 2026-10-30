# Santa Tracker: choosing the two best solvers

Google Hash Code 2022, Final round. Eight public solver repositories were collected, seven could be benchmarked under the same rules, and the collection was cut down to the two that win on at least one instance.

## What we did

1. **Collected.** We searched GitHub and GitLab and found 8 solver repositories for this problem. Duplicate downloads were dropped. Files byte-identical to the official inputs were deleted.
2. **Benchmarked (first round, every usable program).** Instances B–F. A is a toy example and was left out.
   - Deterministic solvers got 1 run each. Randomized ones got 10 runs, with seeds 1, 12, 23, 34, 45, 56, 67, 78, 89, 100.
   - Each run had a 10-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/santa_tracker/judge.py`. A run whose output the judge rejects counts as 0.
   - Code changes were limited to the seed, the input path and the 10-minute stop. `Golovanov399` cannot be run on an instance, so it was marked unusable and not scored.
   - Three Python programs with no visible randomness (`Aryissa`, `E228539M`, `Sh1nc0`) count as deterministic. A second run with another `PYTHONHASHSEED` gave byte-identical outputs, except on `E228539M`'s D, which was not repeated because it runs into the limit.
   - `Nanored4498` needed the 10-minute stop on E, which otherwise writes nothing. The first version of the stop ended F and E too early and could write an invalid `LoadCarrots 0`, so it was replaced and those runs were repeated. Only the final runs are reported.
3. **Selected.** We ranked the solvers on each instance. Only two are first on any instance, and the other six were deleted. Their sources are linked in [README.md](README.md).
4. **Renamed and re-ran.** The two kept solvers now live in [solvers/](solvers/). Each is named after its method, and its README starts with a header giving the source URL and an overview of the method. Both were run again under the same protocol. The outputs and scores are in [output/](output/).

## Chosen and ignored

First-round results, best run per instance (official judge). Bold marks the highest score on each instance. "Placement" puts the sum over B–F among the 39 finalist teams of 2022, whose totals also include A (worth at most 18 points).

| Collected solver | Decision | B | C | D | E | F | Sum B–F | Placement |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| `Optimizational-Problems-Solutions_indjev99` | **chosen** | 89,815 | 1,664,854 | 0 | **1,050,706** | **1,352,019** | 4,157,394 | 3 |
| `HashCode2022_Nanored4498` | **chosen** | **122,311** | **1,692,098** | **621,478** | 229,363 | 967,522 | 3,632,772 | 6 |
| `polyhash_google_chall_Aryissa` | ignored | 8,000 | 258,551 | 101,406 | 490,542 | 614,427 | 1,472,926 | 23 |
| `polyhash2022_E228539M` | ignored | 0 | 422,419 | 0 | 345,339 | 472,572 | 1,240,330 | 28 |
| `polyhash2022_Sh1nc0` | ignored | 0 | 150,637 | 168,845 | 63,303 | 314,131 | 696,916 | 34 |
| `ProjectStudent-Googlehash_AdrienLibert` | ignored | invalid (0/10) | invalid (0/10) | invalid (0/10) | invalid (0/10) | invalid (0/10) | 0 | — |
| `Hashcode-2022-Santa-Tracker_AndrijaRiki` | ignored | invalid (0/10) | invalid (0/10) | invalid (0/10) | invalid (0/10) | invalid (0/10) | 0 | — |
| `hashcode-2022_Golovanov399` | ignored | — | — | — | — | — | not scored | — |

**Chosen:**

- `indjev99`, as [steering_greedy_carrot_grid_search](solvers/steering_greedy_carrot_grid_search/): the best scores on E and F and the highest sum. It is also fast, at most 27 s per instance.
- `Nanored4498`, as [bfs_motion_table_greedy_trips](solvers/bfs_motion_table_greedy_trips/): the best scores on B, C and D.

**Ignored:**

- `Aryissa`: the best of four line and single-gift strategies. Valid on every instance, but first on none.
- `E228539M`: diagonal sweeps. It delivers nothing on B and D, as its README warns. On D it was still running at the limit; the file it had written by then is valid and delivers no gift. On the other instances it ends with its own `you have no time left` exception, and the file written up to that point is the submission.
- `Sh1nc0`: DBSCAN clusters or map tiles. The judge gives exactly the scores in its README.
- `AdrienLibert`: every output is rejected, because it writes negative accelerations such as `AccLeft -4` and the statement requires 0 ≤ a. As an unofficial check outside the protocol, we flipped those lines to the opposite direction: all 50 outputs then pass, with best scores B 85,490, C 416,522, D 500,805, E 326,425 and F 470,073 (1,799,315). It would still be first on no instance, so this rejection does not change the choice.
- `AndrijaRiki`: every output is rejected, because the file starts with a `Highest score:` line. As a second unofficial check, we stripped that header and recounted the actions, and the judge still rejects the plan: `"LoadCarrots " + santa.carrots` adds the number to a string pointer, which writes corrupt lines. The program also writes `AccDown` for a move to the right.
- `Golovanov399`: `game.py` is an interactive pygame version of the problem, flown by hand with the arrow keys. It has no algorithm that could be run on an instance.

| Solver | Upstream | Method |
|---|---|---|
| [steering_greedy_carrot_grid_search](solvers/steering_greedy_carrot_grid_search/) | indjev99/Optimizational-Problems-Solutions, `santa.cpp` (C++) | Simulates second by second, steering towards the gift with the best score per distance. The whole simulation is repeated over a grid of gift capacities and carrot loads, and the best plan is kept. |
| [bfs_motion_table_greedy_trips](solvers/bfs_motion_table_greedy_trips/) | Nanored4498/HashCode2022, `2022/Final/` (C++) | One program per instance. A BFS over position and velocity gives the fastest flight along each axis, and trips are built greedily by score per second, delivering what lies along the path. |

## Best scores (B–F, re-run from `solvers/`, official judge)

Both solvers are deterministic, so each has one run per instance. Bold marks the highest score on each instance.

| Solver | B | C | D | E | F | Sum |
|---|---:|---:|---:|---:|---:|---:|
| [steering_greedy_carrot_grid_search](output/steering_greedy_carrot_grid_search/scores.md) | 89,815 | 1,664,854 | 0 | **1,050,706** | **1,352,019** | 4,157,394 |
| [bfs_motion_table_greedy_trips](output/bfs_motion_table_greedy_trips/scores.md) | **122,311** | **1,692,098** | **621,478** | 229,363 | 870,893 | 3,536,143 |

Taking the best output for each instance gives 4,838,612 over B–F, which would place 3rd of the 39 finalist teams. The best team totals are 5,396,369 and 4,970,702.

- Nine of the ten outputs are byte-identical to the first round, so moving the solvers into `solvers/` changed nothing.
- The tenth is F of bfs_motion_table_greedy_trips, which depends on the machine's speed because its stop is a wall-clock limit. An unpatched run finished in 576 s and scored 1,061,182. The two runs with the stop reached game time 520 (967,522) and 407 (870,893) of 600. All three are below steering_greedy_carrot_grid_search on F, so the choice does not depend on this.
- Weak spots:
  - bfs_motion_table_greedy_trips scores only 229,363 on E, stopped at game time 158 of 1,200. Its README reports 1,109,883 without a 10-minute limit, and that score would be first on E. Its source also has OpenMP pragmas, which have no effect here because the benchmark is built without `-fopenmp` and runs on one core.
  - steering_greedy_carrot_grid_search scores 0 on D, which has range 0, because its steering never places the sleigh exactly on a gift's cell.

Per-instance tables and timings are in `output/<solver>/scores.md`.

## How we ran them

Both need the official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) (`archive/2022/final/hashcode_2022_final_round.in/`). Each benchmark run was wrapped as `taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/santa_tracker/judge.py -i <input>.in.txt -o <output>.out
```

| Solver | Build and run | Changes for the benchmark (made to a copy; `solvers/` is untouched) |
|---|---|---|
| steering_greedy_carrot_grid_search | `g++ -O2 -std=c++17 -o santa santa.cpp`<br>`cp b_better_hurry.in.txt b.txt && echo 1 \| ./santa`, which writes `sol_b.txt` | None. |
| bfs_motion_table_greedy_trips | `g++ -O2 -std=c++17 -o b b.cpp`<br>`./b < b_better_hurry.in.txt > b.out` | `c.cpp`, `e.cpp` and `f.cpp` got a 590 s stop in the main loop and in the target search, after which they write the plan so far. `b.cpp` and `d.cpp` are unchanged. |

Instances C–F use the same commands with the letter or the file name changed. The full setup notes for each solver are in the *Run setup* section of its `scores.md`.
