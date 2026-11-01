# Router Placement: choosing the best solvers

Google Hash Code 2017, Final round, which has four instances. 25 repositories were in the folder. 9 solvers were kept and 16 were removed.

## Kept

| Solver | Repository | charleston_road | rue_de_londres | opera | lets_go_higher | Sum of means | Why |
|---|---|---:|---:|---:|---:|---:|---|
| [coverage_minus_cable_greedy](solvers/coverage_minus_cable_greedy/) | `antonin-arquey` | 21,962,313 | 58,144,021 | 171,912,009 | 290,168,757 | 542,187,100 | Within 5%, highest sum |
| [scored_greedy_with_mst_backbone](solvers/scored_greedy_with_mst_backbone/) | `matteojug` | 21,962,197 | **58,301,019** | 168,673,084 | **290,201,347** | 539,137,647 | Within 5%, first on `rue_de_londres` and `lets_go_higher` |
| [greedy_coverage_steiner_tree](solvers/greedy_coverage_steiner_tree/) | `amadoukane96` | 21,962,464 | 57,419,007 | 170,251,075 | 289,471,682 | 539,104,228 | Within 5% |
| [linked_list_coverage_greedy](solvers/linked_list_coverage_greedy/) | `SebBerlioux` | 21,962,412 | 56,449,071 | 169,222,092 | 290,106,517 | 537,740,092 | Within 5% |
| [max_coverage_then_fill_greedy](solvers/max_coverage_then_fill_greedy/) | `SimylinK` | 21,962,312 | 56,263,059 | 169,156,094 | 290,125,827 | 537,507,292 | Within 5% |
| [max_coverage_threshold_heuristic](solvers/max_coverage_threshold_heuristic/) | `ottins` | 21,952,139 | 52,898,074 | 162,479,089 | 289,785,712 | 527,115,014 | Within 5% |
| [perfect_squares_kd_tree_priority_fill](solvers/perfect_squares_kd_tree_priority_fill/) | `mihai-bontea` | 20,347,830 | 54,095,059 | 168,251,035 | 278,207,727 | 520,901,651 | Within 5%, by 239,476 |
| [coverage_greedy_with_random_router_removal](solvers/coverage_greedy_with_random_router_removal/) | `AlexeyZhuravlev` | — | 57,991,063 | **171,942,099** | — | not valid on all four | First on `opera` |
| [gaussian_blur_placement](solvers/gaussian_blur_placement/) | `Matsoy` | **21,962,533** | 57,867,314 | — | — | not valid on all four | First on `charleston_road` by best run |

Bold is the best run of any program on that instance, and the other numbers are means. The kept programs vary little: only `gaussian_blur` differs between runs, and its mean on `charleston_road` is 21,962,349.

The scoreboard gives only totals. The top team has 548,065,447, so the 5% line is 520,662,175 (95% of 548,065,447 is 520,662,174.65). The best kept program, at 542,187,100, would place 30th of the 50 teams. The best score per instance sums to 542,406,998, which would also place below the top 20 (20th is 543,054,761).

## Three results that depend on our changes

- **Re-listing the backbone.** The statement requires each backbone cell to neighbour the initial cell or a cell listed above it. `coverage_minus_cable_greedy`, `scored_greedy_with_mst_backbone` and `perfect_squares_kd_tree_priority_fill` write valid cells in an order that breaks this rule, or list the initial cell, and the judge rejects those files. Before judging, our benchmark re-listed the same cells outward from the initial cell and dropped the initial cell. Without this, the three would be invalid on some or all instances. Dropping the initial cell also saves the price of one cable.
- **Crash fixes.** `greedy_coverage_steiner_tree` and `max_coverage_then_fill_greedy` crashed on Linux because functions returned references to local variables, so they scored 0 until we fixed that. `greedy_coverage_steiner_tree` then matches its stored outputs exactly, 539,104,228, which supports the fix.
- **Thin margin.** `perfect_squares_kd_tree_priority_fill` clears the line by 239,476 points, or 0.05%.

## Programs whose stored or reported scores exceed our runs

- `gaussian_blur_placement` stores 545,031,007, the highest verified total in the collection, in its output files, which our 10-minute runs do not reach. `gaussian_blur` wrote nothing on `opera` and was not run on `lets_go_higher` within 10 minutes, so it is kept only as first on `charleston_road`.
- `scored_greedy_with_mst_backbone` stores 544,460,107 from per-instance parameter tuning with `param_tuning.py`. We ran the defaults.
- `HashCode2017Finals_stoman` reports 544,317,395, 13th in the final, and was removed. It is over budget on `opera` by 2 points in all 10 of our runs, and that one failure keeps it under the 5% line.
- `router_placement_hashcode2017_03xyhrytsiv` reports 545,820,170 and was removed: no code in it can produce a submission, so the number cannot be checked.

## What we did

