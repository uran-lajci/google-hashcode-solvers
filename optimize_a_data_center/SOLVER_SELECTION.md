# Optimize a Data Center: choosing the best solvers

Google Hash Code 2015, Qualification round, which has a single instance. 54 repositories were in the folder. 4 solvers were kept, 3 repositories stay because they need a license we do not have, and 47 were removed.

## Kept

| Solver | Repository | Best | Mean | Placement | Why |
|---|---|---:|---:|---:|---|
| [restarted_ratio_greedy_pool_swaps](solvers/restarted_ratio_greedy_pool_swaps/) | `phlalx` | **400** | 400.0 | 4 | First on the instance |
| [density_greedy_worst_pool_improvement](solvers/density_greedy_worst_pool_improvement/) | `stoman`, mode `full-2-3` | 398 | 397.8 | 7 | 5% rule |
| [row_balanced_greedy_pool_coloring](solvers/row_balanced_greedy_pool_coloring/) | `nicolas-legroux` | 391 | 391.0 | 12 | 5% rule |
| [density_greedy_pool_lookahead](solvers/density_greedy_pool_lookahead/) | `kobr4` | 387 | 387.0 | 22 | 5% rule, exactly on the line |

The top team has 407, so the 5% line is 387 (95% of 407 is 386.65). `hashcode2015_zorun` misses it by one point, at 386 on all 10 runs. No program we ran reaches 407.

Two things about the chosen solvers matter when using them:

- **`restarted_ratio_greedy_pool_swaps` includes a change of ours.** The original loops forever and never writes its answer. We added a writer for `best.out`, without changing the search. It also crashes with a memory error on about half of its runs (5 of 10, after 5 to 119 seconds). The score held anyway, because the file is complete by then, and all 10 runs scored 400.
- **`density_greedy_worst_pool_improvement` is one program with five modes,** and the mean above is its best mode. The other modes are in the table below.

## The stored score of 418

