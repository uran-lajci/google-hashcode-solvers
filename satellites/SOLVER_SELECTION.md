# Satellites: choosing the best solvers

Google Hash Code 2016, Final round, which has four instances. 15 repositories were in the folder. 2 solvers were kept and 13 were removed. None needs a license.

## Kept

| Solver | Repository | forever_alone | weekend | constellation | overlap | Why |
|---|---|---:|---:|---:|---:|---|
| [kd_tree_greedy_and_satellite_search](solvers/kd_tree_greedy_and_satellite_search/), mode `raph` | `aliphen` | **55,728** | no output | no output | crashes | First on `forever_alone` |
| [kd_tree_greedy_and_satellite_search](solvers/kd_tree_greedy_and_satellite_search/), mode `gui` | `aliphen` | 48,000 | 47,522 | 61,817 | **32,857** | First on `overlap` |
| [per_turn_first_fit_greedy](solvers/per_turn_first_fit_greedy/) | `nicolas-gaillard` | 43,328 | **68,495** | **91,222** | invalid | First on `weekend` and `constellation` |

Bold is first on that instance. The scoreboard gives only totals. The top team has 1,017,218, so the 5% line is 966,358 (95% of 1,017,218 is 966,357.1). The best score per instance sums to 248,302, about a quarter of that, so no program qualifies under the 5% rule and both solvers are kept for being first on an instance. A team would need about 400,000 to reach 20th place of the 51 on the scoreboard, so these are weak solvers that happen to be the best we could run.

## The thesis program

`Thesis-Code_KreshnikRamadani` is a genetic algorithm from a master's thesis. Its `BestResults.txt` reports 360,047, 60,032, 59,565 and 357,970, which is 837,614 in total and far above everything else here. It was removed, because the official judge rejects its output:

- The program is a Windows Forms application, so we built a console version with the same parsing, the author's parameters and a writer that saves the best plan.
- It scores its own plans at about 60,000 on `forever_alone` and over 200,000 on `weekend` and `constellation`, so it behaves as the thesis says. Those plans break the rules: on `forever_alone`, the camera turns 6,440 arcseconds in 121 turns, where the limit is 1,815. A comment in its form code says of its own check on this rule, "This is false".
- With the illegal photos removed in turn order, its `forever_alone` plan scores 39,584, below the kept solvers. We did not count that as its score, because it is our repair.
- On `overlap` it wrote nothing in 10 minutes.

`hashcode2017_Diegoriggle77` is similar. Its `stephane` program reports 371,433 on `overlap`, but it looks for each image separately and ignores the camera limits, and the judge rejects the output.

## What we did

