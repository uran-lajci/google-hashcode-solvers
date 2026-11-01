# Router Placement

Google Hash Code 2017, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2017/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2017/final).

## Why only nine solvers

Nine solvers are kept out of 25 repositories. A solver is kept if it is first on an instance, or if the sum of its per-instance means is within 5% of the top team's total (at least 520,662,175, 95% of 548,065,447). Seven clear that line, and two more are first on an instance. Programs got a screen with one seed, and those that advanced got the full protocol. The full account is in [SOLVER_SELECTION.md](SOLVER_SELECTION.md). None needs a license, though one repository holds a CPLEX program we did not run.

## Collected solvers

9 solvers: 9 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/coverage_minus_cable_greedy`](solvers/coverage_minus_cable_greedy/) | C++ | Our runs: sum of means 542,187,100 |
| [`solvers/scored_greedy_with_mst_backbone`](solvers/scored_greedy_with_mst_backbone/) | C++ (+ Python parameter tuning) | Our runs: sum of means 539,137,647 |
| [`solvers/greedy_coverage_steiner_tree`](solvers/greedy_coverage_steiner_tree/) | C++ | Our runs: sum of means 539,104,228 |
| [`solvers/linked_list_coverage_greedy`](solvers/linked_list_coverage_greedy/) | Python 3 | Our runs: sum of means 537,740,092 |
| [`solvers/max_coverage_then_fill_greedy`](solvers/max_coverage_then_fill_greedy/) | C++ | Our runs: sum of means 537,507,292 |
| [`solvers/max_coverage_threshold_heuristic`](solvers/max_coverage_threshold_heuristic/) | PHP | Our runs: sum of means 527,115,014 |
| [`solvers/perfect_squares_kd_tree_priority_fill`](solvers/perfect_squares_kd_tree_priority_fill/) | C++ | Our runs: sum of means 520,901,651 |
| [`solvers/coverage_greedy_with_random_router_removal`](solvers/coverage_greedy_with_random_router_removal/) | C++ | Our runs: first on `opera` |
| [`solvers/gaussian_blur_placement`](solvers/gaussian_blur_placement/) | C++ | Our runs: first on `charleston_road` by best run |

### [`solvers/coverage_minus_cable_greedy/`](solvers/coverage_minus_cable_greedy/)

- **Source:** https://github.com/antonin-arquey/polyhash2017
- **Snapshot:** GitHub clone at commit `ad0bc2e` (history 2017-10-19 → 2018-01-13); `.git` removed on import.
- **Language:** C++
- **Approach:** Scores each cell by the targets a router there would cover, minus its distance to the nearest cable. Places the best router, links it to the nearest cable with diagonal steps, and updates the scores. Stops when the budget runs out.
- **Run:** In `Resolution/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve *.cpp`, then `./solve <input> <output>`.
- **Benchmark:** sum of means 542,187,100. ([scores](output/coverage_minus_cable_greedy/scores.md)).
- **Removed on import:** 12 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/scored_greedy_with_mst_backbone/`](solvers/scored_greedy_with_mst_backbone/)

