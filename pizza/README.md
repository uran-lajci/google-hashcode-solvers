# Pizza

Google Hash Code 2017, Practice round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2017/practice](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2017/practice).

## Why eleven solvers

11 solvers are kept out of 294 repositories: the ten with the highest sum of per-instance means in our benchmark, and `guillotine_block_dynamic_programming`, which has the best `medium` result. There is no scoreboard for this practice round. 57 programs from 54 repositories came within 5% of the best sum of means, 959,187, because most are simple greedy programs that score close together, so only the top ten of those were kept. The tenth is 1.0% below the best. Programs got a screen with one seed, and those that advanced got the full protocol. The full account is in [SOLVER_SELECTION.md](SOLVER_SELECTION.md). Three repositories with programs that need a Gurobi or LocalSolver license stay in the folder, and those programs were not run.

## Collected solvers

14 solvers: 11 documented by hand (details below the tables) and 3 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/overlap_shrinking_largest_slice_greedy`](solvers/overlap_shrinking_largest_slice_greedy/) | C# | Our runs: sum of means 959,187 |
| [`solvers/two_pass_rectangle_cut`](solvers/two_pass_rectangle_cut/) | Rust | Our runs: sum of means 954,688 |
| [`solvers/first_fit_then_recut_slices`](solvers/first_fit_then_recut_slices/) | Python 2 | Our runs: sum of means 954,670 |
| [`solvers/distance_priority_queue_with_improvement`](solvers/distance_priority_queue_with_improvement/) | C++ | Our runs: sum of means 954,588 |
| [`solvers/shape_count_priority_with_recursive_repair`](solvers/shape_count_priority_with_recursive_repair/) | C | Our runs: sum of means 951,505 |
| [`solvers/smallest_piece_walk_then_expand`](solvers/smallest_piece_walk_then_expand/) | Python 3 | Our runs: sum of means 951,192 |
| [`solvers/filter_grow_up_greedy`](solvers/filter_grow_up_greedy/) | Java (+ filter generator) | Our runs: sum of means 950,801 |
| [`solvers/mask_then_grow_slices`](solvers/mask_then_grow_slices/) | Python 3 | Our runs: sum of means 950,217 |
| [`solvers/strategic_ingredient_smallest_slice_greedy`](solvers/strategic_ingredient_smallest_slice_greedy/) | Java | Our runs: sum of means 950,190 |
| [`solvers/priority_queue_slice_growth`](solvers/priority_queue_slice_growth/) | Java | Our runs: sum of means 949,185 |
| [`solvers/guillotine_block_dynamic_programming`](solvers/guillotine_block_dynamic_programming/) | C++ | Our runs: first on `medium` (49,998); nothing on `big` in 10 minutes |

### Imported in bulk

Folder names are `<repo>_<owner>`. Commit is the snapshot imported (`.git` removed); *Notes* quotes the first descriptive line of the repo's own README, unedited.

| Folder | Source | Commit (history) | Language | Notes |
|---|---|---|---|---|
| [`google-hash-code-solutions_jp172`](google-hash-code-solutions_jp172/) | [jp172/google-hash-code-solutions](https://github.com/jp172/google-hash-code-solutions) | `2d5f23c` (2020-02-24 → 2020-02-24, 1 commit) | C++ | Only part of a multi-problem repo: `warmup-pizza`. README: “In this repo I gradually add my solutions to various google hash code tasks I solved throughout the years. You can find the original problem statements and input data here.” |
| [`hashcode-2018_clemkoa`](hashcode-2018_clemkoa/) | [clemkoa/hashcode-2018](https://github.com/clemkoa/hashcode-2018) | `ab993cb` (2018-03-01 → 2018-03-01, 1 commit) | Python | Only part of a multi-problem repo: `pizza`. 4 official input copies removed (see list below). README: “Display command line syntax using python run.py -h” |
| [`hashcode_pizza_2018_yoann-dufresne`](hashcode_pizza_2018_yoann-dufresne/) | [yoann-dufresne/hashcode_pizza_2018](https://github.com/yoann-dufresne/hashcode_pizza_2018) | `bc5a889` (2018-02-20 → 2018-02-20, 1 commit) | Python | 4 official input copies removed (see list below). README: “Scores: example.in 15/15 small.in 42/42 medium.in 50 000/50 000 big.in 990 000/1 000 000” |

### [`solvers/overlap_shrinking_largest_slice_greedy/`](solvers/overlap_shrinking_largest_slice_greedy/)

- **Source:** https://github.com/sagishporer/hashcode-practice-pizza
- **Snapshot:** GitHub clone at commit `24fd18b` (2019-02-24); `.git` removed on import.
- **Language:** C#
- **Approach:** Scans for an unsliced cell and finds the largest valid slice that grows from it in all directions. The slice may overlap existing slices as long as what remains of them stays valid, and those slices are shrunk. Rescans the slices and retries growing them.
- **Run:** In `HashCode_Pizza/`: `dotnet build -c Release hc.csproj`, then `dotnet bin/Release/net6.0/hc.dll <input>`, which writes `<input>.out`.
- **Benchmark:** sum of means 959,187. `Program.cs` no longer saves a picture of the slices, which needs `System.Drawing`. We added `hc.csproj`, a .NET 6 project over the same sources, and renamed the old .NET Framework project file and `Properties/AssemblyInfo.cs` with `.old`. ([scores](output/overlap_shrinking_largest_slice_greedy/scores.md)).

### [`solvers/two_pass_rectangle_cut/`](solvers/two_pass_rectangle_cut/)

- **Source:** https://github.com/nappa85/HashCode2018
- **Snapshot:** GitHub clone at commit `ba1de98` (2018-03-08); `.git` removed on import.
- **Language:** Rust
- **Approach:** `cut` scans the free cells and saves the first valid rectangle from each. A second pass over the cells follows. It scores 954,688, against 942,563 for the PHP version in the same author's 2017 repository.
- **Run:** In `training/`: `cargo build --release`. Then, in `training/src/`: `../target/release/hash_code2018_training <input> <output>`.
- **Benchmark:** sum of means 954,688. ([scores](output/two_pass_rectangle_cut/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/first_fit_then_recut_slices/`](solvers/first_fit_then_recut_slices/)

