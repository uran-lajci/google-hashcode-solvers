# Compiling Google

Google Hash Code 2019, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2019/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2019/final).

## Why only three solvers

Only three solvers are kept, from two of the 12 collected repositories. A first screen ran every usable program on instances B–F with one seed and a 5-minute limit. The programs that could still be competitive then went through the full protocol (10-minute limit, 10 runs for randomized solvers, official judge). The rule, every program's scores and the protocol are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers now live in [`solvers/`](solvers/) under method names, with their benchmark outputs in [`output/`](output/). Kept: `HashCode2022_Nanored4498`, first on B and tied first on E and F (6.08 M over B–F), and two programs of `Hashcode-final-2019_LarsAstrom`: `solve_c_la`, first on C (1.95 M), and `mm_sort_shuffle`, first on D (1.28 M). The other ten repositories are listed under *Removed after benchmarking* below.

## Collected solvers

3 solvers: 3 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/instance_tailored_target_scheduler`](solvers/instance_tailored_target_scheduler/) | C++ | A 60, B 1,530,065, C 1,934,841, D 1,250,354, E 524,288, F 840,971 (6,080,579; would have ranked 7th) |
| [`solvers/subset_sum_partition_scheduler`](solvers/subset_sum_partition_scheduler/) | Python (pypy recommended) | No scores recorded in the repo |
| [`solvers/shuffled_deadline_order_greedy`](solvers/shuffled_deadline_order_greedy/) | Python (pypy recommended) | No scores recorded in the repo |

### [`solvers/instance_tailored_target_scheduler/`](solvers/instance_tailored_target_scheduler/)

- **Source:** https://github.com/Nanored4498/HashCode2022
- **Snapshot:** GitHub clone at commit `339100d` (history 2022-02-25 → 2026-06-03); `.git` removed on import. Only the files for this problem were copied (`2019/acd.cpp`, `b.cpp`, `e.cpp`, `f.cpp`, `verifier.cpp`), plus the repo's README and LICENSE; the rest of the repo covers other problems.
- **Origin:** Competition and post-contest solutions by Yoann Coudert--Osmont and teammates ("Quiche LORIAinne" in 2022, "TEAM TEAM" in 2019). MIT licensed.
- **Authors:** Yoann Coudert--Osmont (Nanored4498); commits are all by him
- **Language:** C++
- **Approach:** Separate solvers per input group (`acd`, `b`, `e`, `f`) plus a verifier. Written for training after the contest.
- **Scores:** A 60, B 1,530,065, C 1,934,841, D 1,250,354, E 524,288, F 840,971 (6,080,579; would have ranked 7th).
- **Bundled inputs:** None bundled.
- **Run:** Compile with `g++ -O2` and run each program on the input (`< input > output`)
- **Benchmark:** B 1,530,065, C 1,934,841, D 1,250,354, E 524,288, F 840,971 (6,080,519; [scores](output/instance_tailored_target_scheduler/scores.md)).

### [`solvers/subset_sum_partition_scheduler/`](solvers/subset_sum_partition_scheduler/)

- **Source:** https://github.com/LarsAstrom/Hashcode-final-2019
- **Snapshot:** GitHub clone at commit `6884db2` (history 2019-04-23 → 2019-04-27); `.git` removed on import.
- **Origin:** Written on contest day (2019-04-27) by a team at the Hash Code 2019 final, using the `exoji2e/hashcode-template` Python harness.
- **Authors:** Lars Åström, Björn, Måns Magnusson, Jonatan Nilsson (from git history)
- **Language:** Python (pypy recommended)
- **Approach:** Written for instance C. A subset-sum dynamic program splits the dependencies of the target with 100 of them over the servers, then the other targets are scheduled greedily in the earliest free slots.
- **Scores:** No scores recorded in the repo.
- **Bundled inputs:** None bundled. Only `solve_c_la.py` and the team's harness were copied; the official instances go in `in/`.
- **Run:** `pypy main.py c_urgent -s <seed> --solve module=solve_c_la` → `submission/c_urgent.ans`
- **Benchmark:** C: best 1,950,379, mean 1,943,920 over 10 seeds ([scores](output/subset_sum_partition_scheduler/scores.md)).

### [`solvers/shuffled_deadline_order_greedy/`](solvers/shuffled_deadline_order_greedy/)

- **Source:** https://github.com/LarsAstrom/Hashcode-final-2019
- **Snapshot:** GitHub clone at commit `6884db2` (history 2019-04-23 → 2019-04-27); `.git` removed on import.
- **Origin:** Written on contest day (2019-04-27) by a team at the Hash Code 2019 final, using the `exoji2e/hashcode-template` Python harness.
- **Authors:** Lars Åström, Björn, Måns Magnusson, Jonatan Nilsson (from git history)
- **Language:** Python (pypy recommended)
- **Approach:** Targets are sorted by deadline, latest first, and the first 17 are shuffled. Each target's files then go to the earliest free slots, and a target that would miss its deadline is undone.
- **Scores:** No scores recorded in the repo.
- **Bundled inputs:** None bundled. Only `mm_sort_shuffle.py` and the team's harness were copied; the official instances go in `in/`.
- **Run:** `pypy main.py <instance> -s <seed> --solve module=mm_sort_shuffle` → `submission/<instance>.ans`
- **Benchmark:** best of 10 seeds: B 1,482,186, C 1,456,275, D 1,277,337, E 1; F is invalid on every seed ([scores](output/shuffled_deadline_order_greedy/scores.md)).

## Removed after benchmarking

These ten repositories were benchmarked (or, if they cannot be run, examined) on 2026-10-30 and then deleted from the collection (see *Why only three solvers* above). Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has every score. The last two entries were never collected: they were examined at import and hold no solver.

- `hashcode-2019-final-training_AlexeyZhuravlev` (https://github.com/AlexeyZhuravlev/hashcode-2019-final-training): not selected: `timur.cpp` scored 2.75 M over B–F, and `lexa.cpp` and `lexa2.cpp` scored 2.11 M. The last two reach the top F score, 840,971, but only tie it. `miron.cpp`, `kinan.cpp` and `template.cpp` are empty templates.
- `HashCode_arriopolis` (https://github.com/arriopolis/HashCode): not selected: its best general program scored 2.91 M over B–F. `e_solution.py` and `Solver_f.py` reach the top scores on E and F, but only tie them.
- `hashcode-2019_nilswende` (https://github.com/nilswende/hashcode-2019): not selected: linear compilation chains, 1.30 M over B–F, and invalid on D.
- `g_hashcodes_kobr4` (https://github.com/kobr4/g_hashcodes): not selected: at most 1.26 M over B–F across its three modes.
- `hashCode2019UI_mrDreaml` (https://github.com/mrDreaml/hashCode2019UI): not selected: a genetic algorithm in a browser app, 0.92 M over B–F with a native build.
- `Google-HashCode-2019_Mogstene` (https://github.com/Mogstene/Google-HashCode-2019): not selected: 0.69 M over B–F.
- `hashcode2019-final-round_danvixent` (https://github.com/danvixent/hashcode2019-final-round): every output is invalid: files are listed before the dependencies they need.
- `compile_scheduler_lekemula` (https://github.com/lekemula/compile_scheduler): never writes a submission: it only prints its own score.
- `hashcode2021_gnitsua` (https://github.com/gnitsua/hashcode2021): cannot run: `practice/Solver.py` does not parse.
- `HashCode2019_ishaanzaveri` (https://github.com/ishaanzaveri/HashCode2019): solves Photo Slideshow (2019 qualification), not this problem.
- `jaimuepe/google-hashcode-2019-final` (Java, `77587f1`): only reads the input into objects; there is no solver and no output.
- `erclu/google-hashcode-2019-extended-final-round` (Python, `dcb29cb`): builds the dependency graph and prints the targets, but never produces a submission.
