# Loon

Google Hash Code 2015, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2015/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2015/final).

## Why only one solver

One solver is kept out of 23 repositories. A solver is kept if it is first on the instance, or if its mean score is within 5% of the best score in the competition (at least 665,868, 95% of 700,913). All usable programs got a screen with one seed and a 5-minute limit, and a program with no valid output got a 10-minute run. Only the kept program came within 20% of the best, so it alone got 10 runs at a 10-minute limit. The full account is in [SOLVER_SELECTION.md](SOLVER_SELECTION.md).

The kept solver lives in [`solvers/`](solvers/) under a method name, with its outputs in [`output/`](output/). Its 683,482 depends on changes of ours: as shipped, the program crashes, and with that fixed its driver plans only 6 balloons and scores 140,494.

## Collected solvers

1 solver: 1 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/per_balloon_dp_hill_climbing`](solvers/per_balloon_dp_hill_climbing/) | C++ | Our runs: 683,482 best, mean 682,207.0, with our driver |

### [`solvers/per_balloon_dp_hill_climbing/`](solvers/per_balloon_dp_hill_climbing/)

- **Source:** https://github.com/yoann-dufresne/loon
- **Snapshot:** GitHub clone at commit `ebf40c7` (2017-01-05); `.git` removed on import.
- **Language:** C++
- **Approach:** Dynamic programming for one balloon at a time over the targets the others leave uncovered, then hill climbing that plans two random balloons again.
- **Run:** `make`, then `mkdir -p results` and `./loon < input`. It runs until stopped and keeps its best plan in `results/best.txt`.
- **Benchmark:** 683,482 best, mean 682,207.0, first. We wrote the driver, fixed an array size and added an include ([scores](output/per_balloon_dp_hill_climbing/scores.md)).
- **Removed on import:** 1 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

## Removed after benchmarking

These 22 repositories were screened or examined on 2026-11-01 and then deleted from the collection (see *Why only one solver* above).

- `HashCode2015-FinalRound_nicolas-legroux` (https://github.com/nicolas-legroux/HashCode2015-FinalRound): `DivisionSolver` scored 326,583 in 490 seconds. The commented-out `DijkstraSolver` and `Solver` crash when enabled
- `HashCode2015-finalround_Dewep` (https://github.com/Dewep/HashCode2015-finalround): `main.py` scored 10,784. `main_paths.py` crashes
- `HashCode2017Warmup_stoman` (https://github.com/stoman/HashCode2017Warmup): mode `channel` scored 263,664 and `naive` 59,084. Mode `emi` gives invalid output
- `Hashcode2015_evilz-agent` (https://github.com/evilz-agent/Hashcode2015): not run, because it is an old .NET Framework project. Reading the code, it launches every balloon once and leaves it there, and that output scores 1,249
- `Hashcode2015_valentinsulzer` (https://github.com/valentinsulzer/Hashcode2015): `optimal_path.py` scored 456,131 in 587 seconds, at 6 GB (it stops at our 3.5 GB limit). `greedy_solution.py` and `random_solution.py` give invalid output
- `LoonBalloons_Flag-Systemes` (https://github.com/Flag-Systemes/LoonBalloons): not a solver: `Main` builds the grid and computes the coverage of one cell, and writes nothing
- `Loon_HashCode_2015_sofiia-tesliuk` (https://github.com/sofiia-tesliuk/Loon_HashCode_2015): invalid output: a balloon descends to altitude 0. It prints a score of 184,593, which we did not check
- `Loon_demmerichs` (https://github.com/demmerichs/Loon): invalid output: the Java program at the 10-minute limit, and the C++ program before it hit even a 6 GB memory limit. Its stored outputs are also invalid, and were made for a different input
- `Polyhash-project_tristandefay44-collab` (https://github.com/tristandefay44-collab/Polyhash-project): no valid output: five methods wrote nothing in 10 minutes, and `random` crashes
- `Polyhash_daymanka` (https://github.com/daymanka/Polyhash): option 4 scored 52,507, and options 1 to 3 scored less
- `google-hashcode-2015_flashcode` (https://github.com/flashcode/google-hashcode-2015): scored 209,905 in 13 seconds
- `google-hashcode2015-sigmaBoys_maxday` (https://github.com/maxday/google-hashcode2015-sigmaBoys): `sigmaFinal` scored 273,712, with its hardcoded Windows input path changed
- `hashcode-2015-loons_mattias-lundell` (https://github.com/mattias-lundell/hashcode-2015-loons): never writes a submission. With Python 2 it prints a score of 154,448, which we did not check
- `hashcode-2015_marioyc` (https://github.com/marioyc/hashcode-2015): `loon.cpp` is cut off in the middle of `main` and does not compile. The other programs in the repository are for Optimize a Data Center or only print a grid
- `hashcode-2015_phlalx` (https://github.com/phlalx/hashcode-2015): scored 389,032 at the 10-minute limit with 21 of 53 balloons planned, with a writer we added, because the original writes nothing until it finishes
- `hashcode-loon_dd0` (https://github.com/dd0/hashcode-loon): scored 373,847 in 124 seconds, with our changes: it wrote no submission and started from a fixed cell, and we turned moves the rules forbid into stays
- `hashcode16_valenca` (https://github.com/valenca/hashcode16): unfinished: it has a syntax error and no submission writer
- `hashcode2015_nicomev` (https://github.com/nicomev/hashcode2015): scored 165,682 in 4 seconds, with Python 2
- `hashcode2015_zorun` (https://github.com/zorun/hashcode2015): `loon.py` prints a hand-written solution that scores 22,371. `loon_v2.py` fails on current `networkx`
- `polyhash-24_coralietosten` (https://github.com/coralietosten/polyhash-24): `main.py` scored 443,574 in 11 seconds, keeping the best of its strategies. Its stored output scores 391,092
- `polyhash2024_IIXIVII` (https://github.com/IIXIVII/polyhash2024): `ClusteredPath` scored 373,695. `Mathis`, `RSMT` and `RSMTv2` give invalid output, `RSMTv3` wrote nothing in 10 minutes, and `ECM`, `bfs` and `CBBA` hit even a 6 GB memory limit
- `polyhash_GabrielPlayeur` (https://github.com/GabrielPlayeur/polyhash): wrote nothing in 10 minutes. Its README reports 509,000 after 1 hour 43 minutes

## Duplicates removed during import

- `TomDaniaud/Polyhash` (GitHub, `b135878`): an older snapshot of the same team's project. `GabrielPlayeur/polyhash` has every one of its commits plus three newer ones.
- `AlexysGromard/polyhash` (GitHub, `0d14689`): only the course template with the team's names added. `IIXIVII/polyhash2024` is the same team's repo and contains this commit and the full solver.
- `polyhash2024_starter` (GitLab zip from the first import): the unmodified Poly# 2024 starter template (stub parser and solver). The full repos above build on it.
- [TomDaniaud/Polyhash](https://github.com/TomDaniaud/Polyhash) (`b135878`): older snapshot of the same team's repo (TomDaniaud/Polyhash at b135878; every commit is in GabrielPlayeur/polyhash) as `polyhash_GabrielPlayeur`.

## Official inputs removed

1 files in 1 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>solvers/per_balloon_dp_hill_climbing</code> (1 files)</summary>

- `data.in` ← `archive/2015/final/hashcode_2015_final_round.in`

</details>
