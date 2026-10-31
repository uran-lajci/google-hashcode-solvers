# Optimize a Data Center

Google Hash Code 2015, Qualification round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2015/qualification](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2015/qualification).

## Why only four solvers

Four solvers are kept out of 54 repositories, and three more repositories stay because they need a Gurobi or CPLEX license and cannot be run here ([LICENSED_SOLVERS.md](../LICENSED_SOLVERS.md)). A solver is kept if it is first on the instance, or if its mean score is within 5% of the best score in the competition (at least 387, 95% of 407). All usable programs got a screen with one seed and a 5-minute limit. The programs that could still be competitive got 10 runs at a 10-minute limit. The details are in [SOLVER_SELECTION.md](SOLVER_SELECTION.md).

The kept solvers live in [`solvers/`](solvers/) under method names, with their outputs in [`output/`](output/). `hashcode2017_Diegoriggle77`, removed below, stores an output that scores 418, above the top team's 407, which no code in its repository produces.

## Collected solvers

7 solvers: 4 documented by hand (details below the tables) and 3 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/restarted_ratio_greedy_pool_swaps`](solvers/restarted_ratio_greedy_pool_swaps/) | C++ | Our runs: 400 on all 10 runs |
| [`solvers/density_greedy_worst_pool_improvement`](solvers/density_greedy_worst_pool_improvement/) | C++ | Our runs: 398 best, mean 397.8 (`full-2-3`) |
| [`solvers/row_balanced_greedy_pool_coloring`](solvers/row_balanced_greedy_pool_coloring/) | Java | Our runs: 391 |
| [`solvers/density_greedy_pool_lookahead`](solvers/density_greedy_pool_lookahead/) | JavaScript | Our runs: 387 |

### Imported in bulk

Folder names are `<repo>_<owner>`. Commit is the snapshot imported (`.git` removed); *Notes* quotes the first descriptive line of the repo's own README, unedited.

| Folder | Source | Commit (history) | Language | Notes |
|---|---|---|---|---|
| [`google-hash-code-solutions_jp172`](google-hash-code-solutions_jp172/) | [jp172/google-hash-code-solutions](https://github.com/jp172/google-hash-code-solutions) | `2d5f23c` (2020-02-24 → 2020-02-24, 1 commit) | C++ | Only part of a multi-problem repo: `2015-quali`. README: “In this repo I gradually add my solutions to various google hash code tasks I solved throughout the years. You can find the original problem statements and input data here.” |
| [`hashcodeDataCenterOptmization_vilelabruno`](hashcodeDataCenterOptmization_vilelabruno/) | [vilelabruno/hashcodeDataCenterOptmization](https://github.com/vilelabruno/hashcodeDataCenterOptmization) | `9ee2b49` (2020-02-02 → 2020-02-02, 1 commit) | Java | 1 official input copy removed (see list below). |
| [`OptimizeDatacenter_Hashcode2015_exo404`](OptimizeDatacenter_Hashcode2015_exo404/) | [exo404/OptimizeDatacenter_Hashcode2015](https://github.com/exo404/OptimizeDatacenter_Hashcode2015) | `a79ccb8` (2024-07-17 → 2024-07-17, 1 commit) | Python, Python (Jupyter) | 1 official input copy removed (see list below). README: “directory for some prototypes of script directory with server's allocations and scores optimal solution using Guroby in python greedy custom solution using python's classes gap calculator to estimate the quality of the heuristic” |

### [`solvers/restarted_ratio_greedy_pool_swaps/`](solvers/restarted_ratio_greedy_pool_swaps/)

- **Source:** https://github.com/phlalx/hashcode-2015
- **Snapshot:** GitHub clone at commit `6a91ff8` (2017-05-17); `.git` removed on import.
- **Origin:** Its README says these were submissions to the 2015 contest.
- **Language:** C++
- **Approach:** Greedy by capacity per square root of size, with pool swaps, restarted forever.
- **Run:** `g++ -O2 -std=c++17 -fpermissive -include bits/stdc++.h -o solve main.cpp aux.cpp io.cpp` in `qualification/`, then `./solve < input`; it writes `best.out`.
- **Benchmark:** 400 on all 10 runs, first. We added the writer for `best.out`, and the program crashes on about half of its runs ([scores](output/restarted_ratio_greedy_pool_swaps/scores.md)).
- **Removed on import:** 1 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/density_greedy_worst_pool_improvement/`](solvers/density_greedy_worst_pool_improvement/)

