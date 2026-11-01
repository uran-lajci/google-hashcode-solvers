# Loon: choosing the best solvers

Google Hash Code 2015, Final round, which has a single instance. 23 repositories were in the folder. 1 solver was kept and 22 were removed. None needs a license.

## Kept

| Solver | Repository | Best | Mean | Worst | Placement | Why |
|---|---|---:|---:|---:|---:|---|
| [per_balloon_dp_hill_climbing](solvers/per_balloon_dp_hill_climbing/) | `yoann-dufresne` | **683,482** | 682,207.0 | 680,904 | 6 | First on the instance, and within 5% |

The top team has 700,913, so the 5% line is 665,868 (95% of 700,913 is 665,867.35). Placement is where the best run would rank among the 65 teams. No other program comes close: the next best scored 456,131.

**This score depends on changes of ours.** As shipped, the program crashes, because its arrays are one altitude too small. With that fixed, its driver plans only up to 6 balloons and scores 140,494. We wrote a driver that plans all 53 balloons and then repeats the program's hill climbing step, and the planning and hill climbing code is otherwise the author's. A commented-out line in the original loads a file named `results/2loons_699764.txt`, so the author evidently ran it in several stages and reached 699,764. That file is not in the repository, so we could not check it.

## What we did

1. **Collected.** 23 repositories, after the earlier non-solver prunes.
2. **Screened.** One run with a 5-minute limit, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/loon/judge.py`. A run whose output the judge rejects counts as 0.
3. **10-minute runs.** A program with no valid output at 5 minutes got a 10-minute run, and programs stopped by our 3.5 GB memory limit got a 10-minute run at 6 GB.
4. **Full protocol.** A program advanced if it was within 20% of the best (at least 546,786). Only the kept program did, so it got 10 runs at a 10-minute limit.
5. **Selected.** A solver is kept if it is first on the instance by its best run, or if its mean is at least 665,868. The others were deleted.
6. **Renamed.** The kept solver now lives in [solvers/](solvers/), named after its method, and its README starts with a header giving the source and the method. The outputs in [output/](output/) come from the runs above and were not repeated after the move.

## Removed repositories

The result is the best valid score we got, on one run. The 10-minute limit decides many of these.

| Repository | Result | Why it is out |
|---|---:|---|
| `Hashcode2015_valentinsulzer` | 456,131 | `optimal_path.py` scored 456,131 in 587 seconds, at 6 GB (it stops at our 3.5 GB limit). `greedy_solution.py` and `random_solution.py` give invalid output |
| `polyhash-24_coralietosten` | 443,574 | `main.py` scored 443,574 in 11 seconds, keeping the best of its strategies. Its stored output scores 391,092 |
| `hashcode-2015_phlalx` | 389,032 | scored 389,032 at the 10-minute limit with 21 of 53 balloons planned, with a writer we added, because the original writes nothing until it finishes |
| `hashcode-loon_dd0` | 373,847 | scored 373,847 in 124 seconds, with our changes: it wrote no submission and started from a fixed cell, and we turned moves the rules forbid into stays |
| `polyhash2024_IIXIVII` | 373,695 | `ClusteredPath` scored 373,695. `Mathis`, `RSMT` and `RSMTv2` give invalid output, `RSMTv3` wrote nothing in 10 minutes, and `ECM`, `bfs` and `CBBA` hit even a 6 GB memory limit |
| `HashCode2015-FinalRound_nicolas-legroux` | 326,583 | `DivisionSolver` scored 326,583 in 490 seconds. The commented-out `DijkstraSolver` and `Solver` crash when enabled |
| `google-hashcode2015-sigmaBoys_maxday` | 273,712 | `sigmaFinal` scored 273,712, with its hardcoded Windows input path changed |
| `HashCode2017Warmup_stoman` | 263,664 | mode `channel` scored 263,664 and `naive` 59,084. Mode `emi` gives invalid output |
| `google-hashcode-2015_flashcode` | 209,905 | scored 209,905 in 13 seconds |
| `hashcode2015_nicomev` | 165,682 | scored 165,682 in 4 seconds, with Python 2 |
| `Polyhash_daymanka` | 52,507 | option 4 scored 52,507, and options 1 to 3 scored less |
| `hashcode2015_zorun` | 22,371 | `loon.py` prints a hand-written solution that scores 22,371. `loon_v2.py` fails on current `networkx` |
| `HashCode2015-finalround_Dewep` | 10,784 | `main.py` scored 10,784. `main_paths.py` crashes |
| `Hashcode2015_evilz-agent` | — | not run, because it is an old .NET Framework project. Reading the code, it launches every balloon once and leaves it there, and that output scores 1,249 |
| `LoonBalloons_Flag-Systemes` | — | not a solver: `Main` builds the grid and computes the coverage of one cell, and writes nothing |
| `Loon_HashCode_2015_sofiia-tesliuk` | — | invalid output: a balloon descends to altitude 0. It prints a score of 184,593, which we did not check |
| `Loon_demmerichs` | — | invalid output: the Java program at the 10-minute limit, and the C++ program before it hit even a 6 GB memory limit. Its stored outputs are also invalid, and were made for a different input |
| `Polyhash-project_tristandefay44-collab` | — | no valid output: five methods wrote nothing in 10 minutes, and `random` crashes |
| `hashcode-2015-loons_mattias-lundell` | — | never writes a submission. With Python 2 it prints a score of 154,448, which we did not check |
| `hashcode-2015_marioyc` | — | `loon.cpp` is cut off in the middle of `main` and does not compile. The other programs in the repository are for Optimize a Data Center or only print a grid |
| `hashcode16_valenca` | — | unfinished: it has a syntax error and no submission writer |
| `polyhash_GabrielPlayeur` | — | wrote nothing in 10 minutes. Its README reports 509,000 after 1 hour 43 minutes |

## What may understate a program

- **`hashcode-2015_phlalx` uses a similar method but runs slower.** At the 10-minute limit it had planned 21 of 53 balloons for 389,032, and its planned balloons scored about the same as the kept solver's at the same count. With more time it could score much higher. Its original also writes nothing until it finishes, so we added a writer.
- **Slow Python programs have no score.** `polyhash_GabrielPlayeur` wrote nothing in 10 minutes, and its README reports 509,000 after 1 hour 43 minutes, which is still below the line.
- **Programs were pinned to one core,** including `polyhash2024_IIXIVII` `ECM`, which is written to run in parallel. Its README reports 408,000 at best, also below the line.
- **Invalid outputs count as 0.** Several programs lower a balloon to altitude 0 or raise it past altitude 8, which the rules forbid. `sofiia-tesliuk` reports 184,593 for itself that way. We repaired this only for `dd0`, to see whether it could compete.
- **Setup changes.** Paths were changed or the input was copied where programs expect it, including over the `r70` input that some repositories store, which is not the official instance. Debug text around the 400 answer lines was removed before judging. Some programs needed Python 2, and `sofiia-tesliuk` needed a visualization import removed and a pandas call updated. `zorun` `loon_v2.py` still failed on current `networkx`, and we did not try an older version.