1. **Collected.** 15 repositories, after the earlier non-solver prunes.
2. **Screened.** One run with a 5-minute limit on all four instances, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/satellites/judge.py`. A run whose output the judge rejects counts as 0.
3. **10-minute runs.** A program with no valid output at 5 minutes got a 10-minute run on that instance.
4. **Full protocol.** A program advanced on an instance if it was in the top 3 or within 20% of the best there. It then got 10 runs at a 10-minute limit, or 2 runs if it has no random choices and cannot differ. No program can reach the 5% line, so the only open question is who is first, and we ran each program only on the instances where it advanced. Every program gave the same score on every run.
5. **Selected.** A solver is kept if it is first on an instance by its best run, or if the sum of its means is at least 966,358. The others were deleted.
6. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods, and each README starts with a header giving the source and the method. The outputs in [output/](output/) come from the runs above and were not repeated after the move.

`Togodumnus` scored exactly what its README reports on all four instances, which supports the setup and the judge.

## Removed repositories

The scores are the best valid ones we got. A dash means no valid output.

| Repository | forever_alone | weekend | constellation | overlap | Sum | Why it is out |
|---|---:|---:|---:|---:|---:|---|
| `google_hashcode_2016_Togodumnus` | 48,000 | 49,026 | 61,631 | 10,490 | 169,147 | not first anywhere. `GloutonAlgo` matches the scores in its README, and `BasicAlgo` and `ConstraintAlgo` score less |
| `hashcode-2016-final_joffrey-bion` | 48,000 | 51,794 | 47,971 | — | 147,765 | not first anywhere, and wrote nothing on `overlap` in 10 minutes |
| `-Google-Hash-Code-2016-_SimylinK` | 48,592 | — | — | — | 48,592 | second on `forever_alone`. Invalid on `weekend` and `constellation`, where a satellite takes two images in one turn, and wrote nothing on `overlap` in 10 minutes |
| `hashcode2016_ifsmirnov` | 48,000 | — | — | — | 48,000 | ties at 48,000 on `forever_alone`. It takes no photos on `weekend` and `overlap`, and wrote nothing on `constellation` in 10 minutes, where it prints 61,697 |
| `polyhash-2016_nquinquenel` | 36,208 | — | — | — | 36,208 | `Lanceur.py` scored 36,208 on `forever_alone`, also the score of its stored output. It takes no photos on `weekend` and `constellation`, and crashes on `overlap` |
| `Google-HashCode-2016_amadoukane96` | — | — | — | — | 0 | crashes: `mainLoop` is never called in the repository, and when called it stops on a missing import |
| `HashCode2017Warmup_stoman` | — | — | — | — | 0 | invalid output on all four instances: the camera orientation is far out of range, because its satellite longitude is wrong. It also needed a missing semicolon added to compile |
| `Thesis-Code_KreshnikRamadani` | — | — | — | — | 0 | invalid output: its genetic algorithm breaks the camera rules, and `overlap` wrote nothing in 10 minutes. See *The thesis program*. It reports 837,614 |
| `hashcode-2016-final-round_TechHoruser` | — | — | — | — | 0 | unfinished: its only algorithm returns nothing, so it crashes on every instance |
| `hashcode-2017-prep_drublackberry` | — | — | — | — | 0 | unfinished: `solver.py` is Python 2 code that stops before it chooses any photo, and its writer has a bug. Not run |
| `hashcode-satellites_malhotraa` | — | — | — | — | 0 | never writes a submission: `main.py` only computes positions and prints them. Not run |
| `hashcode2016_marioyc` | — | — | — | — | 0 | invalid output: `final/sol1.cpp` turns the camera too fast on three instances and wrote nothing on `overlap` in 10 minutes. `Finale/youssef.cpp` only prints two counts |
| `hashcode2017_Diegoriggle77` | — | — | — | — | 0 | invalid output: `stephane/main.cpp` ignores the camera limits, and reports 371,433 on `overlap`. `olivier/run.py` only reads files that are not in the repository |

## What may understate a program

- **Programs were pinned to one core,** including the threads of `per_turn_first_fit_greedy` and `Parallel.ForEach` in `raph`. We gave `raph` 3 cores on `weekend` and `constellation`, and it still wrote nothing in 10 minutes. With more time it might beat the others there.
- **The 10-minute limit stops several programs:** `ifsmirnov` on `constellation`, where it prints 61,697, and `joffrey-bion`, `SimylinK` and `marioyc` on `overlap`.
- **Invalid outputs count as 0.** `marioyc`, `SimylinK`, `per_turn_first_fit_greedy` on `overlap`, `stephane` and the thesis program all break a rule somewhere. With illegal photos removed, `marioyc` scores 35,068 on `weekend` and `SimylinK` 2,178, both below the kept solver there, and `stephane` 26,080 on `forever_alone`.
- **Setup changes.** Input paths were changed or the input copied where programs expect it. `aliphen` and the thesis program were moved to .NET 6, and `SimylinK` had its window removed and `time.clock` replaced. `Togodumnus` needed the Boost headers, and `stoman` a missing semicolon. Debug text around the answer lines was removed before judging.
- **Not run:** `malhotraa` and `drublackberry` have no submission writer.