- **Source:** https://github.com/stoman/HashCode2017Warmup
- **Snapshot:** GitHub clone at commit `14e0a07` (2017-03-31); `.git` removed on import.
- **Origin:** Practice for Hash Code 2017, on a past problem.
- **Language:** C++
- **Approach:** Greedy by capacity per slot, worst-pool assignment and random pool swaps, with five modes.
- **Run:** `g++ -O2 -std=c++20 -fpermissive -o solve code/main.cpp` in `datacenter/`, then `./solve full-2-3 < input > output`.
- **Benchmark:** 398 best, mean 397.8, with mode `full-2-3`. No code changes ([scores](output/density_greedy_worst_pool_improvement/scores.md)).
- **Removed on import:** 1 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/row_balanced_greedy_pool_coloring/`](solvers/row_balanced_greedy_pool_coloring/)

- **Source:** https://github.com/nicolas-legroux/HashCode2015-QualificationRound
- **Snapshot:** GitHub clone at commit `12b9d10` (2015-03-12); `.git` removed on import.
- **Origin:** Committed in March 2015, just after the round.
- **Language:** Java
- **Approach:** Row-balanced greedy placement, then pool assignment by what each pool already holds in the row.
- **Run:** `javac -d out src/*.java`, then `java -cp ../out Test` from `src/`, with the instance at `src/data/dc.in` and a `src/results/` folder.
- **Benchmark:** 391, deterministic. No code changes ([scores](output/row_balanced_greedy_pool_coloring/scores.md)).
- **Removed on import:** 1 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/density_greedy_pool_lookahead/`](solvers/density_greedy_pool_lookahead/)

- **Source:** https://github.com/kobr4/g_hashcodes
- **Snapshot:** GitHub clone at commit `cd87140` (2022-03-06); `.git` removed on import.
- **Origin:** Committed in 2022, long after the round.
- **Language:** JavaScript
- **Approach:** Greedy by capacity per cell, with a one-step look-ahead over the pools.
- **Run:** `node hashcode_qualif_2015/solver/solver.js` from the folder root, with the instance as `dc.in` there.
- **Benchmark:** 387, deterministic. No code changes ([scores](output/density_greedy_pool_lookahead/scores.md)).

## Removed after benchmarking

These 47 repositories were screened or examined on 2026-10-31 and then deleted from the collection (see *Why only four solvers* above). *Full protocol* means 10 runs at a 10-minute limit. *Screen only* means one run at a 5-minute limit.

- `DataCenter_antonio-ramadas` (https://github.com/antonio-ramadas/DataCenter): unfinished: it only parses the input and never writes a submission.
- `FU-Hashcode2016Training_JohannGameDev` (https://github.com/JohannGameDev/FU-Hashcode2016Training): invalid output: `team42/main.c` places a server past the end of a row, in our run and in its stored output.
- `GoogleHashCodePast_Lefteris008` (https://github.com/Lefteris008/GoogleHashCodePast): never writes a submission: it only prints the instance and a grid.
- `HashCode2015-qualificationround_Dewep` (https://github.com/Dewep/HashCode2015-qualificationround): full protocol: `main.py`, mean 370.0, best 370. Not first, and below 387.
- `HashCode2015_WhiteShadowHashCode2015` (https://github.com/WhiteShadowHashCode2015/HashCode2015): screen only: `src/hashCode2015/HashCode2015.java` scored 299.
- `HashCode2015_brochape` (https://github.com/brochape/HashCode2015): screen only: its output scores 0.
- `HashCode2015_cedricbastin` (https://github.com/cedricbastin/HashCode2015): never writes a submission. Run by hand with Scala 2.13, it prints a score of 135.
- `HashCode2015_mtrellet` (https://github.com/mtrellet/HashCode2015): no valid output: `parsing.py` was still running at 10 minutes and writes server ids into its file, which is not the submission format. `vrjunkies_intel.py` prints 253 and has its writer commented out.
- `HashCode_2015_ydubernet` (https://github.com/ydubernet/HashCode_2015): full protocol: `Trial_Round_2015/src/fr/google/hashcode/main/Main.java`, mean 340.0, best 340. Not first, and below 387.
- `Hashcode-15_Richard-Degenne` (https://github.com/Richard-Degenne/Hashcode-15): screen only: `main.cpp` scored 222.
- `Hashcode-Practice_Awen23` (https://github.com/Awen23/Hashcode-Practice): never writes a submission. `zhivko.py` prints a best of 314 in 10 minutes.
- `Hashcode2015_evilz-agent` (https://github.com/evilz-agent/Hashcode2015): no valid output at 10 minutes from `HashCode2015` or `Genetic`, after replacing their .NET Framework projects with .NET 6 ones. Its stored output scores 368.
- `Optimize-a-Data-Center_jmrCalvo` (https://github.com/jmrCalvo/Optimize-a-Data-Center): does not compile: the C# has syntax errors.
- `Optimize-a-Data-Center_rpicout` (https://github.com/rpicout/Optimize-a-Data-Center): full protocol: `src/main/Main.java`, mean 336.0, best 336. Not first, and below 387.
- `Optimize_a_data_center_Google_Hash-Code_2015_Sanket-HP` (https://github.com/Sanket-HP/Optimize_a_data_center_Google_Hash-Code_2015): screen only: `Optimize_a_Data-Center/src/main.c` scored 236.
- `RP-Optimize-a-data-center_bearojas` (https://github.com/bearojas/RP-Optimize-a-data-center): never writes a submission: it only prints the instance.
- `colonel_erichoco` (https://github.com/erichoco/colonel): never writes a submission: `writeSubmission` is never called.
- `data-center-optimization_cptanalatriste` (https://github.com/cptanalatriste/data-center-optimization): screen only: its output scores 0. It needed Python 2 with numpy.
- `evilz-agent-Hashcode2014_evilz-agent` (https://github.com/evilz-agent/evilz-agent-Hashcode2014): does not build here: old .NET Framework project, and it still failed as .NET 6.
- `google-hash-code-optimize-a-data-center_islam-aymann` (https://github.com/islam-aymann/google-hash-code-optimize-a-data-center): crashes with an index error during placement.
- `google-hashcode-2015_flashcode` (https://github.com/flashcode/google-hashcode-2015): full protocol: `qualification/hashcode_2015_jambonneau_qualif.py`, mean 383.0, best 383. Not first, and below 387.
- `google-hashcode-2015_sebysr` (https://github.com/sebysr/google-hashcode-2015): not a solver: it reads a finished submission and computes its score.
- `hascode_mmarouen` (https://github.com/mmarouen/hascode): no valid output: all three CP-SAT models hit our 3.5 GB memory limit within 3 minutes.
- `hashcode-2015-qualification_mattias-lundell` (https://github.com/mattias-lundell/hashcode-2015-qualification): invalid output: a server on an unavailable slot, because the row loop reads the wrong row's unavailable slots.
- `hashcode-2015_Groscheri` (https://github.com/Groscheri/hashcode-2015): no valid output: it crashes after about 5 minutes and prints a score of 0.
- `hashcode-2015_PierreLvx` (https://github.com/PierreLvx/hashcode-2015): screen only: its output scores 0.
- `hashcode-2015_af83` (https://github.com/af83/hashcode-2015): full protocol: `qualif/data_center.rb`, mean 379.0, best 379. Not first, and below 387.
- `hashcode-2015_joelklint` (https://github.com/joelklint/hashcode-2015): never writes a submission. `Main.java` prints a best of 365.
- `hashcode-datacenter-2015_trampfox` (https://github.com/trampfox/hashcode-datacenter-2015): full protocol: `src/main/java/com/reply/hashcode/Application.java`, mean 341.1, best 348. Not first, and below 387.
- `hashcode-training_EduRibeiro00` (https://github.com/EduRibeiro00/hashcode-training): crashes on the real instance (row and slot swapped when reading unavailable slots), and only prints its state.
- `hashcode16_valenca` (https://github.com/valenca/hashcode16): full protocol: `qualif15/19/other_guy.py`, mean 383.0, best 383. Not first, and below 387.
- `hashcode2014_hugopetiot` (https://github.com/hugopetiot/hashcode2014): never writes a submission: it only prints a grid.
- `hashcode2015.1_jdmichaud` (https://github.com/jdmichaud/hashcode2015.1): crashes on the instance, and has no submission writer.
- `hashcode2015_Antoinephi` (https://github.com/Antoinephi/hashcode2015): no valid output, and it prints negative scores.
- `hashcode2015_ChickenWingsHashCode` (https://github.com/ChickenWingsHashCode/hashcode2015): never writes a submission: `Main` stops after the pools, and `ProblemSolver` crashes with an index error.
- `hashcode2015_a14n` (https://github.com/a14n/hashcode2015): does not run: Dart 1 code that fails to compile on current Dart.
- `hashcode2015_guilbill` (https://github.com/guilbill/hashcode2015): screen only: its output scores 0.
- `hashcode2015_houghstc` (https://github.com/houghstc/hashcode2015): invalid output: a server on an unavailable slot.
- `hashcode2015_nicomev` (https://github.com/nicomev/hashcode2015): full protocol: `qualif/test2/main.py`, mean 360.0, best 360. Not first, and below 387.
- `hashcode2015_zorun` (https://github.com/zorun/hashcode2015): full protocol: `python/dc.py`, mean 386.0, best 386. Not first, and below 387.
- `hashcode2017_Diegoriggle77` (https://github.com/Diegoriggle77/hashcode2017): its stored `res_0000000418` scores 418, above the top team, but no code in the repository produces it. `run.py` never writes a file and gives an invalid placement. See [SOLVER_SELECTION.md](SOLVER_SELECTION.md).
- `hashcode_abderraza8k` (https://github.com/abderraza8k/hashcode): not a solver: it writes the placeholder `1 2 3` for every server.
- `hashcode_cmercier` (https://github.com/cmercier/hashcode): screen only: `main.cpp` scored 197.
- `hashcode_nsvir` (https://github.com/nsvir/hashcode): not a solver: `main.ml` places three fixed servers, and the code was not run.
- `hashcode_vikingeff` (https://github.com/vikingeff/hashcode): never writes a submission: the call to its writer is commented out. Its stored output scores 324.
- `hashcodeparis-2015_vbarthel-fr` (https://github.com/vbarthel-fr/hashcodeparis-2015): screen only: its output scores 0. It needed its resource lookup changed to load the input.
- `qualification-round-2015_Gophing-Around` (https://github.com/Gophing-Around/qualification-round-2015): full protocol: `main.go`, mean 359.0, best 359. Not first, and below 387.

## Official inputs removed

5 files in 5 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>hashcodeDataCenterOptmization_vilelabruno</code> (1 files)</summary>

- `dc.in` ← `archive/2015/qualification/hashcode_2015_qualification_round.in`

</details>

<details><summary><code>OptimizeDatacenter_Hashcode2015_exo404</code> (1 files)</summary>

- `input_output/hashcode_2015_qualification_round.in` ← `archive/2015/qualification/hashcode_2015_qualification_round.in`

</details>

<details><summary><code>solvers/density_greedy_worst_pool_improvement</code> (1 files)</summary>

- `datacenter/data/large.in` ← `archive/2015/qualification/hashcode_2015_qualification_round.in`

</details>

<details><summary><code>solvers/restarted_ratio_greedy_pool_swaps</code> (1 files)</summary>

- `qualification/task.txt` ← `archive/2015/qualification/hashcode_2015_qualification_round.in`

</details>

<details><summary><code>solvers/row_balanced_greedy_pool_coloring</code> (1 files)</summary>

- `data/dc.in` ← `archive/2015/qualification/hashcode_2015_qualification_round.in`

</details>
