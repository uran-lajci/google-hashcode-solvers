# Assembling Smartphones

Google Hash Code 2020, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2020/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2020/final).

## Why only three solvers

Only the three competitive solvers are kept. All 12 collected solvers were benchmarked on instances B–F (10-minute limit, 10 seeds for randomized solvers, official judge; protocol and full results in [`experiments/assembling_smartphones/`](../experiments/assembling_smartphones/)). The three kept solvers are the only ones with the best mean score on any instance: `local-search-assembly_rilindmehmeti` on B, `polyhash-2020_slavi010` on C, D and F, `HashCode2022_Nanored4498` (`yoann_old.cpp`) on E. They are also the only ones whose totals would place in the top 8 of the 45 finalist teams. The other nine are listed under *Removed after benchmarking* below.

## Collected solvers

3 solvers: 3 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`polyhash-2020_slavi010`](polyhash-2020_slavi010/) | Python 3 | Over 7 million points in total, according to the README (per-input charts are in `image_readme/Score_*.png`) |
| [`local-search-assembly_rilindmehmeti`](local-search-assembly_rilindmehmeti/) | C++ (`v5.cpp`) + shell scripts for sequential, parallel and daemon runs | Best kept outputs: B 1,069,912, C 1,121,755, D 1,387,580, E 1,105,254, F 1,298,304 (5,982,805 without A) |
| [`HashCode2022_Nanored4498`](HashCode2022_Nanored4498/) | C++ | No scores reported for 2020 (the README only covers 2019, 2021 and 2022) |

### [`polyhash-2020_slavi010/`](polyhash-2020_slavi010/)

- **Source:** https://github.com/slavi010/polyhash-2020
- **Snapshot:** GitHub clone at commit `a11aa69` (history 2020-10-09 → 2021-05-07); `.git` removed on import.
- **Origin:** Student project from the *Poly#* (PolyHash) 2020 course at Polytech Nantes (Université de Nantes). Code and comments are mostly in French.
- **Authors:** Sviatoslav Besnard, Aurélie Boulais, Chama El Majeny, Rémy Borius
- **Language:** Python 3
- **Approach:** Parameterised simulation search: robotic arms are assigned tasks around barycentres and moved step by step with collision handling. Tuning parameters (`MAX_STUCK`, `MAX_DIST_PM`, `ADDITION`, `FACTEUR_CONCENTRATION_BRAS`) can be randomised over many iterations. There is an optional live GUI. Strategy details are on the GitHub wiki.
- **Scores:** Over 7 million points in total, according to the README (per-input charts are in `image_readme/Score_*.png`).
- **Bundled inputs:** `data/input/`: the six official inputs (+ the problem PDF).
- **Run:** `python main.py -m <A–F> [-i N] [-v] [-g]`
- **Removed on import:** 6 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`local-search-assembly_rilindmehmeti/`](local-search-assembly_rilindmehmeti/)

- **Source:** https://github.com/rilindmehmeti/local-search-assembly
- **Snapshot:** GitHub clone at commit `37d23f3` (history 2026-01-15 → 2026-01-15); `.git` removed on import. Upstream `output/` held 448 run results (122 MB). Only the best `.out` (and its `.json` run log, where present) per input was kept.
- **Origin:** Independent project.
- **Authors:** Rilind Mehmeti
- **Language:** C++ (`v5.cpp`) + shell scripts for sequential, parallel and daemon runs
- **Approach:** Parameterised greedy construction (task-efficiency weight, distance penalty, mount-point ownership distance, path-cost threshold, BFS randomness) wrapped in a local search over those parameters. Runs last hours; the scripts launch many seeded runs.
- **Scores:** Best kept outputs: B 1,069,912, C 1,121,755, D 1,387,580, E 1,105,254, F 1,298,304 (5,982,805 without A).
- **Bundled inputs:** `input/`: the six official inputs.
- **Run:** Build with `scripts/build.sh`, then `./v5 -m <A–F> [--local-search --iterations N …]` (see `scripts/README_*.md`)
- **Removed on import:** 6 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`HashCode2022_Nanored4498/`](HashCode2022_Nanored4498/)

- **Source:** https://github.com/Nanored4498/HashCode2022
- **Snapshot:** GitHub clone at commit `339100d` (history 2022-02-25 → 2026-06-03); `.git` removed on import. Only the files for this problem were copied (`2020/`), plus the repo's README (and LICENSE where present); the rest of the repo covers other problems.
- **Origin:** Competition and post-contest solutions by Yoann Coudert--Osmont and teammates ("Quiche LORIAinne" in 2022, "TEAM TEAM" in 2019). MIT licensed.
- **Authors:** Yoann Coudert--Osmont (Nanored4498); commits are all by him
- **Language:** C++
- **Approach:** Randomized greedy robotic-arm planner on the grid (`yoann_old.cpp`, BFS pathfinding), with a verifier (`verifier.cpp`).
- **Removed after benchmarking:** `yoann.cpp`, the later version with priority-queue pathfinding; it scored lower than `yoann_old.cpp` on C, D and E and in total (sum of mean scores over B–F 4.00 M vs 4.53 M).
- **Scores:** No scores reported for 2020 (the README only covers 2019, 2021 and 2022).
- **Bundled inputs:** None bundled.
- **Run:** Compile with `g++ -O2` and run each program on the input (`< input > output`)