- **Source:** https://github.com/matteojug/hashcode17_finals
- **Snapshot:** GitHub clone at commit `374c43f` (history 2017-03-31 → 2017-04-03); `.git` removed on import.
- **Language:** C++ (+ Python parameter tuning)
- **Approach:** Scores each cell by coverage, with weights for neighbouring walls and covered cells. Places the best router the budget allows, keeping an estimate of the cable cost. Rebuilds the backbone as a minimum spanning tree over the routers (`fix_backbone`) and continues with what is left of the budget. `param_tuning.py` searches the weights, and we ran the defaults. `cplex/test.cpp` needs a CPLEX license and was not run.
- **Run:** `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve main.cpp`, then `./solve charleston_road.in`, which writes `charleston_road.in.out`.
- **Benchmark:** sum of means 539,137,647. ([scores](output/scored_greedy_with_mst_backbone/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/greedy_coverage_steiner_tree/`](solvers/greedy_coverage_steiner_tree/)

- **Source:** https://github.com/amadoukane96/Google-HashCode-2017
- **Snapshot:** GitHub clone at commit `cbc418c` (2018-03-16); `.git` removed on import.
- **Language:** C++
- **Approach:** Places routers one at a time at the cell that covers the most targets, ignoring cable cost. Connects them with the Takahashi-Matsuyama Steiner tree heuristic. While over budget, drops the last router and rebuilds the tree.
- **Run:** In `GHC17/`: `g++ -std=c++17 -O2 -fpermissive -w -I. -ICSolver -ICReferee -ICReferee/modeles -ICTimer $(find . -name '*.cpp' | grep -v CTimer) -o solve`, then `./solve <input> <output>`.
- **Benchmark:** sum of means 539,104,228. We fixed three things for GCC. `maxm`, `minm` and `SPoint::min` in `SPoint.h` returned references to local variables, which crashed on Linux. `SCell::operator==` had no `return`. `CSolver.cpp` uses `std::filesystem` in place of the old experimental namespace. ([scores](output/greedy_coverage_steiner_tree/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/linked_list_coverage_greedy/`](solvers/linked_list_coverage_greedy/)

- **Source:** https://github.com/SebBerlioux/PolyHash
- **Snapshot:** GitHub clone at commit `12ec3f8` (history 2017-10-09 → 2017-12-10); `.git` removed on import.
- **Language:** Python 3
- **Approach:** Scores each cell by how many cells a router there would cover, and keeps the cells in a linked list ordered by that score. Places routers best-first, updating scores as it goes. Connects the routers to the backbone with a low-cost tree.
- **Run:** `python3 main.py <input> <output>`.
- **Benchmark:** sum of means 537,740,092. ([scores](output/linked_list_coverage_greedy/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/max_coverage_then_fill_greedy/`](solvers/max_coverage_then_fill_greedy/)

- **Source:** https://github.com/SimylinK/Google-HashCode-2017
- **Snapshot:** GitHub clone at commit `4e4d970` (2018-01-12); `.git` removed on import.
- **Language:** C++
- **Approach:** Places every router that can reach its maximum coverage area. Links those routers, each to the closest connected point. Fills the remaining gaps with more routers while the budget lasts.
- **Run:** In `googleHashCode2017/`: `g++ -std=c++17 -O2 -fpermissive -w *.cpp -o solve`, then `./solve charleston_road.in`, which writes `charleston_road.out`.
- **Benchmark:** sum of means 537,507,292. We fixed one thing for GCC. `distance` in `Coordinate.h` and `Coordinate.cpp` returned a reference to a local variable, which crashed on Linux. ([scores](output/max_coverage_then_fill_greedy/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/max_coverage_threshold_heuristic/`](solvers/max_coverage_threshold_heuristic/)

- **Source:** https://github.com/ottins/hashcode2017-finalround
- **Snapshot:** GitHub clone at commit `15f31cc` (history 2017-04-15 → 2017-04-15); `.git` removed on import.
- **Language:** PHP
- **Approach:** `router.php` places routers according to a `max_coverage` threshold, which its README says strongly affects run time. `maps/` shows the coverage reached on each instance.
- **Run:** With the instance in the current folder, `HC_INST=charleston_road php router.php`.
- **Benchmark:** sum of means 527,115,014. `router.php` now solves the one instance named by `HC_INST`, where it used to loop over all four. ([scores](output/max_coverage_threshold_heuristic/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/perfect_squares_kd_tree_priority_fill/`](solvers/perfect_squares_kd_tree_priority_fill/)

- **Source:** https://github.com/mihai-bontea/Google-Hash-Code-2017-Final-Round
- **Snapshot:** GitHub clone at commit `1124b2c` (history 2022-04-24 → 2026-05-18); `.git` removed on import.
- **Language:** C++
- **Approach:** Tiles perfect (2R+1) squares in spiral order. Connects each to the nearest connected cell with a k-d tree. Spends the remaining budget on the best spots from a parallel priority queue.
- **Run:** Needs the libkdtree++ headers, which the repository does not include (`libkdtree++-dev`). In `sol3/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -fopenmp -I/usr/include/kdtree++ -o solve main.cpp`, then, with the instance in the current folder, `HC_INST=charleston_road ./solve`.
- **Benchmark:** sum of means 520,901,651. `sol3/main.cpp` now reads the one instance named by `HC_INST` from the current folder and writes `sub_<instance>` there, where it used to loop over four fixed paths. ([scores](output/perfect_squares_kd_tree_priority_fill/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/coverage_greedy_with_random_router_removal/`](solvers/coverage_greedy_with_random_router_removal/)

- **Source:** https://github.com/AlexeyZhuravlev/hashcode-finals-2017
- **Snapshot:** GitHub clone at commit `1358404` (history 2017-04-01 → 2017-04-01); `.git` removed on import.
- **Language:** C++
- **Approach:** `aleksey.cpp` places routers greedily by the cells they newly cover. Runs 100 rounds of router removal with a random ratio between 0.5 and 1, and keeps the result when the score does not drop.
- **Run:** `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o aleksey aleksey.cpp`, then, with the instance in the current folder, `./aleksey charleston_road`, which writes `charleston_road.out`. The other programs in the folder were not kept for themselves.
- **Benchmark:** First on `opera`. ([scores](output/coverage_greedy_with_random_router_removal/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/gaussian_blur_placement/`](solvers/gaussian_blur_placement/)

- **Source:** https://github.com/Matsoy/hashcode2017-finalRound
- **Snapshot:** GitHub clone at commit `ea2c69f` (history 2017-10-19 → 2019-03-03); `.git` removed on import.
- **Language:** C++
- **Approach:** Convolves the target cells with a Gaussian kernel and places routers at the peaks. Connects them to the backbone. `random` and `bigcase` are the other methods in the same code. Only `gaussian_blur` was kept for itself, as first on `charleston_road`.
- **Run:** In `Strategie/Strategie/`: `g++ -std=c++17 -O2 -w -fpermissive -pthread -include bits/stdc++.h -o solve *.cpp`, then `./solve <input> <output>`.
- **Benchmark:** First on `charleston_road` by best run. `main.cpp` now builds the `gaussian_blur` method. It was set to `bigcase`, and the method is chosen by a string in that line. ([scores](output/gaussian_blur_placement/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

## Removed after benchmarking, or never added

The first 16 repositories were screened or examined on 2026-11-01 and then deleted from the collection (see *Why only nine solvers* above). The last 2 were never added.

- `AI-Google-router-placement-optimization_ricardoyang00` (https://github.com/ricardoyang00/AI-Google-router-placement-optimization): It has a GUI and no submission writer, so we added one. The judge rejects every output: the backbone cells are not connected. No output on `lets_go_higher` in 10 minutes.
- `HashCode2017Finals_PetarV-` (https://github.com/PetarV-/HashCode2017Finals): `newbackbone` and `farwall-greedy` go over budget on `rue_de_londres`, and `newbackbone` also on `opera`. `main.cpp` goes over budget or repeats routers on all four. `farwall` wrote nothing in 10 minutes.
- `HashCode2017Finals_stoman` (https://github.com/stoman/HashCode2017Finals): Over budget on `opera` in all 10 runs, by 2 points (94,862 against 94,860), so its sum of means is 367,735,204. It is not first on any instance. Its README reports 544,317,395 and 13th place, and a valid `opera` near the other programs' scores would put it over the line.
- `HashCodeFinals_Nicolas-Ding` (https://github.com/Nicolas-Ding/HashCodeFinals): Not run: it has no submission writer.
- `IA_routerPlacement_racoelhosilva` (https://github.com/racoelhosilva/IA_routerPlacement): No valid output on any instance in 10 minutes.
- `Router-Placement_tasosxak` (https://github.com/tasosxak/Router-Placement): Not run: it prints its result and never writes a submission.
- `RouterPlacement_PoddukinVladimir` (https://github.com/PoddukinVladimir/RouterPlacement): Windows console program. After our .NET 6 port it scores 21,961,639 on `charleston_road`, and it wrote nothing on `rue_de_londres` in 10 minutes, so the larger instances were not run.
- `RouterPlacement_svalera99` (https://github.com/svalera99/RouterPlacement): Writes an empty backbone section on `charleston_road` and `rue_de_londres`, and runs out of memory on `opera` at 3.5 GB.
- `Router_Placement_Hyperion2023` (https://github.com/Hyperion2023/Router_Placement): After our writer fix, the judge rejects its outputs: routers off the backbone on `charleston_road`, over budget on `rue_de_londres` and `opera`. No output on `lets_go_higher` in 10 minutes.
- `google-hashcode-2017_AntoineMrj` (https://github.com/AntoineMrj/google-hashcode-2017): Second on `charleston_road`, 28 behind `gaussian_blur`'s best run. Its README gives 50 minutes, 3 hours and 14 hours for the larger instances, and it wrote nothing on `rue_de_londres` or `opera` in 10 minutes. Its stored outputs total 538,766,392. `main.py` calls a price function that its module lacks, so we added it.
- `hash-code-2017_tardisman5197` (https://github.com/tardisman5197/hash-code-2017): The shipped binary goes over budget on `rue_de_londres` and `opera`, and we had no Go toolchain, so the source was not rebuilt. Scores need our re-listing of the backbone cells. Its README reports valid scores on all four.
- `hashcode-2017_lefreud` (https://github.com/lefreud/hashcode-2017): Wrote nothing on `charleston_road`, the smallest instance, in 10 minutes.
- `hashcode-2022-practice-round_HuzaifaIrfan-DSA` (https://github.com/HuzaifaIrfan-DSA/hashcode-2022-practice-round): A scorer only, with no solver to run.
- `hashcode2018_DanieleMaisto` (https://github.com/DanieleMaisto/hashcode2018): Its stored outputs total 539,090,345, but `score_mst`, its method that scores by coverage, wrote nothing on `charleston_road` in 10 minutes. The faster modes score far lower, and `conv` puts a router on a wall on `rue_de_londres`. We updated removed NumPy and SciPy names.
- `hashcode_plietar` (https://github.com/plietar/hashcode): First on no instance. It scores 168,674,073 on `opera` in a 10-minute run and runs out of memory on `lets_go_higher` at 6 GB.
- `router_placement_hashcode2017_03xyhrytsiv` (https://github.com/03xyhrytsiv/router_placement_hashcode2017): Its README reports 545,820,170, but no code can reproduce that. `algorithm1` imports a `write_file` that does not exist, and `algorithm2` writes a map where a submission belongs, printing 20,839,862 on `charleston_road` by its own count. The reported per-instance values also look odd: `rue_de_londres` 65,187,137 and `opera` 199,394,735 are above every other score we saw.
- `MantisMaestro/HashCode2017Final` (Go, `75da8f2`): unfinished. It tiles routers and prints how many it placed, but never connects them to the backbone or writes a submission.
- `flaxcode/Google-hashcode-solutions` (`28f4370`): README only, no code.

## Duplicates removed during import

- `YZ1GO/L.EIC029_IA_PRJ01` (GitHub, `5503169`): the same repository as `ricardoyang00/AI-Google-router-placement-optimization`, with identical history and files.
- `Kevogich/HashcodeFinal` (GitHub, `5f38985`): a re-upload, three days later, of `PetarV-/HashCode2017Finals`. All code files are byte-identical; it only adds a results screenshot and one README line.
- [Kevogich/HashcodeFinal](https://github.com/Kevogich/HashcodeFinal) (`5f38985`): same source code (after normalising line endings and whitespace) as `HashCode2017Finals_PetarV-`.
- [nquinquenel/polytech-hashcode-2017](https://github.com/nquinquenel/polytech-hashcode-2017) (`870a293`): same source code (after normalising line endings and whitespace) as `polyhash2017_antonin-arquey`.

## Official inputs removed

44 files in 9 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>solvers/coverage_greedy_with_random_router_removal</code> (4 files)</summary>

- `charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/coverage_minus_cable_greedy</code> (12 files)</summary>

- `Arbitre/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `Arbitre/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `Arbitre/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `Arbitre/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`
- `Executables/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `Executables/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `Executables/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `Executables/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`
- `Resolution/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `Resolution/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `Resolution/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `Resolution/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/gaussian_blur_placement</code> (4 files)</summary>

- `inputs/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `inputs/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `inputs/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `inputs/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/greedy_coverage_steiner_tree</code> (4 files)</summary>

- `input/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `input/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `input/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `input/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/linked_list_coverage_greedy</code> (4 files)</summary>

- `maps/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `maps/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `maps/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `maps/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/max_coverage_then_fill_greedy</code> (4 files)</summary>

- `inputAndOutput/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `inputAndOutput/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `inputAndOutput/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `inputAndOutput/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/max_coverage_threshold_heuristic</code> (4 files)</summary>

- `inputs/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `inputs/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `inputs/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `inputs/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/perfect_squares_kd_tree_priority_fill</code> (4 files)</summary>

- `input_files/charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `input_files/lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `input_files/opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `input_files/rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>

<details><summary><code>solvers/scored_greedy_with_mst_backbone</code> (4 files)</summary>

- `charleston_road.in` ← `archive/2017/final/hashcode_2017_final_round.in/charleston_road.in`
- `lets_go_higher.in` ← `archive/2017/final/hashcode_2017_final_round.in/lets_go_higher.in`
- `opera.in` ← `archive/2017/final/hashcode_2017_final_round.in/opera.in`
- `rue_de_londres.in` ← `archive/2017/final/hashcode_2017_final_round.in/rue_de_londres.in`

</details>