- **Source:** https://github.com/mozanunal/NOP_HashCode2017
- **Snapshot:** GitHub clone at commit `a9d629d` (2017-07-19); `.git` removed on import.
- **Language:** Python 2
- **Approach:** `trycreateSlice` commits the first valid slice from each free cell. `calculate` then takes each slice back and tries variants around it, keeping valid ones.
- **Run:** Python 2. In `practice/`, with the instance copied to `medium.in`: `pypy practice.py`, which writes `medium.txt`.
- **Benchmark:** sum of means 954,670. ([scores](output/first_fit_then_recut_slices/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/distance_priority_queue_with_improvement/`](solvers/distance_priority_queue_with_improvement/)

- **Source:** https://github.com/GaspareG/HashCode-Practice
- **Snapshot:** GitHub clone at commit `a085a99` (2018-02-25); `.git` removed on import.
- **Language:** C++
- **Approach:** Scores each cell by how far it is from the nearest of each ingredient (`flood`) and keeps cells in a priority queue. Cuts slices in that order (`trovaSoluzioni`). Runs 5,000 improvement passes (`migliora`) that grow the slices.
- **Run:** `g++ -O2 lontano.cpp`, then `./a.out < <input> > <output>`.
- **Benchmark:** sum of means 954,588. ([scores](output/distance_priority_queue_with_improvement/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/shape_count_priority_with_recursive_repair/`](solvers/shape_count_priority_with_recursive_repair/)

- **Source:** https://github.com/RobertObkircher/pizza
- **Snapshot:** GitHub clone at commit `1021606` (2019-01-29); `.git` removed on import.
- **Language:** C
- **Approach:** Counts the valid shapes at each cell and places slices where options are fewest. `solve_recursive` then tries combinations around the leftover cells to raise the score.
- **Run:** In `src/`: `gcc -O2 main.c -lm`. With the four instances at `inputs/a_example.in`, `inputs/b_small.in`, `inputs/c_medium.in` and `inputs/d_big.in`, `./a.out` writes `inputs/<name>.out` for each.
- **Benchmark:** sum of means 951,505. ([scores](output/shape_count_priority_with_recursive_repair/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/smallest_piece_walk_then_expand/`](solvers/smallest_piece_walk_then_expand/)

- **Source:** https://github.com/vboiko-gt/HashCode2019_UNIT_Train
- **Snapshot:** GitHub clone at commit `5c54dca` (2019-02-24); `.git` removed on import.
- **Language:** Python 3
- **Approach:** Sorts the pieces by area and walks the pizza placing the first that fits (`walk_pizza`). `razpanah` then expands the placed pieces into free cells.
- **Run:** With the instances at `a_example.in`, `b_small.in`, `c_medium.in` and `d_big.in`: `python3 main.py`, which writes `<name>.out` for each.
- **Benchmark:** sum of means 951,192. ([scores](output/smallest_piece_walk_then_expand/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/filter_grow_up_greedy/`](solvers/filter_grow_up_greedy/)

- **Source:** https://github.com/msagi/hash-code-2018-test
- **Snapshot:** GitHub clone at commit `47dab69` (2018-02-27); `.git` removed on import.
- **Language:** Java (+ filter generator)
- **Approach:** `GrowUpAlgorithm` slides shape filters of each size over the pizza in row order, smallest first, to place slices. Then grows the placed slices into free cells.
- **Run:** Compile the sources under `src/main/java/` with `javac`, then `java com.msagi.hashcode.pizza.Main <input>`, which prints the submission.
- **Benchmark:** sum of means 950,801. ([scores](output/filter_grow_up_greedy/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/mask_then_grow_slices/`](solvers/mask_then_grow_slices/)

- **Source:** https://github.com/mcieno/HashCode
- **Snapshot:** GitHub clone at commit `63156a7` (2022-03-01); `.git` removed on import.
- **Language:** Python 3
- **Approach:** `mask` marks valid slices over the pizza using shapes from the factor list of each size. `grow` extends each slice in every direction while the size limit allows.
- **Run:** In `18-Pizza/`: `python3 solution.py <input>`, which prints the submission.
- **Benchmark:** sum of means 950,217. ([scores](output/mask_then_grow_slices/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/strategic_ingredient_smallest_slice_greedy/`](solvers/strategic_ingredient_smallest_slice_greedy/)

- **Source:** https://github.com/ROMBTeam/hashcode-practice-pizza
- **Snapshot:** GitHub clone at commit `737acb2` (2017-01-27); `.git` removed on import.
- **Language:** Java
- **Approach:** Finds the "strategic" ingredient, the scarcer one. At each free cell it lists the valid slices, keeps those with the least of that ingredient, and takes the smallest. Then extends slices where it can.
- **Run:** Compile `pizza-slicer/src/` with `javac`, then `java romb.pizza.slicer.Cutter <input>`, which writes `commands.txt` in the current folder.
- **Benchmark:** sum of means 950,190. ([scores](output/strategic_ingredient_smallest_slice_greedy/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/priority_queue_slice_growth/`](solvers/priority_queue_slice_growth/)

- **Source:** https://github.com/Lrakulka/Jams
- **Snapshot:** GitHub clone at commit `88f0ef2` (2019-04-21); `.git` removed on import.
- **Language:** Java
- **Approach:** At each free cell, a priority queue holds candidate slices. `addLargeSlices` adds right and bottom extensions until a valid slice comes out.
- **Run:** Compile `src/` with `javac`, then `java pizza.PizzaSlicer < <input> > <output>`.
- **Benchmark:** sum of means 949,185. `src/util/` adds `InputData`, `OutputData` and `ProblemDataIO`, which the code imports but the repository does not include. ([scores](output/priority_queue_slice_growth/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`solvers/guillotine_block_dynamic_programming/`](solvers/guillotine_block_dynamic_programming/)

- **Source:** https://github.com/ClementChouteau/Hashcode-2018-entrainement
- **Snapshot:** GitHub clone at commit `5150ab2` (2018-03-06); `.git` removed on import.
- **Language:** C++
- **Approach:** `progdyn_bloc.cpp` splits the pizza into 100-by-100 blocks and solves each block on its own. For each sub-rectangle of a block, the best covered area is the whole rectangle if it is a valid slice, and otherwise the best sum over every horizontal or vertical cut into two parts. The results are memoized over all sub-rectangles. It then rebuilds the slices from the table. `big` has 100 blocks, and it wrote nothing there in 10 minutes. `glouton.cpp` in the same folder is a greedy that cuts the largest rectangle that fits at each cell. It is within 5% (943,880) but ranked 19th, so it is not kept for itself. `progdyn.cpp` is an earlier version without blocks.
- **Run:** `g++ -O2 progdyn_bloc.cpp`, then `./a.out < <input> > <output>`.
- **Benchmark:** first on `medium` (49,998); nothing on `big` in 10 minutes. ([scores](output/guillotine_block_dynamic_programming/scores.md)).
- **Removed on import:** 4 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

## Removed after benchmarking

These 280 repositories were screened or examined on 2026-11-01 and 2026-11-02 and then deleted from the collection (see *Why eleven solvers* above). *Screen* is one run per instance at a 5-minute limit. *Full protocol* is 2 or 10 runs at 10 minutes. A machine restart on 2026-11-02 lost the per-repository records of programs that totalled less than 869,709 at the screen and of programs that gave no valid output, so *No record* means one of those two. Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has the scores.

- `-Practise-Round-GoogleHashCode2017_krzysiekprzekwas` (https://github.com/krzysiekprzekwas/-Practise-Round-GoogleHashCode2017): Screen: small 40, invalid output on `medium`, invalid output on `big`.
- `42Robo-food_snugdad` (https://github.com/snugdad/42Robo-food): No record.
- `G-hashcode-trial_Thanerik` (https://github.com/Thanerik/G-hashcode-trial): Screen and a 10-minute run: no valid output on `small`, out of memory on `medium` at 6 GB, out of memory on `big` at 6 GB.
- `GHC2018_C-ka_mrtncls` (https://github.com/mrtncls/GHC2018_C-ka): Screen: invalid output on `small`, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `big` (809,816).
- `GHC_Practice2017_Pizza_TedevFR` (https://github.com/TedevFR/GHC_Practice2017_Pizza): Within 5%, with a sum of means of 929,494, but ranked 47 of 54, below the top ten. Its stored outputs total 929,494.
- `Google-Hackathon-HashCode-2017-PizzaSubmition_DenysPodanenko` (https://github.com/DenysPodanenko/Google-Hackathon-HashCode-2017-PizzaSubmition): No record. Its stored outputs total 764,091.
- `Google-Hash-Code-2018-Practice-Problem_mihai-bontea` (https://github.com/mihai-bontea/Google-Hash-Code-2018-Practice-Problem): No record.
- `Google-Hash-Code-Pizza-Problem-2017_Alexandru-Dascalu` (https://github.com/Alexandru-Dascalu/Google-Hash-Code-Pizza-Problem-2017): Screen: totals 877,388 (small 35, medium 46,905, big 830,448).
- `Google-Hash-Code-Pizza_Mroziek` (https://github.com/Mroziek/Google-Hash-Code-Pizza): Within 5%, with a sum of means of 933,258, but ranked 40 of 54, below the top ten. Its stored outputs total 933,258.
- `Google-Hash-Code-Pizza_ilie05` (https://github.com/ilie05/Google-Hash-Code-Pizza): Within 5%, with a sum of means of 935,560, but ranked 33 of 54, below the top ten.
- `Google-HashCode-2017-preparation_AdrianMrn` (https://github.com/AdrianMrn/Google-HashCode-2017-preparation): No record.
- `Google-HashCode-2018-Test-Round_JGShaw` (https://github.com/JGShaw/Google-HashCode-2018-Test-Round): No record.
- `Google-HashCode-2019_mihailhernandez` (https://github.com/mihailhernandez/Google-HashCode-2019): No record.
- `Google-HashCode-Pizza-Problem_ntedgi` (https://github.com/ntedgi/Google-HashCode-Pizza-Problem): No record.
- `Google-HashCode2019_raviautar` (https://github.com/raviautar/Google-HashCode2019): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `Google-HashCode_danicrg` (https://github.com/danicrg/Google-HashCode): Within 5%, with a sum of means of 945,136, but ranked 14 of 54, below the top ten. Its stored outputs total 945,463.
- `Google-HashCodes-Pizza-Cutter_darraghmerrick` (https://github.com/darraghmerrick/Google-HashCodes-Pizza-Cutter): No record.
- `Google-Hash_AlexBlandin` (https://github.com/AlexBlandin/Google-Hash): Its stored outputs total 930,955, above the line. Its writer needed two fixes from us, after which it scored 37 on small and 40,044 on medium, and it did not finish `big` within the time limit, even with 6 GB.
- `Google-Hashcode-2019_QTimort` (https://github.com/QTimort/Google-Hashcode-2019): No record.
- `Google-Hashcode-Pizza-Problem-Solution_konradbachusz-zz` (https://github.com/konradbachusz-zz/Google-Hashcode-Pizza-Problem-Solution): Within 5%, with a sum of means of 912,802, but ranked 54 of 54, below the top ten. Its stored outputs total 912,802.
- `GoogleHashCode-Pizza_TheBoomBoxer` (https://github.com/TheBoomBoxer/GoogleHashCode-Pizza): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes.
- `GoogleHashCode2017_LyashenkoGS` (https://github.com/LyashenkoGS/GoogleHashCode2017): Screen and a 10-minute run: small 28, no valid output on `medium`, no valid output on `big`.
- `GoogleHashCode2019_spanoselias` (https://github.com/spanoselias/GoogleHashCode2019): Screen: totals 877,212 (small 30, medium 46,934, big 830,248).
- `GoogleHashCodePizza2019_sklipnoty` (https://github.com/sklipnoty/GoogleHashCodePizza2019): Screen: small 41, medium 39,792, no output on `big` in 5 minutes. It stores valid outputs only for `small` (36) and `medium` (39,720).
- `GoogleHashCodePizzaProblem_klyse` (https://github.com/klyse/GoogleHashCodePizzaProblem): No record.
- `GoogleHashCodePizza_sklipnoty` (https://github.com/sklipnoty/GoogleHashCodePizza): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`.
- `GoogleHashCodeTestRound_Loniowsky` (https://github.com/Loniowsky/GoogleHashCodeTestRound): Within 5%, with a sum of means of 943,104, but ranked 24 of 54, below the top ten.
- `GoogleHashCode_PizzaCutter_Gituser143` (https://github.com/Gituser143/GoogleHashCode_PizzaCutter): Screen: totals 869,709 (small 30, medium 46,233, big 823,446). Its stored outputs total 869,709.
- `GoogleHashCode_Pizza_2019_Jordilg13` (https://github.com/Jordilg13/GoogleHashCode_Pizza_2019): Full protocol: `mainPizza.py` has a sum of means of 905,892 (small 41, medium 47,490, big 858,361), below 911,228.
- `GoogleHashcode2017_davidmather` (https://github.com/davidmather/GoogleHashcode2017): No record.
- `GoogleHashcode2019_AselKitulagoda` (https://github.com/AselKitulagoda/GoogleHashcode2019): No record. It stores valid outputs only for `small` (35) and `big` (15,274).
- `GooglePizza_Gonthar` (https://github.com/Gonthar/GooglePizza): No record.
- `GooglePizza_linnykoleh` (https://github.com/linnykoleh/GooglePizza): No record. It stores valid outputs only for `small` (40).
- `Google_HashCode-2019_madilraza` (https://github.com/madilraza/Google_HashCode-2019): No record.
- `Google_HashCode_PizzaSlicing_iwih` (https://github.com/iwih/Google_HashCode_PizzaSlicing): Its stored outputs total 935,588, above the line, but it ran out of memory on `big` (small 40, medium 47,932, both at the time limit).
- `Google_Hashcode_2018_Pizza_Practice_shemetz` (https://github.com/shemetz/Google_Hashcode_2018_Pizza_Practice): Within 5%, with a sum of means of 947,948, but ranked 11 of 54, below the top ten. Its stored outputs total 951,698.
- `Google_Hashcode_Pizza_Dart_hussien4321` (https://github.com/hussien4321/Google_Hashcode_Pizza_Dart): No record. Its stored outputs total 816,330.
- `Google_Hashcode_pizza_problem_solution_YacovAverbuch` (https://github.com/YacovAverbuch/Google_Hashcode_pizza_problem_solution): Within 5%, with a sum of means of 913,274, but ranked 53 of 54, below the top ten. Its stored outputs total 950,693.
- `Google_Pizza_Hash_Code_anisayari` (https://github.com/anisayari/Google_Pizza_Hash_Code): No record.
- `Google_Pizza_Hash_Code_elados93` (https://github.com/elados93/Google_Pizza_Hash_Code): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes.
- `Google_hashcode_2019_anstadnik` (https://github.com/anstadnik/Google_hashcode_2019): No record.
- `HGC.slicePizza_DamCarduner` (https://github.com/DamCarduner/HGC.slicePizza): No record.
- `Hash-Code-2017-Practice-Test-Pizza-Problem-_TeamLS` (https://github.com/TeamLS/Hash-Code-2017-Practice-Test-Pizza-Problem-): No record. Its stored outputs total 560,789.
- `Hash-Code-Pizza-Practice-Round-_gheorghe-sava` (https://github.com/gheorghe-sava/Hash-Code-Pizza-Practice-Round-): Within 5%, with a sum of means of 932,254, but ranked 44 of 54, below the top ten.
- `HashCode-2017-Pizza_shaharalgaby` (https://github.com/shaharalgaby/HashCode-2017-Pizza): No record.
- `HashCode-2017_InfinityCollaborations` (https://github.com/InfinityCollaborations/HashCode-2017): Screen and a 10-minute run: small 28, no valid output on `medium`, no valid output on `big`. Best of 2 programs. Its stored outputs total 444,595.
- `HashCode-2017_Nasvera` (https://github.com/Nasvera/HashCode-2017): No record.
- `HashCode-2018-Practice_Oliver-Binns` (https://github.com/Oliver-Binns/HashCode-2018-Practice): No record.
- `HashCode-Pizza-IM_ShambaC` (https://github.com/ShambaC/HashCode-Pizza-IM): No record.
- `HashCode-Pizza_GhostPoro` (https://github.com/GhostPoro/HashCode-Pizza): No record.
- `HashCode-Pratice-2017_Ghoul-SSZ` (https://github.com/Ghoul-SSZ/HashCode-Pratice-2017): No record.
- `HashCode-Train1-2018_victorspgl` (https://github.com/victorspgl/HashCode-Train1-2018): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`.
- `HashCode-Training-Problem_bartoszmodelski` (https://github.com/bartoszmodelski/HashCode-Training-Problem): No record. It stores valid outputs only for `small` (30).
- `HashCode-Warmup-2019_jueyaye` (https://github.com/jueyaye/HashCode-Warmup-2019): No record.
- `HashCode2017-practiseProblem_fgadea` (https://github.com/fgadea/HashCode2017-practiseProblem): No record.
- `HashCode2017PizzaSlider_Onurus` (https://github.com/Onurus/HashCode2017PizzaSlider): Screen: small 30, invalid output on `medium`, invalid output on `big`. Its stored outputs total 77,334.
- `HashCode2017Pizza_ChrisBertrand` (https://github.com/ChrisBertrand/HashCode2017Pizza): Screen: small 27, invalid output on `medium`, invalid output on `big`.
- `HashCode2017Warmup_stoman` (https://github.com/stoman/HashCode2017Warmup): No record. It stores valid outputs only for `small` (42).
- `HashCode2017_DanielGorlo` (https://github.com/DanielGorlo/HashCode2017): No record.
- `HashCode2017_Fellfalla` (https://github.com/Fellfalla/HashCode2017): No record.
- `HashCode2017_Pizza_NetBeans_baluteam` (https://github.com/baluteam/HashCode2017_Pizza_NetBeans): No record. Its stored outputs total 616,500.
- `HashCode2017_Pizza_ParisKitty` (https://github.com/ParisKitty/HashCode2017_Pizza): No record.
- `HashCode2017_Practice_ITSMarchi` (https://github.com/ITSMarchi/HashCode2017_Practice): No record.
- `HashCode2017_WilliamMajanja-zz` (https://github.com/WilliamMajanja-zz/HashCode2017): No record.
- `HashCode2017_YaZko` (https://github.com/YaZko/HashCode2017): No record.
- `HashCode2017_ferquinz` (https://github.com/ferquinz/HashCode2017): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes.
- `HashCode2017_mariaBianca` (https://github.com/mariaBianca/HashCode2017): No record.
- `HashCode2017_nappa85` (https://github.com/nappa85/HashCode2017): Within 5%, with a sum of means of 942,563, but ranked 26 of 54, below the top ten. Its stored outputs total 942,563.
- `HashCode2018Pizza_gdgbologna` (https://github.com/gdgbologna/HashCode2018Pizza): Within 5%, with a sum of means of 929,539, but ranked 46 of 54, below the top ten. Its stored outputs total 929,497.
- `HashCode2018Warmup_stoman` (https://github.com/stoman/HashCode2018Warmup): No record. It stores valid outputs only for `small` (42).
- `HashCode2018_GioVAX` (https://github.com/GioVAX/HashCode2018): Within 5%, with a sum of means of 933,278, but ranked 39 of 54, below the top ten.
- `HashCode2018_JimNero009` (https://github.com/JimNero009/HashCode2018): Screen: small 36, medium 3,331, no output on `big` in 5 minutes.
- `HashCode2018_matteoformenti` (https://github.com/matteoformenti/HashCode2018): Within 5%, with a sum of means of 932,932, but ranked 42 of 54, below the top ten. Its stored outputs total 932,932.
- `HashCode2019PracticeProblem_CoffeeVector` (https://github.com/CoffeeVector/HashCode2019PracticeProblem): Within 5%, with a sum of means of 933,040, but ranked 41 of 54, below the top ten. Its stored outputs total 933,040.
- `HashCode2019_bshishov` (https://github.com/bshishov/HashCode2019): No record.
- `HashCode2019_clemsage` (https://github.com/clemsage/HashCode2019): Screen: small 28, invalid output on `medium`, invalid output on `big`.
- `HashCode2019_idyczko` (https://github.com/idyczko/HashCode2019): No record.
- `HashCode2019train_kirmartynov` (https://github.com/kirmartynov/HashCode2019train): Within 5%, with a sum of means of 939,884, but ranked 27 of 54, below the top ten.
- `HashCode2021_KrutikaBhatt` (https://github.com/KrutikaBhatt/HashCode2021): No record. It stores valid outputs only for `small` (20).
- `HashCodePizza_Brostafa` (https://github.com/Brostafa/HashCodePizza): No record.
- `HashCodePizza_EddyCerpa` (https://github.com/EddyCerpa/HashCodePizza): Screen and a 10-minute run: small 42, no valid output on `medium`, no output on `big` in 10 minutes.
- `HashCodePizza_JoaquinTrinanes` (https://github.com/JoaquinTrinanes/HashCodePizza): Screen: small 32, medium 46,086, no output on `big` in 5 minutes.
- `HashCodePizza_JoseLlorensRipolles` (https://github.com/JoseLlorensRipolles/HashCodePizza): No record.
- `HashCodePizza_Nikoloutsos` (https://github.com/Nikoloutsos/HashCodePizza): No record.
- `HashCodePizza_RustamZakAs` (https://github.com/RustamZakAs/HashCodePizza): No record.
- `HashCodePizza_Taity-mini` (https://github.com/Taity-mini/HashCodePizza): No record.
- `HashCodePizza_boyski33` (https://github.com/boyski33/HashCodePizza): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `HashCodePizza_peterjgill` (https://github.com/peterjgill/HashCodePizza): Within 5%, with a sum of means of 943,532, but ranked 23 of 54, below the top ten. Its stored outputs total 943,532.
- `HashCodePizza_wdaniel1993` (https://github.com/wdaniel1993/HashCodePizza): No record.
- `HashCodePractice2016_FantastiCode` (https://github.com/FantastiCode/HashCodePractice2016): No record.
- `HashCodePracticeProblem2019_JoseIgnacioRetamalThomsen` (https://github.com/JoseIgnacioRetamalThomsen/HashCodePracticeProblem2019): Screen: small 30, invalid output on `medium`, invalid output on `big`.
- `HashCodePratice2017_DropAllTables-bkp` (https://github.com/DropAllTables-bkp/HashCodePratice2017): No record.
- `HashCodeProblem2018_joseffffff` (https://github.com/joseffffff/HashCodeProblem2018): No record.
- `HashCodeQual2019_siowmeng` (https://github.com/siowmeng/HashCodeQual2019): No record. It stores valid outputs only for `medium` (39,603).
- `HashCode_2017_practice_round_slaby93` (https://github.com/slaby93/HashCode_2017_practice_round): No record.
- `HashCode_HillaShx` (https://github.com/HillaShx/HashCode): No record.
- `HashCode_Pizza_karolkozak` (https://github.com/karolkozak/HashCode_Pizza): No record. Its stored outputs total 908,813.
- `HashCode_arora-aditya` (https://github.com/arora-aditya/HashCode): No record.
- `HashCode_kartsridhar` (https://github.com/kartsridhar/HashCode): No record.
- `HashCode_mohsenTalal` (https://github.com/mohsenTalal/HashCode): A renamed copy of `hashcode-practice-pizza_sagishporer`, which is kept as `overlap_shrinking_largest_slice_greedy`. About 91% of its code tokens match, it scores the same on every instance (959,187), and `sagishporer`'s single commit is a year older (2019-02-24, against 2020-02-14) and documents the method.
- `HashPizza_kosyonikolov` (https://github.com/kosyonikolov/HashPizza): No record.
- `Hashcode-2018_brkn` (https://github.com/brkn/Hashcode-2018): No record.
- `Hashcode-Pizza_muffin-coders` (https://github.com/muffin-coders/Hashcode-Pizza): No record.
- `Hashcode2018-Preparation_GambuzX` (https://github.com/GambuzX/Hashcode2018-Preparation): No record.
- `Hashcode2018_zazizizou` (https://github.com/zazizizou/Hashcode2018): No record.
- `Hashcode2018kapson_KapsonLabs` (https://github.com/KapsonLabs/Hashcode2018kapson): No record.
- `Hashcode2019Practice_pzierahn` (https://github.com/pzierahn/Hashcode2019Practice): No record.
- `Hashcode2019_mcamila777` (https://github.com/mcamila777/Hashcode2019): No record.
- `HashcodePizza_andresescobarcotan` (https://github.com/andresescobarcotan/HashcodePizza): No record.
- `HashcodePizza_nullhtp` (https://github.com/nullhtp/HashcodePizza): Screen: small 37, medium 47,680, no output on `big` in 5 minutes.
- `Hashcode_practice_2019_tieberthomas` (https://github.com/tieberthomas/Hashcode_practice_2019): No record.
- `Pizza-GoogleHashCode2018_joshiraez` (https://github.com/joshiraez/Pizza-GoogleHashCode2018): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`.
- `Pizza-HashCode_MahmoudMabrok` (https://github.com/MahmoudMabrok/Pizza-HashCode): No record. It stores valid outputs only for `big` (665,622).
- `Pizza-HashCode_diegologs` (https://github.com/diegologs/Pizza-HashCode): No record.
- `Pizza-HashCode_jesusjimsa` (https://github.com/jesusjimsa/Pizza-HashCode): No record.
- `Pizza-Hashcode-Example-2018_titusmann` (https://github.com/titusmann/Pizza-Hashcode-Example-2018): No record. Its stored outputs total 196,422.
- `Pizza-Problem_mrknockturnal` (https://github.com/mrknockturnal/Pizza-Problem): No record.
- `Pizza-WarmUp_MadonnasPlays` (https://github.com/MadonnasPlays/Pizza-WarmUp): Screen: small 2, invalid output on `medium`, invalid output on `big`.
- `PizzaCutter_Mikeywalsh` (https://github.com/Mikeywalsh/PizzaCutter): Its stored outputs total 935,791, above the line, but it wrote nothing on `big` within the time limit (small 42, medium 48,261).
- `PizzaHashCode2018BruteforceSolution_abaft` (https://github.com/abaft/PizzaHashCode2018BruteforceSolution): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `PizzaHashCode_Belterius` (https://github.com/Belterius/PizzaHashCode): No record.
- `PizzaProblem_gitaumoses4` (https://github.com/gitaumoses4/PizzaProblem): Screen: small 27, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `small` (27) and `medium` (1,860).
- `PizzaProblem_martinajir` (https://github.com/martinajir/PizzaProblem): No record.
- `PizzaSlicer_sachinjegaonkar` (https://github.com/sachinjegaonkar/PizzaSlicer): No record. It stores valid outputs only for `small` (30).
- `Pizza_HASH_CODE_vuslysty` (https://github.com/vuslysty/Pizza_HASH_CODE): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes.
- `Pizza_Problem_AcoffeePlease` (https://github.com/AcoffeePlease/Pizza_Problem): Within 5%, with a sum of means of 943,965, but ranked 17 of 54, below the top ten. Its stored outputs total 943,965.
- `Pizza_Ratchet-Studios` (https://github.com/Ratchet-Studios/Pizza): No record.
- `Pizza_Tifzou` (https://github.com/Tifzou/Pizza): No record.
- `Pizza_adamjin` (https://github.com/adamjin/Pizza): No record.
- `Pizza_alexdoloz` (https://github.com/alexdoloz/Pizza): No record.
- `Pizza_danielfleischer` (https://github.com/danielfleischer/Pizza): No record.
- `Pizza_itcherry` (https://github.com/itcherry/Pizza): No record.
- `Pizza_mehmetbarisyaman` (https://github.com/mehmetbarisyaman/Pizza): No record.
- `Pizza_pysergio` (https://github.com/pysergio/Pizza): Within 5%, with a sum of means of 929,494, but ranked 48 of 54, below the top ten. Its stored outputs total 929,504.
- `Pizza_yoann-dufresne` (https://github.com/yoann-dufresne/Pizza): No record.
- `Problem-Statement-Pizza-Hash-Code-0xZBV_3_VigHub` (https://github.com/VigHub/Problem-Statement-Pizza-Hash-Code-0xZBV_3): Within 5%, with a sum of means of 946,711, but ranked 13 of 54, below the top ten. Its stored outputs total 946,711.
- `StreamingVideos-GoogleHashCode2017_huybthomas` (https://github.com/huybthomas/StreamingVideos-GoogleHashCode2017): Screen: totals 890,761 (small 38, medium 47,381, big 843,342).
- `The-Pizza-Problem_RubinDaija` (https://github.com/RubinDaija/The-Pizza-Problem): Within 5%, with a sum of means of 922,911, but ranked 50 of 54, below the top ten.
- `The-Pizza-Problem_SimonIyamu` (https://github.com/SimonIyamu/The-Pizza-Problem): No record.
- `crHackers_manuelsalvadori` (https://github.com/manuelsalvadori/crHackers): No record.
- `ghc-pizza-problem_bboron86` (https://github.com/bboron86/ghc-pizza-problem): Within 5%, with a sum of means of 931,496, but ranked 45 of 54, below the top ten.
- `ghc-pizza_yumin-chen` (https://github.com/yumin-chen/ghc-pizza): No record.
- `google-code-hash-pizza_augerm` (https://github.com/augerm/google-code-hash-pizza): No record.
- `google-hash-code-2017-task_nikitaeverywhere` (https://github.com/nikitaeverywhere/google-hash-code-2017-task): Within 5%, with a sum of means of 918,504, but ranked 52 of 54, below the top ten. Its stored outputs total 919,174.
- `google-hash-code-2018-test_AleksandrChernyavenko` (https://github.com/AleksandrChernyavenko/google-hash-code-2018-test): Screen: small 20, invalid output on `medium`, invalid output on `big`. Its stored outputs total 876,370.
- `google-hash-code-pizza_islam-aymann` (https://github.com/islam-aymann/google-hash-code-pizza): No record.
- `google-hash-code-pizza_uran-lajci` (https://github.com/uran-lajci/google-hash-code-pizza): Within 5%, with a sum of means of 943,699, but ranked 21 of 54, below the top ten. Its stored outputs total 959,605.
- `google-hashcode-19_jaracoder` (https://github.com/jaracoder/google-hashcode-19): No record.
- `google-hashcode-2017_PieterDr` (https://github.com/PieterDr/google-hashcode-2017): No record.
- `google-hashcode-2018_slimcdk` (https://github.com/slimcdk/google-hashcode-2018): No record.
- `google-hashcode-2019_mohantejach` (https://github.com/mohantejach/google-hashcode-2019): Within 5%, with a sum of means of 933,278, but ranked 38 of 54, below the top ten. Its stored outputs total 933,278.
- `google-hashcode-pizza-problem_alessandro1105` (https://github.com/alessandro1105/google-hashcode-pizza-problem): Within 5%, with a sum of means of 943,706, but ranked 20 of 54, below the top ten. Its stored outputs total 943,706.
- `google-hashcode-pizza-problem_lindskogen` (https://github.com/lindskogen/google-hashcode-pizza-problem): No record.
- `google-hashcode-pizza-solution_nikpundik` (https://github.com/nikpundik/google-hashcode-pizza-solution): Within 5%, with a sum of means of 933,289, but ranked 37 of 54, below the top ten. Its stored outputs total 933,289.
- `google-hashcode-pizza-solution_stuffrome` (https://github.com/stuffrome/google-hashcode-pizza-solution): Screen and a 10-minute run: small 42, no valid output on `medium`, no output on `big` in 10 minutes.
- `google-hashcode-pizza_arturo-source` (https://github.com/arturo-source/google-hashcode-pizza): Screen and a 10-minute run: small 42, no valid output on `medium`, out of memory on `big` at 6 GB.
- `google-hashcode-pizza_mindfulme` (https://github.com/mindfulme/google-hashcode-pizza): No record.
- `google-hashcode_AndreFCruz` (https://github.com/AndreFCruz/google-hashcode): Within 5%, with a sum of means of 943,699, but ranked 22 of 54, below the top ten.
- `google-hashcode_flobilosaurus` (https://github.com/flobilosaurus/google-hashcode): No record.
- `google-hashcode_hex7c0` (https://github.com/hex7c0/google-hashcode): No record.
- `google-pizza-challenge_marcosmmb` (https://github.com/marcosmmb/google-pizza-challenge): No record.
- `google_hash_code_pizza_problem_janerikhein` (https://github.com/janerikhein/google_hash_code_pizza_problem): Screen: small 38, invalid output on `medium`, invalid output on `big`.
- `google_hashcode_2017_erseco` (https://github.com/erseco/google_hashcode_2017): Within 5%, with a sum of means of 935,637, but ranked 32 of 54, below the top ten. Its stored outputs total 935,792.
- `google_hashcode_2017_lucianbc` (https://github.com/lucianbc/google_hashcode_2017): Screen: small 40, medium 48,269, invalid output on `big`. Best of 2 programs.
- `google_hashcode_pizza_2019_AnatoliiStepaniuk` (https://github.com/AnatoliiStepaniuk/google_hashcode_pizza_2019): Its stored outputs total 912,475, just above the line, but it wrote nothing on `medium` or `big` within the time limit (small 25).
- `googlehashcode-pizza-problem_anass05` (https://github.com/anass05/googlehashcode-pizza-problem): Full protocol: `Main.java` has a sum of means of 906,755 (small 35, medium 43,749, big 862,971), below 911,228.
- `hascode_mmarouen` (https://github.com/mmarouen/hascode): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, out of memory on `big` at 6 GB.
- `hash-code-2019_team-pithon` (https://github.com/team-pithon/hash-code-2019): No record.
- `hashCode2018_planga82` (https://github.com/planga82/hashCode2018): Screen: small 5, medium 1,548, no output on `big` in 5 minutes. Its stored outputs total 82,025.
- `hashCode2019-training_greenTransistor` (https://github.com/greenTransistor/hashCode2019-training): Within 5%, with a sum of means of 938,256, but ranked 29 of 54, below the top ten.
- `hashCode2020_aurensanx` (https://github.com/aurensanx/hashCode2020): No record. Its stored outputs total 707,954.
- `hashCode_jagh` (https://github.com/jagh/hashCode): No record.
- `hash_code_pizza_AlexVndnblcke` (https://github.com/AlexVndnblcke/hash_code_pizza): No record.
- `hashcode-2017-practice_wl-seclin-hashcode` (https://github.com/wl-seclin-hashcode/hashcode-2017-practice): No record.
- `hashcode-2017-practice_xiaohan2012` (https://github.com/xiaohan2012/hashcode-2017-practice): No record. It stores valid outputs only for `small` (34).
- `hashcode-2017-prep_drublackberry` (https://github.com/drublackberry/hashcode-2017-prep): No record.
- `hashcode-2017-solution_Edraak` (https://github.com/Edraak/hashcode-2017-solution): Within 5%, with a sum of means of 935,090, but ranked 35 of 54, below the top ten.
- `hashcode-2017-training_drowolath` (https://github.com/drowolath/hashcode-2017-training): Screen: small 25, no output on `medium` in 5 minutes.
- `hashcode-2017_ShirazSuleman` (https://github.com/ShirazSuleman/hashcode-2017): Screen: totals 877,388 (small 35, medium 46,905, big 830,448).
- `hashcode-2017_clemkoa` (https://github.com/clemkoa/hashcode-2017): Screen: totals 883,983 (small 25, medium 46,740, big 837,218).
- `hashcode-2017_hermanzdosilovic` (https://github.com/hermanzdosilovic/hashcode-2017): Within 5%, with a sum of means of 935,780, but ranked 31 of 54, below the top ten. Its stored outputs total 936,696.
- `hashcode-2018-pizza_ghepavdi` (https://github.com/ghepavdi/hashcode-2018-pizza): Screen: totals 888,520 (small 22, medium 46,744, big 841,754).
- `hashcode-2018-pizza_vicmunoz` (https://github.com/vicmunoz/hashcode-2018-pizza): No record.
- `hashcode-2018_muety` (https://github.com/muety/hashcode-2018): Screen and a 10-minute run: small 40, no valid output on `medium`, no output on `big` in 10 minutes.
- `hashcode-2018_oktomus` (https://github.com/oktomus/hashcode-2018): Screen: small 15, invalid output on `medium`, no output on `big` in 5 minutes.
- `hashcode-2018_sharkadi-a` (https://github.com/sharkadi-a/hashcode-2018): Within 5%, with a sum of means of 929,285, but ranked 49 of 54, below the top ten.
- `hashcode-2019-pizza_1okey` (https://github.com/1okey/hashcode-2019-pizza): Screen: small 33, invalid output on `medium`, invalid output on `big`.
- `hashcode-2019-preparation_hackathonsdrinkteam` (https://github.com/hackathonsdrinkteam/hashcode-2019-preparation): Screen: totals 887,759 (small 41, medium 48,091, big 839,627). Its stored outputs total 887,759.
- `hashcode-2019_WeberJulian` (https://github.com/WeberJulian/hashcode-2019): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. Its stored outputs total 222,696.
- `hashcode-2019_chameleonTK` (https://github.com/chameleonTK/hashcode-2019): Screen: small 40, medium 48,269, no output on `big` in 5 minutes. Best of 2 programs.
- `hashcode-2019_youstinus` (https://github.com/youstinus/hashcode-2019): No record.
- `hashcode-core_tyburam` (https://github.com/tyburam/hashcode-core): Its stored outputs total 933,253, above the line, but it wrote nothing on `big` within the time limit (small 35, medium 48,246).
- `hashcode-example-2018_Fokko` (https://github.com/Fokko/hashcode-example-2018): No record.
- `hashcode-palinkoders-2018_manupm87` (https://github.com/manupm87/hashcode-palinkoders-2018): Screen and a 10-minute run: small 42, medium 46,970, no valid output on `big`. Its stored outputs total 889,109.
- `hashcode-pizza-problem-practice_mikeogezi` (https://github.com/mikeogezi/hashcode-pizza-problem-practice): No record.
- `hashcode-pizza-problem_cmplx-xyttmt` (https://github.com/cmplx-xyttmt/hashcode-pizza-problem): Screen: small 30, invalid output on `medium`, invalid output on `big`.
- `hashcode-pizza-problem_rotolonico` (https://github.com/rotolonico/hashcode-pizza-problem): Screen: totals 876,500 (small 30, medium 46,536, big 829,934).
- `hashcode-pizza_DriesDeRydt` (https://github.com/DriesDeRydt/hashcode-pizza): Screen: totals 9,710. It stores valid outputs only for `small` (40) and `medium` (13,572).
- `hashcode-pizza_alesolano` (https://github.com/alesolano/hashcode-pizza): No record. Its stored outputs total 749,863.
- `hashcode-pizza_carderne` (https://github.com/carderne/hashcode-pizza): Screen and a 10-minute run: small 38, medium 48,616, no valid output on `big`. Its stored outputs total 898,296.
- `hashcode-pizza_cesartl` (https://github.com/cesartl/hashcode-pizza): No record.
- `hashcode-pizza_chaszzt` (https://github.com/chaszzt/hashcode-pizza): Screen: small 42, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `small` (42).
- `hashcode-pizza_filkaris` (https://github.com/filkaris/hashcode-pizza): No record.
- `hashcode-pizza_firstprateek` (https://github.com/firstprateek/hashcode-pizza): No record.
- `hashcode-pizza_hendrikcech` (https://github.com/hendrikcech/hashcode-pizza): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `hashcode-pizza_kafkoders` (https://github.com/kafkoders/hashcode-pizza): Within 5%, with a sum of means of 932,667, but ranked 43 of 54, below the top ten. Its stored outputs total 932,668.
- `hashcode-pizza_krezac` (https://github.com/krezac/hashcode-pizza): No record.
- `hashcode-pizza_maksmas` (https://github.com/maksmas/hashcode-pizza): No record.
- `hashcode-pizza_necrashter` (https://github.com/necrashter/hashcode-pizza): Its stored outputs total 935,260, above the line, but it wrote nothing on `big` within the time limit (small 42, medium 48,280).
- `hashcode-pizza_perdy` (https://github.com/perdy/hashcode-pizza): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `hashcode-pizza_prague-pandas` (https://github.com/prague-pandas/hashcode-pizza): Screen: small 35, medium 49,216, no output on `big` in 5 minutes.
- `hashcode-pizza_sprkrd` (https://github.com/sprkrd/hashcode-pizza): No record.
- `hashcode-practice-pizza_zack-xiang` (https://github.com/zack-xiang/hashcode-practice-pizza): No record.
- `hashcode-prep_jeysal` (https://github.com/jeysal/hashcode-prep): Screen: totals 869,952 (small 39, medium 47,152, big 822,761). Its stored outputs total 869,955.
- `hashcode17-practice_msvechla` (https://github.com/msvechla/hashcode17-practice): Screen: small 20, medium 44,586, no output on `big` in 5 minutes.
- `hashcode17-training_dwarfmaster` (https://github.com/dwarfmaster/hashcode17-training): Screen: small 39, invalid output on `medium`, invalid output on `big`. Its stored outputs total 861,085.
- `hashcode19_radjavi` (https://github.com/radjavi/hashcode19): Screen: small 30, invalid output on `medium`, invalid output on `big`. Its stored outputs total 869,709.
- `hashcode2017-jamp-pizza_renuo` (https://github.com/renuo/hashcode2017-jamp-pizza): No record. Its stored outputs total 273,582.
- `hashcode2017-practice_Freeways` (https://github.com/Freeways/hashcode2017-practice): No record.
- `hashcode2017-practice_LostVariables` (https://github.com/LostVariables/hashcode2017-practice): Screen and a 10-minute run: small 42, no valid output on `medium`, no valid output on `big`.
- `hashcode2017-practice_Nasvera` (https://github.com/Nasvera/hashcode2017-practice): No record.
- `hashcode2017-practice_ishmaelmakitla` (https://github.com/ishmaelmakitla/hashcode2017-practice): No record.
- `hashcode2017.0_jdmichaud` (https://github.com/jdmichaud/hashcode2017.0): Within 5%, with a sum of means of 942,568, but ranked 25 of 54, below the top ten.
- `hashcode2017_Diegoriggle77` (https://github.com/Diegoriggle77/hashcode2017): Within 5%, with a sum of means of 936,103, but ranked 30 of 54, below the top ten. Its stored outputs total 940,928.
- `hashcode2017_KoenP` (https://github.com/KoenP/hashcode2017): Screen: small 35, invalid output on `medium`, no output on `big` in 5 minutes. It stores valid outputs only for `small` (35) and `big` (836).
- `hashcode2017_LowikC` (https://github.com/LowikC/hashcode2017): Screen and a 10-minute run: small 42, no valid output on `medium`, out of memory on `big` at 6 GB.
- `hashcode2017_Pcheape` (https://github.com/Pcheape/hashcode2017): No record. It stores valid outputs only for `big` (526,259).
- `hashcode2017_TeamRocketHashcode` (https://github.com/TeamRocketHashcode/hashcode2017): No record.
- `hashcode2017_alreadytaikeune` (https://github.com/alreadytaikeune/hashcode2017): No record.
- `hashcode2017_mmtr` (https://github.com/mmtr/hashcode2017): Screen: small 38, medium 46,840, no output on `big` in 5 minutes.
- `hashcode2017_moked` (https://github.com/moked/hashcode2017): No record.
- `hashcode2017_vaiol` (https://github.com/vaiol/hashcode2017): No record.
- `hashcode2018-pizza_claudiosousa` (https://github.com/claudiosousa/hashcode2018-pizza): Screen: small 42, medium 46,593, no output on `big` in 5 minutes. Best of 2 programs. Its stored outputs total 846,753.
- `hashcode2018-practise_Itope84` (https://github.com/Itope84/hashcode2018-practise): Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes.
- `hashcode2018_DanieleMaisto` (https://github.com/DanieleMaisto/hashcode2018): No record.
- `hashcode2018_PaulienVa` (https://github.com/PaulienVa/hashcode2018): Screen: small 4, invalid output on `medium`, invalid output on `big`.
- `hashcode2018_mmtr` (https://github.com/mmtr/hashcode2018): No record.
- `hashcode2018_phischepi` (https://github.com/phischepi/hashcode2018): No record.
- `hashcode2018_tirbal` (https://github.com/tirbal/hashcode2018): No record.
- `hashcode2018_training_mdelorme` (https://github.com/mdelorme/hashcode2018_training): Within 5%, with a sum of means of 935,027, but ranked 36 of 54, below the top ten.
- `hashcode2018pizza_orbytegithub` (https://github.com/orbytegithub/hashcode2018pizza): No record.
- `hashcode2018zaragoza_DavidRoyApp` (https://github.com/DavidRoyApp/hashcode2018zaragoza): No record.
- `hashcode2019-pizza_ellisvlad` (https://github.com/ellisvlad/hashcode2019-pizza): No record.
- `hashcode2019_mcanalesmayo` (https://github.com/mcanalesmayo/hashcode2019): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `hashcode2019training_Anastasiya-Zhyrkevich` (https://github.com/Anastasiya-Zhyrkevich/hashcode2019training): Full protocol: `main.py` has a sum of means of 907,353 (small 38, medium 49,438, big 857,877), below 911,228.
- `hashcode2021_gcoro` (https://github.com/gcoro/hashcode2021): No record.
- `hashcode_2018_practice_OddballGreg` (https://github.com/OddballGreg/hashcode_2018_practice): No record.
- `hashcode_2019_josecyc` (https://github.com/josecyc/hashcode_2019): No record.
- `hashcode_JasonSome` (https://github.com/JasonSome/hashcode): Within 5%, with a sum of means of 946,711, but ranked 12 of 54, below the top ten. Its programs: `pizza_last_version.cpp` 946,711; `pizza_first_version.cpp` 935,673.
- `hashcode_Julien2313` (https://github.com/Julien2313/hashcode): No record.
- `hashcode_Shoomaher` (https://github.com/Shoomaher/hashcode): No record.
- `hashcode_google_2019_CaptainKali` (https://github.com/CaptainKali/hashcode_google_2019): Screen: totals 900,996 (small 28, medium 48,754, big 852,214).
- `hashcode_pizza_ShivamShrirao` (https://github.com/ShivamShrirao/hashcode_pizza): No record.
- `hashcode_pizza_adwitiya` (https://github.com/adwitiya/hashcode_pizza): Within 5%, with a sum of means of 944,718, but ranked 15 of 54, below the top ten. Its stored outputs total 944,718.
- `hashcode_pizza_gaetancollaud` (https://github.com/gaetancollaud/hashcode_pizza): Within 5%, with a sum of means of 944,112, but ranked 16 of 54, below the top ten.
- `hashcode_pizza_snowme34` (https://github.com/snowme34/hashcode_pizza): Within 5%, with a sum of means of 920,593, but ranked 51 of 54, below the top ten. Its stored outputs total 920,593.
- `hashcode_pizza_vitaliipoliakov` (https://github.com/vitaliipoliakov/hashcode_pizza): Within 5%, with a sum of means of 935,560, but ranked 34 of 54, below the top ten. Its programs: `pizza_faster.py` 935,560; `pizza_evenfaster.py` 933,767. Its stored outputs total 935,560.
- `hashcode_train_akpenou` (https://github.com/akpenou/hashcode_train): Screen and a 10-minute run: small 40, no valid output on `medium`, no output on `big` in 10 minutes. It stores valid outputs only for `small` (40) and `medium` (42,671).
- `hashcode_unitn_FraLotito` (https://github.com/FraLotito/hashcode_unitn): Within 5%, with a sum of means of 943,946, but ranked 18 of 54, below the top ten. Its programs: `greedy_pizza_943k.py` 943,790; `greedy_pizza_943.cc` 943,946.
- `js_ocono_hashcode_test_sameersemna` (https://github.com/sameersemna/js_ocono_hashcode_test): No record.
- `pelicans-pizza_aurensanx` (https://github.com/aurensanx/pelicans-pizza): No record. Its stored outputs total 644,544.
- `pizza-HashCode_guynnn` (https://github.com/guynnn/pizza-HashCode): No record.
- `pizza-hash_LukeDS-it` (https://github.com/LukeDS-it/pizza-hash): No record.
- `pizza-hashcode_jpborsi` (https://github.com/jpborsi/pizza-hashcode): Within 5%, with a sum of means of 939,587, but ranked 28 of 54, below the top ten. Its stored outputs total 939,587.
- `pizza-problem-hash-code_kshikha818` (https://github.com/kshikha818/pizza-problem-hash-code): No record.
- `pizza-slicing_stemlaur` (https://github.com/stemlaur/pizza-slicing): No record.
- `pizzaHashCode_JonathanWoollett-Light` (https://github.com/JonathanWoollett-Light/pizzaHashCode): No record.
- `pizza_GoogleHashCode_2017_wawrzy` (https://github.com/wawrzy/pizza_GoogleHashCode_2017): Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes.
- `pizza_JulianNeeleman` (https://github.com/JulianNeeleman/pizza): Screen: totals 42,188. It stores valid outputs only for `small` (5) and `medium` (12).
- `pizza_Rwothoromo` (https://github.com/Rwothoromo/pizza): No record.
- `pizza_bbrincat` (https://github.com/bbrincat/pizza): No record.
- `pizza_dnltsk` (https://github.com/dnltsk/pizza): Screen: totals 748,546.
- `pizza_google_hashcode_tod01` (https://github.com/tod01/pizza_google_hashcode): No record.
- `pizza_hashcode_ngulya` (https://github.com/ngulya/pizza_hashcode): Screen: totals 874,137 (small 40, medium 46,807, big 827,290).
- `pizza_kemo71` (https://github.com/kemo71/pizza): No record.
- `pizza_pbarbero` (https://github.com/pbarbero/pizza): No record.
- `pizza_veselypeta` (https://github.com/veselypeta/pizza): No record.
- `pizzapuzzle_jacksono` (https://github.com/jacksono/pizzapuzzle): No record.
- `practice_hashcode_2017_WestleyB` (https://github.com/WestleyB/practice_hashcode_2017): No record.
- `suha17_Laged` (https://github.com/Laged/suha17): No record.

## Duplicates removed during import

- `42Robo_food`: same source code (after normalising line endings and whitespace) as `42Robo-food_snugdad`.
- [kartikey20/Google-Hashcode-2019-pizza-problem-solution](https://github.com/kartikey20/Google-Hashcode-2019-pizza-problem-solution) (`4489d4b`): same source code (after normalising line endings and whitespace) as `Google-Hashcode-Pizza-Problem-Solution_konradbachusz-zz`.
- [Toulik-Das/Hash-Code-Example-problem-2019-Pizza-Problem-](https://github.com/Toulik-Das/Hash-Code-Example-problem-2019-Pizza-Problem-) (`b7b4ee9`): same source code (after normalising line endings and whitespace) as `Google-Hashcode-Pizza-Problem-Solution_konradbachusz-zz`.
- [kameranis/HashCode-2017](https://github.com/kameranis/HashCode-2017) (`9394a26`): same source code (after normalising line endings and whitespace) as `HashCode-2017_Nasvera`.

## Official inputs removed

48 files in 12 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>hashcode-2018_clemkoa</code> (4 files)</summary>

- `pizza/input/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `pizza/input/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `pizza/input/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `pizza/input/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>hashcode_pizza_2018_yoann-dufresne</code> (4 files)</summary>

- `big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/distance_priority_queue_with_improvement</code> (4 files)</summary>

- `dataset/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `dataset/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `dataset/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `dataset/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/filter_grow_up_greedy</code> (4 files)</summary>

- `assets/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `assets/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `assets/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `assets/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/first_fit_then_recut_slices</code> (4 files)</summary>

- `practice/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `practice/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `practice/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `practice/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/guillotine_block_dynamic_programming</code> (4 files)</summary>

- `in/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `in/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `in/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `in/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/mask_then_grow_slices</code> (4 files)</summary>

- `18-Pizza/in/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `18-Pizza/in/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `18-Pizza/in/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `18-Pizza/in/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/priority_queue_slice_growth</code> (4 files)</summary>

- `src/pizza/in/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `src/pizza/in/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `src/pizza/in/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `src/pizza/in/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/shape_count_priority_with_recursive_repair</code> (4 files)</summary>

- `inputs/a_example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `inputs/b_small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`
- `inputs/c_medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `inputs/d_big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`

</details>

<details><summary><code>solvers/smallest_piece_walk_then_expand</code> (4 files)</summary>

- `a_example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `b_small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`
- `c_medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `d_big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`

</details>

<details><summary><code>solvers/strategic_ingredient_smallest_slice_greedy</code> (4 files)</summary>

- `pizza-slicer/docs/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `pizza-slicer/docs/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `pizza-slicer/docs/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `pizza-slicer/docs/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>

<details><summary><code>solvers/two_pass_rectangle_cut</code> (4 files)</summary>

- `training/input/big.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/big.in`
- `training/input/example.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/example.in`
- `training/input/medium.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/medium.in`
- `training/input/small.in` ← `archive/2017/practice/hashcode_2017_practice_round.in/small.in`

</details>
