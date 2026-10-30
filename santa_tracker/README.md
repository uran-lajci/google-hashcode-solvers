# Santa Tracker

Google Hash Code 2022, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2022/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2022/final).

## Why only two solvers

Only two solvers are kept. All eight collected programs were examined, and the seven that can run were benchmarked on instances B–F (10-minute limit, 10 runs for randomized solvers, official judge). Only these two are first on any instance. The rule, every solver's scores and the protocol are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers now live in [`solvers/`](solvers/) under method names, with their benchmark outputs in [`output/`](output/). Kept: `HashCode2022_Nanored4498`, first on B, C and D (3.54 M over B–F), and `Optimizational-Problems-Solutions_indjev99`, first on E and F (4.16 M). The other six are listed under *Removed after benchmarking* below.

## Collected solvers

2 solvers: 2 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/bfs_motion_table_greedy_trips`](solvers/bfs_motion_table_greedy_trips/) | C++ | After contest: A 16, B 122,311, C 1,692,098, D 621,478, E 1,109,883, F 1,061,182 (4,606,968; would rank 3rd) |
| [`solvers/steering_greedy_carrot_grid_search`](solvers/steering_greedy_carrot_grid_search/) | C++ (single file) | No scores reported upstream |

### [`solvers/bfs_motion_table_greedy_trips/`](solvers/bfs_motion_table_greedy_trips/)

- **Source:** https://github.com/Nanored4498/HashCode2022
- **Snapshot:** GitHub clone at commit `339100d` (history 2022-02-25 → 2026-06-03); `.git` removed on import. Only the files for this problem were copied (`2022/Final/`), plus the repo's README and LICENSE; the rest of the repo covers other problems.
- **Origin:** Competition and post-contest solutions by Yoann Coudert--Osmont and teammates ("Quiche LORIAinne" in 2022, "TEAM TEAM" in 2019). MIT licensed.
- **Authors:** Yoann Coudert--Osmont (Nanored4498); commits are all by him
- **Language:** C++
- **Approach:** Separate C++ solvers for inputs B–F, written during the 2022 final and improved afterwards.
- **Scores:** After contest: A 16, B 122,311, C 1,692,098, D 621,478, E 1,109,883, F 1,061,182 (4,606,968; would rank 3rd). At contest end: 1,913,445 (18th).
- **Bundled inputs:** None bundled.
- **Run:** Compile with `g++ -O2` and run each program on the input (`< input > output`)
- **Benchmark:** B 122,311, C 1,692,098, D 621,478, E 229,363, F 870,893 (3,536,143; [scores](output/bfs_motion_table_greedy_trips/scores.md)). E and F do not finish within the 10-minute limit on one core, so those plans are partial.

### [`solvers/steering_greedy_carrot_grid_search/`](solvers/steering_greedy_carrot_grid_search/)

- **Source:** https://github.com/indjev99/Optimizational-Problems-Solutions
- **Snapshot:** GitHub clone at commit `a7af36f` (history 2019-03-02 → 2026-03-29); `.git` removed on import. `santa.cpp` was added on 2022-05-02. Only the file for this problem was copied (`santa.cpp`); the rest of the repo covers other problems, and it has no licence file.
- **Origin:** Personal collection of solutions to optimisation contests (CodeIT, Bubble Cup, Reply, Hash Code, …).
- **Authors:** indjev99
- **Language:** C++ (single file)
- **Approach:** A steering greedy: each second the sleigh corrects its velocity towards the gift with the best score per distance. The whole simulation is repeated over a grid of gift capacities and carrot loads, and the best plan is kept.
- **Scores:** No scores reported upstream.
- **Bundled inputs:** None bundled.
- **Run:** Compile with `g++ -O2`; put the instance in the working directory as `a.txt` to `f.txt`, give its number on stdin (0 = A … 5 = F), and it writes `sol_<letter>.txt`
- **Benchmark:** B 89,815, C 1,664,854, D 0, E 1,050,706, F 1,352,019 (4,157,394; [scores](output/steering_greedy_carrot_grid_search/scores.md)).

## Removed after benchmarking

These six solvers were benchmarked (or, if they cannot be run, examined) on 2026-10-30 and then deleted from the collection (see *Why only two solvers* above). Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has every score.

- `polyhash_google_chall_Aryissa` (https://github.com/Aryissa/polyhash_google_chall): not selected: picks the best of four line and single-gift strategies, 1.47 M over B–F (23rd of the 39 finalist teams), first on no instance.
- `polyhash2022_E228539M` (https://gitlab.univ-nantes.fr/E228539M/polyhash2022): not selected: diagonal sweeps, 1.24 M over B–F (28th), first on no instance. It delivers nothing on B and D, as its README warns, and does not finish D within the limit.
- `polyhash2022_Sh1nc0` (https://github.com/Sh1nc0/polyhash2022): not selected: DBSCAN clusters or map tiles, 0.70 M over B–F (34th), first on no instance. The judge confirms the scores in its README.
- `ProjectStudent-Googlehash_AdrienLibert` (https://github.com/AdrienLibert/ProjectStudent-Googlehash): every output is invalid: it writes negative accelerations such as `AccLeft -4`, while the statement requires 0 ≤ a. With the signs repaired it would total 1.80 M and still be first on no instance.
- `Hashcode-2022-Santa-Tracker_AndrijaRiki` (https://github.com/AndrijaRiki/Hashcode-2022-Santa-Tracker): every output is invalid: the file starts with a `Highest score:` line, and the plan itself contains corrupt lines because `"LoadCarrots " + santa.carrots` adds the number to a string pointer.
- `hashcode-2022_Golovanov399` (https://github.com/Golovanov399/hashcode-2022): not a solver: an interactive pygame version of the problem, flown by hand with the arrow keys, so it cannot be run on an instance.

## Duplicates removed during import

- `polyhash2022-main (1)` (GitLab zip): the unmodified Poly# 2022 starter template.