`hashcode2017_Diegoriggle77` stores a file, [`practice/servers/res_0000000418`](https://github.com/Diegoriggle77/hashcode2017/blob/master/practice/servers/res_0000000418), that the official judge scores at 418. That is above the top team's 407 and above everything we ran. It was not kept, because no code in the repository produces it:

- `run.py` never writes a file, and its swap loop never undoes a bad swap. A commented-out line reads the 418 file back, so the team built it over several runs of earlier code.
- With a writer added, `run.py` gives an invalid placement, because `read_data` skips one unavailable slot.
- With that bug fixed and bad swaps undone, it reached 391 in one 10-minute run. That is three changes to its code, so we do not count it as the repository's result.

## What we did

1. **Collected.** 54 repositories, after the earlier non-solver prunes. 98 programs were found, leaving out test and visualization code by hand.
2. **Screened.** One run with a 5-minute limit, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/optimize_a_data_center/judge.py`. A run whose output the judge rejects counts as 0.
3. **Advanced.** A program went on if it was within 20% of the best (at least 318), which also covers the top 3. A program with no valid output at 5 minutes got a 10-minute run.
4. **Full protocol.** 21 programs got 10 runs at a 10-minute limit, as seeds 1 to 10. The seed reaches Python programs through `random`, `numpy` and `PYTHONHASHSEED`. The other programs ignore it, so a deterministic one gives the same output each time, and `phlalx` and `stoman` vary on their own.
5. **Selected.** A solver is kept if it is first on the instance by its best run, or if its mean is at least 387. The others were deleted.
6. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods, and each README starts with a header giving the source and the method. The outputs in [output/](output/) come from the runs above and were not repeated after the move.

## Full protocol

Placement is where the best run would rank among the 230 teams.

| Repository | Program | Best | Mean | Worst | Placement | Stage |
|---|---|---:|---:|---:|---:|---|
| `hashcode-2015_phlalx` | `qualification/main.cpp` | 400 | 400.0 | 400 | 4 | **chosen** (first) |
| `HashCode2017Warmup_stoman` | `datacenter/code/main.cpp` `full-2-3` | 398 | 397.8 | 397 | 7 | **chosen** (5% rule) |
| `HashCode2017Warmup_stoman` | `datacenter/code/main.cpp` `full-1-2` | 398 | 397.2 | 397 | 7 | same solver, other mode |
| `HashCode2017Warmup_stoman` | `datacenter/code/main.cpp` `full-3-4` | 397 | 396.4 | 394 | 8 | same solver, other mode |
| `HashCode2017Warmup_stoman` | `datacenter/code/main.cpp` `mockplacement` | 396 | 394.8 | 394 | 8 | same solver, other mode |
| `HashCode2015-QualificationRound_nicolas-legroux` | `src/Test.java` | 391 | 391.0 | 391 | 12 | **chosen** (5% rule) |
| `HashCode2017Warmup_stoman` | `datacenter/code/main.cpp` `full-1` | 394 | 390.0 | 382 | 10 | same solver, other mode |
| `g_hashcodes_kobr4` | `hashcode_qualif_2015/solver/solver.js` | 387 | 387.0 | 387 | 22 | **chosen** (5% rule) |
| `hashcode2015_zorun` | `python/dc.py` | 386 | 386.0 | 386 | 25 | full protocol |
| `google-hashcode-2015_flashcode` | `qualification/hashcode_2015_jambonneau_qualif.py` | 383 | 383.0 | 383 | 30 | full protocol |
| `hashcode16_valenca` | `qualif15/19/other_guy.py` | 383 | 383.0 | 383 | 30 | full protocol |
| `OptimizeDatacenter_Hashcode2015_exo404` | `test/sol.py` | 383 | 383.0 | 383 | 30 | full protocol |
| `hashcode-2015_af83` | `qualif/data_center.rb` | 379 | 379.0 | 379 | 36 | full protocol |
| `HashCode2015-qualificationround_Dewep` | `main.py` | 370 | 370.0 | 370 | 51 | full protocol |
| `hashcode2015_nicomev` | `qualif/test2/main.py` | 360 | 360.0 | 360 | 63 | full protocol |
| `qualification-round-2015_Gophing-Around` | `main.go` | 359 | 359.0 | 359 | 65 | full protocol |
| `hashcode2015_nicomev` | `qualif/main.py` | 357 | 357.0 | 357 | 71 | full protocol |
| `hashcode16_valenca` | `qualif15/19/datacenter.py` | 353 | 353.0 | 353 | 76 | full protocol |
| `hashcode-datacenter-2015_trampfox` | `src/main/java/com/reply/hashcode/Application.java` | 348 | 341.1 | 328 | 79 | full protocol |
| `HashCode_2015_ydubernet` | `Trial_Round_2015/src/fr/google/hashcode/main/Main.java` | 340 | 340.0 | 340 | 85 | full protocol |
| `Optimize-a-Data-Center_rpicout` | `src/main/Main.java` | 336 | 336.0 | 336 | 89 | full protocol |

## Screen only

One run at a 5-minute limit.

| Repository | Program | Score | Time (s) |
|---|---|---:|---:|
| `hashcode16_valenca` | `qualif15/alex/main.py` | 306 | 0 |
| `HashCode2015_WhiteShadowHashCode2015` | `src/hashCode2015/HashCode2015.java` | 299 | 0 |
| `hashcode16_valenca` | `qualif15/val/main.py` | 277 | 0 |
| `Optimize_a_data_center_Google_Hash-Code_2015_Sanket-HP` | `Optimize_a_Data-Center/src/main.c` | 236 | 0 |
| `Hashcode-15_Richard-Degenne` | `main.cpp` | 222 | 0 |
| `hashcode_cmercier` | `main.cpp` | 197 | 0 |
| `hashcode16_valenca` | `qualif15/carlosf/main.c` | 190 | 0 |
| `hashcode-2015_PierreLvx` | `src/main.c` | 0 | 0 |
| `hashcode2015_guilbill` | `src/main/java/team/monalisa/App.java` | 0 | 0 |
| `HashCode2015_brochape` | `solver.py` | 0 | 0 |
| `hashcodeparis-2015_vbarthel-fr` | `hashcode/qualification-round/src/main/java/fr/mashbarth/hashcode/qualificationround/Launcher.java` | 0 | 0 |
| `data-center-optimization_cptanalatriste` | `driver.py` | 0 | 7 |

## No score from us

The stored output is the best file in the repository scored with the official judge, where one exists.

| Repository | Why it has no score from us | Stored output |
|---|---|---:|
| `DataCenter_antonio-ramadas` | unfinished: it only parses the input and never writes a submission | — |
| `FU-Hashcode2016Training_JohannGameDev` | invalid output: `team42/main.c` places a server past the end of a row, in our run and in its stored output | — |
| `GoogleHashCodePast_Lefteris008` | never writes a submission: it only prints the instance and a grid | — |
| `HashCode2015_cedricbastin` | never writes a submission. Run by hand with Scala 2.13, it prints a score of 135 | — |
| `HashCode2015_mtrellet` | no valid output: `parsing.py` was still running at 10 minutes and writes server ids into its file, which is not the submission format. `vrjunkies_intel.py` prints 253 and has its writer commented out | — |
| `Hashcode-Practice_Awen23` | never writes a submission. `zhivko.py` prints a best of 314 in 10 minutes | — |
| `Hashcode2015_evilz-agent` | no valid output at 10 minutes from `HashCode2015` or `Genetic`, after replacing their .NET Framework projects with .NET 6 ones | 368 |
| `Optimize-a-Data-Center_jmrCalvo` | does not compile: the C# has syntax errors | — |
| `RP-Optimize-a-data-center_bearojas` | never writes a submission: it only prints the instance | — |
| `colonel_erichoco` | never writes a submission: `writeSubmission` is never called | — |
| `evilz-agent-Hashcode2014_evilz-agent` | does not build here: old .NET Framework project, and it still failed as .NET 6 | — |
| `google-hash-code-optimize-a-data-center_islam-aymann` | crashes with an index error during placement | — |
| `google-hashcode-2015_sebysr` | not a solver: it reads a finished submission and computes its score | — |
| `hascode_mmarouen` | no valid output: all three CP-SAT models hit our 3.5 GB memory limit within 3 minutes | — |
| `hashcode-2015-qualification_mattias-lundell` | invalid output: a server on an unavailable slot, because the row loop reads the wrong row's unavailable slots | — |
| `hashcode-2015_Groscheri` | no valid output: it crashes after about 5 minutes and prints a score of 0 | — |
| `hashcode-2015_joelklint` | never writes a submission. `Main.java` prints a best of 365 | — |
| `hashcode-training_EduRibeiro00` | crashes on the real instance (row and slot swapped when reading unavailable slots), and only prints its state | — |
| `hashcode2014_hugopetiot` | never writes a submission: it only prints a grid | — |
| `hashcode2015.1_jdmichaud` | crashes on the instance, and has no submission writer | — |
| `hashcode2015_Antoinephi` | no valid output, and it prints negative scores | — |
| `hashcode2015_ChickenWingsHashCode` | never writes a submission: `Main` stops after the pools, and `ProblemSolver` crashes with an index error | — |
| `hashcode2015_a14n` | does not run: Dart 1 code that fails to compile on current Dart | — |
| `hashcode2015_houghstc` | invalid output: a server on an unavailable slot | — |
| `hashcode_abderraza8k` | not a solver: it writes the placeholder `1 2 3` for every server | — |
| `hashcode_nsvir` | not a solver: `main.ml` places three fixed servers, and the code was not run | — |
| `hashcode_vikingeff` | never writes a submission: the call to its writer is commented out | 324 |

`hashcode2017_Diegoriggle77` is described above.

## What may understate a program

- **Licensed solvers were not run.** `google-hash-code-solutions_jp172` (Gurobi), `hashcodeDataCenterOptmization_vilelabruno` (CPLEX) and the `ottima` programs of `OptimizeDatacenter_Hashcode2015_exo404` (Gurobi) are exact models. They could score higher than anything here. The three repositories stay in the folder, as [LICENSED_SOLVERS.md](../LICENSED_SOLVERS.md) says. `exo404` also has free greedy programs, which scored 383 at most.
- **The free exact models hit our memory limit.** The CP-SAT models of `hascode_mmarouen` were stopped at 3.5 GB. We did not try them with more memory.
- **Programs that never write an answer have no score.** We added a writer only to `phlalx` and `Diegoriggle77`, the two that looked able to compete. `joelklint` and `Awen23` print their own bests, of 365 and 314, which we did not check.
- **Setup changes.** To run at all, some programs needed Python 2, or Python 2 code converted to Python 3 (`hashcode16_valenca` `19/datacenter.py`), or C# projects moved to .NET 6, or the input copied to the path they expect. Debug text around the 625 answer lines was removed from outputs before judging, and `-1` for an unplaced server was read as `x`. `brochape` needed its output method to be called, and scored 0.