## Removed after benchmarking

These nine solvers were benchmarked on 2026-10-19 and then deleted from the collection (see *Why only three solvers* above). Sources are linked; the benchmark records the reason for each.

- `Optimizational-Problems-Solutions_indjev99` (https://github.com/indjev99/Optimizational-Problems-Solutions): not competitive: deterministic greedy, 1.05 M over B–F (sum of mean scores; the kept solvers reach 4.1–4.5 M).
- `polyhash_flo` (https://gitlab.univ-nantes.fr/flo/polyhash): not competitive: 3.31 M over B–F, best on no instance.
- `PolyHash_Neltab` (https://github.com/Neltab/PolyHash): crashes on every instance (`RecursionError` on B, C; `TypeError` in `FindPath` on D, E, F), also under Python 3.8.
- `Hashcode2020FinalRound_avie41` (https://github.com/avie41/Hashcode2020FinalRound): not competitive: 2.24 M over B–F, best on no instance (on B its `robot_percent=0.1` gives 0 arms, an invalid output).
- `hashcode-practice-2020-final_AlexeyZhuravlev` (https://github.com/AlexeyZhuravlev/hashcode-practice-2020-final): not competitive: `lexa.cpp` scored 1.71 M over B–F; `kinan.cpp`, `timur.cpp` and `template.cpp` are empty templates and `dima.cpp` prints the example answer.
- `Assembling_Smartphones_Hyperion2023` (https://github.com/Hyperion2023/Assembling_Smartphones): never writes a submission (it only prints its own unverified score), so it cannot be scored.
- `hashcode2021_FilipePintoReis` (https://github.com/FilipePintoReis/hashcode2021): `solve()` is empty; the program only prints input statistics.
- `hashcode_2020_Michael-Kuria` (https://github.com/Michael-Kuria/hashcode_2020): unfinished: `solve()` loops on `while(l > 0)` without changing `l` and writes nothing.
- `hashcode2020_ivan-mitb` (https://github.com/ivan-mitb/hashcode2020): unfinished: calls an undefined `play()` and writes nothing.

## Duplicates removed during import

- `polyhash-master (1)` (GitLab zip): a byte-identical second download of `flo/polyhash` (`polyhash_flo` itself was later removed after benchmarking).
- `slavi010/polyhash-2020` (GitHub, third import): a second clone of the same commit (`a11aa69`) as `polyhash-2020_slavi010`.

## Official inputs removed

12 files in 2 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>local-search-assembly_rilindmehmeti</code> (6 files)</summary>

- `input/a_example.txt` ← `archive/2020/final/hashcode_2020_final_round.in/a_example.txt`
- `input/b_single_arm.txt` ← `archive/2020/final/hashcode_2020_final_round.in/b_single_arm.txt`
- `input/c_few_arms.txt` ← `archive/2020/final/hashcode_2020_final_round.in/c_few_arms.txt`
- `input/d_tight_schedule.txt` ← `archive/2020/final/hashcode_2020_final_round.in/d_tight_schedule.txt`
- `input/e_dense_workspace.txt` ← `archive/2020/final/hashcode_2020_final_round.in/e_dense_workspace.txt`
- `input/f_decentralized.txt` ← `archive/2020/final/hashcode_2020_final_round.in/f_decentralized.txt`

</details>

<details><summary><code>polyhash-2020_slavi010</code> (6 files)</summary>

- `data/input/a_example.txt` ← `archive/2020/final/hashcode_2020_final_round.in/a_example.txt`
- `data/input/b_single_arm.txt` ← `archive/2020/final/hashcode_2020_final_round.in/b_single_arm.txt`
- `data/input/c_few_arms.txt` ← `archive/2020/final/hashcode_2020_final_round.in/c_few_arms.txt`
- `data/input/d_tight_schedule.txt` ← `archive/2020/final/hashcode_2020_final_round.in/d_tight_schedule.txt`
- `data/input/e_dense_workspace.txt` ← `archive/2020/final/hashcode_2020_final_round.in/e_dense_workspace.txt`
- `data/input/f_decentralized.txt` ← `archive/2020/final/hashcode_2020_final_round.in/f_decentralized.txt`

</details>