1. **Collected.** 25 repositories, after the earlier non-solver prunes.
2. **Screened.** One run with a 5-minute limit, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/router_placement/judge.py`. A run whose output the judge rejects counts as 0. A program that timed out on a smaller instance skipped the larger ones.
3. **10-minute runs.** A program with no valid output at 5 minutes got a 10-minute run on the instances that lacked one.
4. **Repairs.** We added or fixed writers where the method existed but no valid file came out, and fixed the crashes above. Programs killed at the 3.5 GB memory limit got a retry at 6 GB.
5. **Full protocol.** A program advanced if it was in the top 3 or within 20% of the best on any instance, or in the top 3 by total. It then got 10 runs at a 10-minute limit, or 2 runs if it has no random choices, on the instances where the screen gave a valid score or a budget failure a new run could change.
6. **Selected.** A solver is kept if it is first on an instance by its best run, or if the sum of its means is at least 520,662,175. The others were deleted.
7. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods, and each README starts with a header giving the source and the method. The outputs in [output/](output/) come from the runs above and were not repeated after the move.

## Removed repositories

The scores are the best valid ones we got across a repository's programs. A dash means no valid output.

| Repository | charleston_road | rue_de_londres | opera | lets_go_higher | Sum of bests | Why it is out |
|---|---:|---:|---:|---:|---:|---|
| `HashCode2017Finals_stoman` | 21,895,654 | 58,039,083 | — | 287,800,467 | 367,735,204 | Over budget on `opera` in all 10 runs, by 2 points (94,862 against 94,860), so its sum of means is 367,735,204. It is not first on any instance. Its README reports 544,317,395 and 13th place, and a valid `opera` near the other programs' scores would put it over the line. |
| `HashCode2017Finals_PetarV-` | 21,962,223 | — | — | 290,119,097 | 312,081,320 | `newbackbone` and `farwall-greedy` go over budget on `rue_de_londres`, and `newbackbone` also on `opera`. `main.cpp` goes over budget or repeats routers on all four. `farwall` wrote nothing in 10 minutes. |
| `hash-code-2017_tardisman5197` | 21,959,496 | — | — | 289,817,942 | 311,777,438 | The shipped binary goes over budget on `rue_de_londres` and `opera`, and we had no Go toolchain, so the source was not rebuilt. Scores need our re-listing of the backbone cells. Its README reports valid scores on all four. |
| `hashcode_plietar` | 21,961,849 | 57,174,105 | 168,674,073 | — | 247,810,027 | First on no instance. It scores 168,674,073 on `opera` in a 10-minute run and runs out of memory on `lets_go_higher` at 6 GB. |
| `hashcode2018_DanieleMaisto` | 21,875,337 | 36,060,086 | 160,269,075 | 3,874,802 | 222,079,300 | Its stored outputs total 539,090,345, but `score_mst`, its method that scores by coverage, wrote nothing on `charleston_road` in 10 minutes. The faster modes score far lower, and `conv` puts a router on a wall on `rue_de_londres`. We updated removed NumPy and SciPy names. |
| `google-hashcode-2017_AntoineMrj` | 21,962,505 | — | — | — | 21,962,505 | Second on `charleston_road`, 28 behind `gaussian_blur`'s best run. Its README gives 50 minutes, 3 hours and 14 hours for the larger instances, and it wrote nothing on `rue_de_londres` or `opera` in 10 minutes. Its stored outputs total 538,766,392. `main.py` calls a price function that its module lacks, so we added it. |
| `RouterPlacement_PoddukinVladimir` | 21,961,639 | — | — | — | 21,961,639 | Windows console program. After our .NET 6 port it scores 21,961,639 on `charleston_road`, and it wrote nothing on `rue_de_londres` in 10 minutes, so the larger instances were not run. |
| `AI-Google-router-placement-optimization_ricardoyang00` | — | — | — | — | 0 | It has a GUI and no submission writer, so we added one. The judge rejects every output: the backbone cells are not connected. No output on `lets_go_higher` in 10 minutes. |
| `HashCodeFinals_Nicolas-Ding` | — | — | — | — | 0 | Not run: it has no submission writer. |
| `IA_routerPlacement_racoelhosilva` | — | — | — | — | 0 | No valid output on any instance in 10 minutes. |
| `Router-Placement_tasosxak` | — | — | — | — | 0 | Not run: it prints its result and never writes a submission. |
| `RouterPlacement_svalera99` | — | — | — | — | 0 | Writes an empty backbone section on `charleston_road` and `rue_de_londres`, and runs out of memory on `opera` at 3.5 GB. |
| `Router_Placement_Hyperion2023` | — | — | — | — | 0 | After our writer fix, the judge rejects its outputs: routers off the backbone on `charleston_road`, over budget on `rue_de_londres` and `opera`. No output on `lets_go_higher` in 10 minutes. |
| `hashcode-2017_lefreud` | — | — | — | — | 0 | Wrote nothing on `charleston_road`, the smallest instance, in 10 minutes. |
| `hashcode-2022-practice-round_HuzaifaIrfan-DSA` | — | — | — | — | 0 | A scorer only, with no solver to run. |
| `router_placement_hashcode2017_03xyhrytsiv` | — | — | — | — | 0 | Its README reports 545,820,170, but no code can reproduce that. `algorithm1` imports a `write_file` that does not exist, and `algorithm2` writes a map where a submission belongs, printing 20,839,862 on `charleston_road` by its own count. The reported per-instance values also look odd: `rue_de_londres` 65,187,137 and `opera` 199,394,735 are above every other score we saw. |

## What may understate a program

- **Programs were pinned to one core,** including OpenMP in `perfect_squares_kd_tree_priority_fill`.
- **The 10-minute limit stops several programs,** among them `gaussian_blur_placement`, `coverage_greedy_with_random_router_removal` on `lets_go_higher`, `AntoineMrj`, `DanieleMaisto` and `lefreud`.
- **We ran default parameters.** Tuned settings, like those behind `scored_greedy_with_mst_backbone`'s stored outputs, can score higher.
- **Invalid outputs count as 0,** even when the excess is small, as with `stoman`.
- **Setup changes.** Input paths were changed, or the input copied where programs expect it. `Poddukin` was moved to .NET 6 and `DanieleMaisto` to current NumPy and SciPy names. `ricardoyang00` and `Hyperion2023` got a submission writer or a writer fix.
- **Not run:** `Nicolas-Ding` and `tasosxak` have no submission writer, `HuzaifaIrfan-DSA` is only a scorer, and `cplex/test.cpp` in `scored_greedy_with_mst_backbone` needs a CPLEX license.
