# Satellites

Google Hash Code 2016, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2016/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2016/final).

## Why only two solvers

Two solvers are kept out of 15 repositories. A solver is kept if it is first on an instance, or if the sum of its per-instance means is within 5% of the top team's total (at least 966,358, 95% of 1,017,218). No program comes near that line, so both are kept for being first on an instance. All usable programs got a screen with one seed and a 5-minute limit, and programs with no valid output got a 10-minute run. The programs that could still be first got the full protocol. The full account is in [SOLVER_SELECTION.md](SOLVER_SELECTION.md).

The kept solvers live in [`solvers/`](solvers/) under method names, with their outputs in [`output/`](output/). The best score per instance sums to 248,302, about a quarter of the top team's 1,017,218.

## Collected solvers

2 solvers: 2 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/kd_tree_greedy_and_satellite_search`](solvers/kd_tree_greedy_and_satellite_search/) | C# (.NET 6) | Our runs: `gui` sum 190,196, first on `overlap`; `raph` first on `forever_alone` |
| [`solvers/per_turn_first_fit_greedy`](solvers/per_turn_first_fit_greedy/) | C++ | Our runs: first on `weekend` and `constellation`; invalid on `overlap` |

### [`solvers/kd_tree_greedy_and_satellite_search/`](solvers/kd_tree_greedy_and_satellite_search/)

- **Source:** https://github.com/aliphen/hashCode2016
- **Snapshot:** GitHub clone at commit `64b418a` (2016-03-26); `.git` removed on import.
- **Language:** C#, moved to .NET 6 by us
- **Approach:** Greedy with a k-d tree (`gui`), and a search over partial plans for each satellite (`raph`).
- **Run:** `dotnet build Hashcode.Finale/hc/hc.csproj -c Release -o out`, then, with the instance in the current folder, `HC_INST=overlap dotnet out/hc.dll gui` (or `raph`). It writes `<instance>-<score>.out`, and the number in that name is the program's own count.
- **Benchmark:** `gui` 48,000, 47,522, 61,817, 32,857; `raph` 55,728 on `forever_alone`. We replaced the project and changed `Program.cs` and one line of `SolverRaph.cs` ([scores](output/kd_tree_greedy_and_satellite_search/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/per_turn_first_fit_greedy/`](solvers/per_turn_first_fit_greedy/)

- **Source:** https://github.com/nicolas-gaillard/SatellitePlusPlus
- **Snapshot:** GitHub clone at commit `7661697` (2017-01-29); `.git` removed on import.
- **Language:** C++
- **Approach:** First-fit greedy, turn by turn, after dropping a fixed share of the collections.
- **Run:** In `Satellite/Satellite/`: `g++ -std=c++14 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve $(ls *.cpp | grep -v mainArbitre)`, then `./solve input output`.
- **Benchmark:** 68,495 on `weekend` and 91,222 on `constellation`, invalid on `overlap`. No code changes ([scores](output/per_turn_first_fit_greedy/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

## Removed after benchmarking

These 13 repositories were screened or examined on 2026-11-01 and then deleted from the collection (see *Why only two solvers* above). A score is the best valid one we got on that instance.

- `-Google-Hash-Code-2016-_SimylinK` (https://github.com/SimylinK/-Google-Hash-Code-2016-): second on `forever_alone`. Invalid on `weekend` and `constellation`, where a satellite takes two images in one turn, and wrote nothing on `overlap` in 10 minutes
- `Google-HashCode-2016_amadoukane96` (https://github.com/amadoukane96/Google-HashCode-2016): crashes: `mainLoop` is never called in the repository, and when called it stops on a missing import
- `HashCode2017Warmup_stoman` (https://github.com/stoman/HashCode2017Warmup): invalid output on all four instances: the camera orientation is far out of range, because its satellite longitude is wrong. It also needed a missing semicolon added to compile
- `Thesis-Code_KreshnikRamadani` (https://github.com/KreshnikRamadani/Thesis-Code): invalid output: its genetic algorithm breaks the camera rules, and `overlap` wrote nothing in 10 minutes. See *The thesis program*. It reports 837,614
- `google_hashcode_2016_Togodumnus` (https://github.com/Togodumnus/google_hashcode_2016): not first anywhere. `GloutonAlgo` matches the scores in its README, and `BasicAlgo` and `ConstraintAlgo` score less
- `hashcode-2016-final-round_TechHoruser` (https://github.com/TechHoruser/hashcode-2016-final-round): unfinished: its only algorithm returns nothing, so it crashes on every instance
- `hashcode-2016-final_joffrey-bion` (https://github.com/joffrey-bion/hashcode-2016-final): not first anywhere, and wrote nothing on `overlap` in 10 minutes
- `hashcode-2017-prep_drublackberry` (https://github.com/drublackberry/hashcode-2017-prep): unfinished: `solver.py` is Python 2 code that stops before it chooses any photo, and its writer has a bug. Not run
- `hashcode-satellites_malhotraa` (https://github.com/malhotraa/hashcode-satellites): never writes a submission: `main.py` only computes positions and prints them. Not run
- `hashcode2016_ifsmirnov` (https://github.com/ifsmirnov/hashcode2016): ties at 48,000 on `forever_alone`. It takes no photos on `weekend` and `overlap`, and wrote nothing on `constellation` in 10 minutes, where it prints 61,697
- `hashcode2016_marioyc` (https://github.com/marioyc/hashcode2016): invalid output: `final/sol1.cpp` turns the camera too fast on three instances and wrote nothing on `overlap` in 10 minutes. `Finale/youssef.cpp` only prints two counts
- `hashcode2017_Diegoriggle77` (https://github.com/Diegoriggle77/hashcode2017): invalid output: `stephane/main.cpp` ignores the camera limits, and reports 371,433 on `overlap`. `olivier/run.py` only reads files that are not in the repository
- `polyhash-2016_nquinquenel` (https://github.com/nquinquenel/polyhash-2016): `Lanceur.py` scored 36,208 on `forever_alone`, also the score of its stored output. It takes no photos on `weekend` and `constellation`, and crashes on `overlap`

## Duplicates removed during import

- [Matsoy/hashcode2016-finalRound](https://github.com/Matsoy/hashcode2016-finalRound) (`85290f0`): same source code (after normalising line endings and whitespace) as `polyhash-2016_nquinquenel`.

## Official inputs removed

8 files in 2 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>solvers/kd_tree_greedy_and_satellite_search</code> (4 files)</summary>

- `Hashcode.Finale/constellation.in` ← `archive/2016/final/hashcode_2016_final_round.in/constellation.in`
- `Hashcode.Finale/forever_alone.in` ← `archive/2016/final/hashcode_2016_final_round.in/forever_alone.in`
- `Hashcode.Finale/overlap.in` ← `archive/2016/final/hashcode_2016_final_round.in/overlap.in`
- `Hashcode.Finale/weekend.in` ← `archive/2016/final/hashcode_2016_final_round.in/weekend.in`

</details>

<details><summary><code>solvers/per_turn_first_fit_greedy</code> (4 files)</summary>

- `Satellite/Satellite/text/constellation.in` ← `archive/2016/final/hashcode_2016_final_round.in/constellation.in`
- `Satellite/Satellite/text/forever_alone.in` ← `archive/2016/final/hashcode_2016_final_round.in/forever_alone.in`
- `Satellite/Satellite/text/overlap.in` ← `archive/2016/final/hashcode_2016_final_round.in/overlap.in`
- `Satellite/Satellite/text/weekend.in` ← `archive/2016/final/hashcode_2016_final_round.in/weekend.in`

</details>
