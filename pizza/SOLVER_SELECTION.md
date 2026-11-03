# Pizza: choosing the best solvers

Google Hash Code 2017, Practice round. Its three main instances are `small`, `medium` and `big`; the example was not run. 294 repositories were in the folder. 11 solvers were kept, 280 repositories were removed, and 3 whose main programs need a license stay in the folder.

## Kept

| Solver | Repository | small | medium | big | Sum of means | Below the best |
|---|---|---:|---:|---:|---:|---:|
| [overlap_shrinking_largest_slice_greedy](solvers/overlap_shrinking_largest_slice_greedy/) | `sagishporer` | **42** | 49,576 | **909,569** | 959,187 | — |
| [two_pass_rectangle_cut](solvers/two_pass_rectangle_cut/) | `nappa85` | 40 | 49,213 | 905,435 | 954,688 | 0.47% |
| [first_fit_then_recut_slices](solvers/first_fit_then_recut_slices/) | `mozanunal` | 40 | 49,194 | 905,436 | 954,670 | 0.47% |
| [distance_priority_queue_with_improvement](solvers/distance_priority_queue_with_improvement/) | `GaspareG` | 38 | 49,255 | 905,295 | 954,588 | 0.48% |
| [shape_count_priority_with_recursive_repair](solvers/shape_count_priority_with_recursive_repair/) | `RobertObkircher` | 34 | 48,887 | 902,584 | 951,505 | 0.80% |
| [smallest_piece_walk_then_expand](solvers/smallest_piece_walk_then_expand/) | `vboiko-gt` | 40 | 48,940 | 902,212 | 951,192 | 0.83% |
| [filter_grow_up_greedy](solvers/filter_grow_up_greedy/) | `msagi` | 40 | 48,922 | 901,839 | 950,801 | 0.87% |
| [mask_then_grow_slices](solvers/mask_then_grow_slices/) | `mcieno` | 40 | 48,888 | 901,289 | 950,217 | 0.94% |
| [strategic_ingredient_smallest_slice_greedy](solvers/strategic_ingredient_smallest_slice_greedy/) | `ROMBTeam` | 40 | 48,919 | 901,231 | 950,190 | 0.94% |
| [priority_queue_slice_growth](solvers/priority_queue_slice_growth/) | `Lrakulka` | 40 | 48,824 | 900,321 | 949,185 | 1.04% |
| [guillotine_block_dynamic_programming](solvers/guillotine_block_dynamic_programming/) | `ClementChouteau` | 38 | **49,998** | — | 50,036 | first on `medium` |

Bold is the best run of any program on that instance, and the other numbers are means. All eleven programs give the same score on every run.

## How the eleven were chosen

The usual rule keeps a solver that is first on an instance, or whose sum of per-instance means is within 5% of the top score. No scoreboard was published for the practice round, so the reference was the best sum of means of any program we ran, 959,187 (`overlap_shrinking_largest_slice_greedy`), and the 5% line was 911,228.

57 programs from 54 repositories cleared that line. Most are simple greedy programs that cut the first or largest valid rectangle at each cell, and their totals sit within a few percent of each other, so the 5% rule could not separate them. Of those, only the ten with the highest sums of means were kept. `big` makes up about 95% of each total, so that ranking is mostly a ranking on `big`.

A program that alone has the best result on an instance is also kept. `guillotine_block_dynamic_programming` (`progdyn_bloc.cpp`) has the best `medium` result, 49,998, though it writes nothing on `big` in 10 minutes. `overlap_shrinking_largest_slice_greedy` has the best `big` result and is already in the top ten. On `small`, many programs reach 42, which covers every cell, so no program is first there alone, and a tie does not keep a program.

What the cut leaves out:

- **A near miss.** The eleventh, `Google_Hashcode_2018_Pizza_Practice_shemetz`, has a mean of 947,948, 1,237 below the tenth. It is random, and its best runs on `medium` and `big` would total 950,591, above the tenth.
- **A copy.** `HashCode_mohsenTalal` scores the same as `overlap_shrinking_largest_slice_greedy` and is a renamed copy of it, so it was removed in any case.
- **The other program in a kept folder.** `glouton.cpp`, beside `progdyn_bloc.cpp`, has a sum of means of 943,880 and ranks 19th, so it is not kept for itself.

## Results that depend on our changes

- `overlap_shrinking_largest_slice_greedy` no longer saves a picture of the slices, and got a .NET 6 project over its old .NET Framework sources. Neither changes the slicing.
- `priority_queue_slice_growth` imports three classes that the repository does not include (`InputData`, `OutputData` and `ProblemDataIO`). We added them, and without them it does not build.
- The other nine ran unchanged. `first_fit_then_recut_slices` is Python 2 and ran under PyPy. Programs that read fixed paths had the instance copied there, as each `scores.md` says.

## Programs whose stored scores exceed our runs

- `hashcode-2018_clemkoa` stores 922,326 on `big`, the best `big` result in the collection. It comes from `pizza/solve.py`, which needs a LocalSolver license, so the repository stays in the folder unbenchmarked (see [LICENSED_SOLVERS.md](../LICENSED_SOLVERS.md)). Its free `run.py` totals 795,918.
- Three removed repositories store totals above the tenth kept solver: `google-hash-code-pizza_uran-lajci` (959,605, the highest stored total), `Google_Hashcode_2018_Pizza_Practice_shemetz` (951,698) and `Google_Hashcode_pizza_problem_solution_YacovAverbuch` (950,693). In our runs they average 943,699, 947,948 and 913,274. `uran-lajci` improves a given solution, and we started it from an empty one. Started from `overlap_shrinking_largest_slice_greedy`'s `big` output, it gained 357 points in 2 minutes, so its stored outputs likely come from improving other programs' solutions.

## What we did

1. **Collected.** 294 repositories, after the earlier non-solver prunes.
2. **Probed and built.** Every program that looked like a solver was built and probed on the small instance to learn how it reads the instance and where it writes the result. Programs in C, C++, C#, Java, JavaScript, Python, Rust, PHP and Go ran; build rules are under *Run setup* below.
3. **Screened.** One run with a 5-minute limit, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/pizza/judge.py`. A run whose output the judge rejects counts as 0. 193 programs from 168 repositories got this far.
4. **10-minute runs.** A program with no valid output at 5 minutes got a 10-minute run on the instances that lacked one. Programs killed at the 3.5 GB memory limit got a retry at 6 GB.
5. **Full protocol.** A program advanced if it was in the top 3 or within 20% of the best on any instance, or in the top 3 by total. Nearly everything is within 20% on `big`, so 135 advanced. It then got 10 runs at a 10-minute limit, or 2 runs if both gave the same score, the second with another `PYTHONHASHSEED`.
6. **Restart.** The machine restarted on 2026-11-02 and the scratch folder with the benchmark was lost. We rebuilt it and re-ran the full protocol for the 62 programs near or above the 5% line, which matched the lost results. Programs well below the line were not re-run, and their screen scores are taken from the session log. Records of programs below 869,709 at the screen, and of programs that never gave a valid output, were lost.
7. **Selected.** 57 programs from 54 repositories had a sum of means of at least 911,228. The ten repositories with the highest sums were kept, and so was the one program that alone has the best result on an instance. The others were deleted, apart from three that need a license.
8. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods, and each README starts with a header giving the source and the method. The outputs in [output/](output/) come from the full-protocol runs and were not repeated after the move.

## Run setup

- **C and C++:** `g++ -O2 -std=c++20` or `-std=c++17 -fpermissive` (`gcc -std=gnu11` for C), with the other source files beside the entry point that have no `main`.
- **Java:** `javac` over the source tree, then `java -Xss512m -Xmx3g`.
- **C#:** the .NET 6 SDK, `dotnet build -c Release`. Old .NET Framework projects got a .NET 6 project over the same sources.
- **Python:** CPython 3.12 with NumPy and SciPy. Python 2 programs ran under PyPy 2.7. A small driver seeded `random` and `numpy.random` with the run's seed and restored names that newer Python and NumPy removed (`time.clock`, `numpy.int` and the like).
- **Others:** Node.js 20, Rust 1.82 with `cargo build --release`, PHP 8.3 with `memory_limit=-1`.
- **Instance files.** Programs that read fixed paths had the instance copied to those paths. The run line in each `scores.md` says where.

## Removed repositories

The scores are the best ones we have for each repository: the full-protocol mean for the 44 that cleared the 5% line, and otherwise the screen total, or the full-protocol mean where it says so. Stored totals are of the output files in the repository, scored with the official judge.

| Repository | Why it is out |
|---|---|
| `HashCode_mohsenTalal` | A renamed copy of `hashcode-practice-pizza_sagishporer`, which is kept as `overlap_shrinking_largest_slice_greedy`. About 91% of its code tokens match, it scores the same on every instance (959,187), and `sagishporer`'s single commit is a year older (2019-02-24, against 2020-02-14) and documents the method. |
| `Google_Hashcode_2018_Pizza_Practice_shemetz` | Within 5%, with a sum of means of 947,948, but ranked 11 of 54, below the top ten. Its stored outputs total 951,698. |
| `hashcode_JasonSome` | Within 5%, with a sum of means of 946,711, but ranked 12 of 54, below the top ten. Its programs: `pizza_last_version.cpp` 946,711; `pizza_first_version.cpp` 935,673. |
| `Problem-Statement-Pizza-Hash-Code-0xZBV_3_VigHub` | Within 5%, with a sum of means of 946,711, but ranked 13 of 54, below the top ten. Its stored outputs total 946,711. |
| `Google-HashCode_danicrg` | Within 5%, with a sum of means of 945,136, but ranked 14 of 54, below the top ten. Its stored outputs total 945,463. |
| `hashcode_pizza_adwitiya` | Within 5%, with a sum of means of 944,718, but ranked 15 of 54, below the top ten. Its stored outputs total 944,718. |
| `hashcode_pizza_gaetancollaud` | Within 5%, with a sum of means of 944,112, but ranked 16 of 54, below the top ten. |
| `Pizza_Problem_AcoffeePlease` | Within 5%, with a sum of means of 943,965, but ranked 17 of 54, below the top ten. Its stored outputs total 943,965. |
| `hashcode_unitn_FraLotito` | Within 5%, with a sum of means of 943,946, but ranked 18 of 54, below the top ten. Its programs: `greedy_pizza_943k.py` 943,790; `greedy_pizza_943.cc` 943,946. |
| `google-hashcode-pizza-problem_alessandro1105` | Within 5%, with a sum of means of 943,706, but ranked 20 of 54, below the top ten. Its stored outputs total 943,706. |
| `google-hash-code-pizza_uran-lajci` | Within 5%, with a sum of means of 943,699, but ranked 21 of 54, below the top ten. Its stored outputs total 959,605. |
| `google-hashcode_AndreFCruz` | Within 5%, with a sum of means of 943,699, but ranked 22 of 54, below the top ten. |
| `HashCodePizza_peterjgill` | Within 5%, with a sum of means of 943,532, but ranked 23 of 54, below the top ten. Its stored outputs total 943,532. |
| `GoogleHashCodeTestRound_Loniowsky` | Within 5%, with a sum of means of 943,104, but ranked 24 of 54, below the top ten. |
| `hashcode2017.0_jdmichaud` | Within 5%, with a sum of means of 942,568, but ranked 25 of 54, below the top ten. |
| `HashCode2017_nappa85` | Within 5%, with a sum of means of 942,563, but ranked 26 of 54, below the top ten. Its stored outputs total 942,563. |
| `HashCode2019train_kirmartynov` | Within 5%, with a sum of means of 939,884, but ranked 27 of 54, below the top ten. |
| `pizza-hashcode_jpborsi` | Within 5%, with a sum of means of 939,587, but ranked 28 of 54, below the top ten. Its stored outputs total 939,587. |
| `hashCode2019-training_greenTransistor` | Within 5%, with a sum of means of 938,256, but ranked 29 of 54, below the top ten. |
| `hashcode2017_Diegoriggle77` | Within 5%, with a sum of means of 936,103, but ranked 30 of 54, below the top ten. Its stored outputs total 940,928. |
| `PizzaCutter_Mikeywalsh` | Its stored outputs total 935,791, above the line, but it wrote nothing on `big` within the time limit (small 42, medium 48,261). |
| `hashcode-2017_hermanzdosilovic` | Within 5%, with a sum of means of 935,780, but ranked 31 of 54, below the top ten. Its stored outputs total 936,696. |
| `google_hashcode_2017_erseco` | Within 5%, with a sum of means of 935,637, but ranked 32 of 54, below the top ten. Its stored outputs total 935,792. |
| `Google_HashCode_PizzaSlicing_iwih` | Its stored outputs total 935,588, above the line, but it ran out of memory on `big` (small 40, medium 47,932, both at the time limit). |
| `Google-Hash-Code-Pizza_ilie05` | Within 5%, with a sum of means of 935,560, but ranked 33 of 54, below the top ten. |
| `hashcode_pizza_vitaliipoliakov` | Within 5%, with a sum of means of 935,560, but ranked 34 of 54, below the top ten. Its programs: `pizza_faster.py` 935,560; `pizza_evenfaster.py` 933,767. Its stored outputs total 935,560. |
| `hashcode-pizza_necrashter` | Its stored outputs total 935,260, above the line, but it wrote nothing on `big` within the time limit (small 42, medium 48,280). |
| `hashcode-2017-solution_Edraak` | Within 5%, with a sum of means of 935,090, but ranked 35 of 54, below the top ten. |
| `hashcode2018_training_mdelorme` | Within 5%, with a sum of means of 935,027, but ranked 36 of 54, below the top ten. |
| `google-hashcode-pizza-solution_nikpundik` | Within 5%, with a sum of means of 933,289, but ranked 37 of 54, below the top ten. Its stored outputs total 933,289. |
| `google-hashcode-2019_mohantejach` | Within 5%, with a sum of means of 933,278, but ranked 38 of 54, below the top ten. Its stored outputs total 933,278. |
| `HashCode2018_GioVAX` | Within 5%, with a sum of means of 933,278, but ranked 39 of 54, below the top ten. |
| `Google-Hash-Code-Pizza_Mroziek` | Within 5%, with a sum of means of 933,258, but ranked 40 of 54, below the top ten. Its stored outputs total 933,258. |
| `hashcode-core_tyburam` | Its stored outputs total 933,253, above the line, but it wrote nothing on `big` within the time limit (small 35, medium 48,246). |
| `HashCode2019PracticeProblem_CoffeeVector` | Within 5%, with a sum of means of 933,040, but ranked 41 of 54, below the top ten. Its stored outputs total 933,040. |
| `HashCode2018_matteoformenti` | Within 5%, with a sum of means of 932,932, but ranked 42 of 54, below the top ten. Its stored outputs total 932,932. |
| `hashcode-pizza_kafkoders` | Within 5%, with a sum of means of 932,667, but ranked 43 of 54, below the top ten. Its stored outputs total 932,668. |
| `Hash-Code-Pizza-Practice-Round-_gheorghe-sava` | Within 5%, with a sum of means of 932,254, but ranked 44 of 54, below the top ten. |
| `ghc-pizza-problem_bboron86` | Within 5%, with a sum of means of 931,496, but ranked 45 of 54, below the top ten. |
| `Google-Hash_AlexBlandin` | Its stored outputs total 930,955, above the line. Its writer needed two fixes from us, after which it scored 37 on small and 40,044 on medium, and it did not finish `big` within the time limit, even with 6 GB. |
| `HashCode2018Pizza_gdgbologna` | Within 5%, with a sum of means of 929,539, but ranked 46 of 54, below the top ten. Its stored outputs total 929,497. |
| `GHC_Practice2017_Pizza_TedevFR` | Within 5%, with a sum of means of 929,494, but ranked 47 of 54, below the top ten. Its stored outputs total 929,494. |
| `Pizza_pysergio` | Within 5%, with a sum of means of 929,494, but ranked 48 of 54, below the top ten. Its stored outputs total 929,504. |
| `hashcode-2018_sharkadi-a` | Within 5%, with a sum of means of 929,285, but ranked 49 of 54, below the top ten. |
| `The-Pizza-Problem_RubinDaija` | Within 5%, with a sum of means of 922,911, but ranked 50 of 54, below the top ten. |
| `hashcode_pizza_snowme34` | Within 5%, with a sum of means of 920,593, but ranked 51 of 54, below the top ten. Its stored outputs total 920,593. |
| `google-hash-code-2017-task_nikitaeverywhere` | Within 5%, with a sum of means of 918,504, but ranked 52 of 54, below the top ten. Its stored outputs total 919,174. |
| `Google_Hashcode_pizza_problem_solution_YacovAverbuch` | Within 5%, with a sum of means of 913,274, but ranked 53 of 54, below the top ten. Its stored outputs total 950,693. |
| `Google-Hashcode-Pizza-Problem-Solution_konradbachusz-zz` | Within 5%, with a sum of means of 912,802, but ranked 54 of 54, below the top ten. Its stored outputs total 912,802. |
| `google_hashcode_pizza_2019_AnatoliiStepaniuk` | Its stored outputs total 912,475, just above the line, but it wrote nothing on `medium` or `big` within the time limit (small 25). |
| `hashcode2019training_Anastasiya-Zhyrkevich` | Full protocol: `main.py` has a sum of means of 907,353 (small 38, medium 49,438, big 857,877), below 911,228. |
| `googlehashcode-pizza-problem_anass05` | Full protocol: `Main.java` has a sum of means of 906,755 (small 35, medium 43,749, big 862,971), below 911,228. |
| `GoogleHashCode_Pizza_2019_Jordilg13` | Full protocol: `mainPizza.py` has a sum of means of 905,892 (small 41, medium 47,490, big 858,361), below 911,228. |
| `hashcode_google_2019_CaptainKali` | Screen: totals 900,996 (small 28, medium 48,754, big 852,214). |
| `StreamingVideos-GoogleHashCode2017_huybthomas` | Screen: totals 890,761 (small 38, medium 47,381, big 843,342). |
| `hashcode-2018-pizza_ghepavdi` | Screen: totals 888,520 (small 22, medium 46,744, big 841,754). |
| `hashcode-2019-preparation_hackathonsdrinkteam` | Screen: totals 887,759 (small 41, medium 48,091, big 839,627). Its stored outputs total 887,759. |
| `hashcode-2017_clemkoa` | Screen: totals 883,983 (small 25, medium 46,740, big 837,218). |
| `Google-Hash-Code-Pizza-Problem-2017_Alexandru-Dascalu` | Screen: totals 877,388 (small 35, medium 46,905, big 830,448). |
| `hashcode-2017_ShirazSuleman` | Screen: totals 877,388 (small 35, medium 46,905, big 830,448). |
| `GoogleHashCode2019_spanoselias` | Screen: totals 877,212 (small 30, medium 46,934, big 830,248). |
| `hashcode-pizza-problem_rotolonico` | Screen: totals 876,500 (small 30, medium 46,536, big 829,934). |
| `pizza_hashcode_ngulya` | Screen: totals 874,137 (small 40, medium 46,807, big 827,290). |
| `hashcode-prep_jeysal` | Screen: totals 869,952 (small 39, medium 47,152, big 822,761). Its stored outputs total 869,955. |
| `GoogleHashCode_PizzaCutter_Gituser143` | Screen: totals 869,709 (small 30, medium 46,233, big 823,446). Its stored outputs total 869,709. |
| `pizza_dnltsk` | Screen: totals 748,546. |
| `pizza_JulianNeeleman` | Screen: totals 42,188. It stores valid outputs only for `small` (5) and `medium` (12). |
| `hashcode-pizza_DriesDeRydt` | Screen: totals 9,710. It stores valid outputs only for `small` (40) and `medium` (13,572). |
| `-Practise-Round-GoogleHashCode2017_krzysiekprzekwas` | Screen: small 40, invalid output on `medium`, invalid output on `big`. |
| `42Robo-food_snugdad` | No record. |
| `crHackers_manuelsalvadori` | No record. |
| `G-hashcode-trial_Thanerik` | Screen and a 10-minute run: no valid output on `small`, out of memory on `medium` at 6 GB, out of memory on `big` at 6 GB. |
| `ghc-pizza_yumin-chen` | No record. |
| `GHC2018_C-ka_mrtncls` | Screen: invalid output on `small`, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `big` (809,816). |
| `google-code-hash-pizza_augerm` | No record. |
| `Google-Hackathon-HashCode-2017-PizzaSubmition_DenysPodanenko` | No record. Its stored outputs total 764,091. |
| `Google-Hash-Code-2018-Practice-Problem_mihai-bontea` | No record. |
| `google-hash-code-2018-test_AleksandrChernyavenko` | Screen: small 20, invalid output on `medium`, invalid output on `big`. Its stored outputs total 876,370. |
| `google-hash-code-pizza_islam-aymann` | No record. |
| `google-hashcode-19_jaracoder` | No record. |
| `Google-HashCode-2017-preparation_AdrianMrn` | No record. |
| `google-hashcode-2017_PieterDr` | No record. |
| `Google-HashCode-2018-Test-Round_JGShaw` | No record. |
| `google-hashcode-2018_slimcdk` | No record. |
| `Google-HashCode-2019_mihailhernandez` | No record. |
| `Google-Hashcode-2019_QTimort` | No record. |
| `google-hashcode-pizza-problem_lindskogen` | No record. |
| `Google-HashCode-Pizza-Problem_ntedgi` | No record. |
| `google-hashcode-pizza-solution_stuffrome` | Screen and a 10-minute run: small 42, no valid output on `medium`, no output on `big` in 10 minutes. |
| `google-hashcode-pizza_arturo-source` | Screen and a 10-minute run: small 42, no valid output on `medium`, out of memory on `big` at 6 GB. |
| `google-hashcode-pizza_mindfulme` | No record. |
| `Google-HashCode2019_raviautar` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `google-hashcode_flobilosaurus` | No record. |
| `google-hashcode_hex7c0` | No record. |
| `Google-HashCodes-Pizza-Cutter_darraghmerrick` | No record. |
| `google-pizza-challenge_marcosmmb` | No record. |
| `google_hash_code_pizza_problem_janerikhein` | Screen: small 38, invalid output on `medium`, invalid output on `big`. |
| `Google_HashCode-2019_madilraza` | No record. |
| `google_hashcode_2017_lucianbc` | Screen: small 40, medium 48,269, invalid output on `big`. Best of 2 programs. |
| `Google_hashcode_2019_anstadnik` | No record. |
| `Google_Hashcode_Pizza_Dart_hussien4321` | No record. Its stored outputs total 816,330. |
| `Google_Pizza_Hash_Code_anisayari` | No record. |
| `Google_Pizza_Hash_Code_elados93` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes. |
| `GoogleHashCode-Pizza_TheBoomBoxer` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes. |
| `GoogleHashcode2017_davidmather` | No record. |
| `GoogleHashCode2017_LyashenkoGS` | Screen and a 10-minute run: small 28, no valid output on `medium`, no valid output on `big`. |
| `GoogleHashcode2019_AselKitulagoda` | No record. It stores valid outputs only for `small` (35) and `big` (15,274). |
| `GoogleHashCodePizza2019_sklipnoty` | Screen: small 41, medium 39,792, no output on `big` in 5 minutes. It stores valid outputs only for `small` (36) and `medium` (39,720). |
| `GoogleHashCodePizza_sklipnoty` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`. |
| `GoogleHashCodePizzaProblem_klyse` | No record. |
| `GooglePizza_Gonthar` | No record. |
| `GooglePizza_linnykoleh` | No record. It stores valid outputs only for `small` (40). |
| `hascode_mmarouen` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, out of memory on `big` at 6 GB. |
| `Hash-Code-2017-Practice-Test-Pizza-Problem-_TeamLS` | No record. Its stored outputs total 560,789. |
| `hash-code-2019_team-pithon` | No record. |
| `hash_code_pizza_AlexVndnblcke` | No record. |
| `HashCode-2017-Pizza_shaharalgaby` | No record. |
| `hashcode-2017-practice_wl-seclin-hashcode` | No record. |
| `hashcode-2017-practice_xiaohan2012` | No record. It stores valid outputs only for `small` (34). |
| `hashcode-2017-prep_drublackberry` | No record. |
| `hashcode-2017-training_drowolath` | Screen: small 25, no output on `medium` in 5 minutes. |
| `HashCode-2017_InfinityCollaborations` | Screen and a 10-minute run: small 28, no valid output on `medium`, no valid output on `big`. Best of 2 programs. Its stored outputs total 444,595. |
| `HashCode-2017_Nasvera` | No record. |
| `hashcode-2018-pizza_vicmunoz` | No record. |
| `HashCode-2018-Practice_Oliver-Binns` | No record. |
| `Hashcode-2018_brkn` | No record. |
| `hashcode-2018_muety` | Screen and a 10-minute run: small 40, no valid output on `medium`, no output on `big` in 10 minutes. |
| `hashcode-2018_oktomus` | Screen: small 15, invalid output on `medium`, no output on `big` in 5 minutes. |
| `hashcode-2019-pizza_1okey` | Screen: small 33, invalid output on `medium`, invalid output on `big`. |
| `hashcode-2019_chameleonTK` | Screen: small 40, medium 48,269, no output on `big` in 5 minutes. Best of 2 programs. |
| `hashcode-2019_WeberJulian` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. Its stored outputs total 222,696. |
| `hashcode-2019_youstinus` | No record. |
| `hashcode-example-2018_Fokko` | No record. |
| `hashcode-palinkoders-2018_manupm87` | Screen and a 10-minute run: small 42, medium 46,970, no valid output on `big`. Its stored outputs total 889,109. |
| `HashCode-Pizza-IM_ShambaC` | No record. |
| `hashcode-pizza-problem-practice_mikeogezi` | No record. |
| `hashcode-pizza-problem_cmplx-xyttmt` | Screen: small 30, invalid output on `medium`, invalid output on `big`. |
| `hashcode-pizza_alesolano` | No record. Its stored outputs total 749,863. |
| `hashcode-pizza_carderne` | Screen and a 10-minute run: small 38, medium 48,616, no valid output on `big`. Its stored outputs total 898,296. |
| `hashcode-pizza_cesartl` | No record. |
| `hashcode-pizza_chaszzt` | Screen: small 42, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `small` (42). |
| `hashcode-pizza_filkaris` | No record. |
| `hashcode-pizza_firstprateek` | No record. |
| `HashCode-Pizza_GhostPoro` | No record. |
| `hashcode-pizza_hendrikcech` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `hashcode-pizza_krezac` | No record. |
| `hashcode-pizza_maksmas` | No record. |
| `Hashcode-Pizza_muffin-coders` | No record. |
| `hashcode-pizza_perdy` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `hashcode-pizza_prague-pandas` | Screen: small 35, medium 49,216, no output on `big` in 5 minutes. |
| `hashcode-pizza_sprkrd` | No record. |
| `hashcode-practice-pizza_zack-xiang` | No record. |
| `HashCode-Pratice-2017_Ghoul-SSZ` | No record. |
| `HashCode-Train1-2018_victorspgl` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`. |
| `HashCode-Training-Problem_bartoszmodelski` | No record. It stores valid outputs only for `small` (30). |
| `HashCode-Warmup-2019_jueyaye` | No record. |
| `hashcode17-practice_msvechla` | Screen: small 20, medium 44,586, no output on `big` in 5 minutes. |
| `hashcode17-training_dwarfmaster` | Screen: small 39, invalid output on `medium`, invalid output on `big`. Its stored outputs total 861,085. |
| `hashcode19_radjavi` | Screen: small 30, invalid output on `medium`, invalid output on `big`. Its stored outputs total 869,709. |
| `hashcode2017-jamp-pizza_renuo` | No record. Its stored outputs total 273,582. |
| `hashcode2017-practice_Freeways` | No record. |
| `hashcode2017-practice_ishmaelmakitla` | No record. |
| `hashcode2017-practice_LostVariables` | Screen and a 10-minute run: small 42, no valid output on `medium`, no valid output on `big`. |
| `hashcode2017-practice_Nasvera` | No record. |
| `HashCode2017-practiseProblem_fgadea` | No record. |
| `hashcode2017_alreadytaikeune` | No record. |
| `HashCode2017_DanielGorlo` | No record. |
| `HashCode2017_Fellfalla` | No record. |
| `HashCode2017_ferquinz` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes. |
| `hashcode2017_KoenP` | Screen: small 35, invalid output on `medium`, no output on `big` in 5 minutes. It stores valid outputs only for `small` (35) and `big` (836). |
| `hashcode2017_LowikC` | Screen and a 10-minute run: small 42, no valid output on `medium`, out of memory on `big` at 6 GB. |
| `HashCode2017_mariaBianca` | No record. |
| `hashcode2017_mmtr` | Screen: small 38, medium 46,840, no output on `big` in 5 minutes. |
| `hashcode2017_moked` | No record. |
| `hashcode2017_Pcheape` | No record. It stores valid outputs only for `big` (526,259). |
| `HashCode2017_Pizza_NetBeans_baluteam` | No record. Its stored outputs total 616,500. |
| `HashCode2017_Pizza_ParisKitty` | No record. |
| `HashCode2017_Practice_ITSMarchi` | No record. |
| `hashcode2017_TeamRocketHashcode` | No record. |
| `hashcode2017_vaiol` | No record. |
| `HashCode2017_WilliamMajanja-zz` | No record. |
| `HashCode2017_YaZko` | No record. |
| `HashCode2017Pizza_ChrisBertrand` | Screen: small 27, invalid output on `medium`, invalid output on `big`. |
| `HashCode2017PizzaSlider_Onurus` | Screen: small 30, invalid output on `medium`, invalid output on `big`. Its stored outputs total 77,334. |
| `HashCode2017Warmup_stoman` | No record. It stores valid outputs only for `small` (42). |
| `hashcode2018-pizza_claudiosousa` | Screen: small 42, medium 46,593, no output on `big` in 5 minutes. Best of 2 programs. Its stored outputs total 846,753. |
| `hashcode2018-practise_Itope84` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes. |
| `Hashcode2018-Preparation_GambuzX` | No record. |
| `hashcode2018_DanieleMaisto` | No record. |
| `HashCode2018_JimNero009` | Screen: small 36, medium 3,331, no output on `big` in 5 minutes. |
| `hashcode2018_mmtr` | No record. |
| `hashcode2018_PaulienVa` | Screen: small 4, invalid output on `medium`, invalid output on `big`. |
| `hashcode2018_phischepi` | No record. |
| `hashCode2018_planga82` | Screen: small 5, medium 1,548, no output on `big` in 5 minutes. Its stored outputs total 82,025. |
| `hashcode2018_tirbal` | No record. |
| `Hashcode2018_zazizizou` | No record. |
| `Hashcode2018kapson_KapsonLabs` | No record. |
| `hashcode2018pizza_orbytegithub` | No record. |
| `HashCode2018Warmup_stoman` | No record. It stores valid outputs only for `small` (42). |
| `hashcode2018zaragoza_DavidRoyApp` | No record. |
| `hashcode2019-pizza_ellisvlad` | No record. |
| `HashCode2019_bshishov` | No record. |
| `HashCode2019_clemsage` | Screen: small 28, invalid output on `medium`, invalid output on `big`. |
| `HashCode2019_idyczko` | No record. |
| `Hashcode2019_mcamila777` | No record. |
| `hashcode2019_mcanalesmayo` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `Hashcode2019Practice_pzierahn` | No record. |
| `hashCode2020_aurensanx` | No record. Its stored outputs total 707,954. |
| `hashcode2021_gcoro` | No record. |
| `HashCode2021_KrutikaBhatt` | No record. It stores valid outputs only for `small` (20). |
| `HashCode_2017_practice_round_slaby93` | No record. |
| `hashcode_2018_practice_OddballGreg` | No record. |
| `hashcode_2019_josecyc` | No record. |
| `HashCode_arora-aditya` | No record. |
| `HashCode_HillaShx` | No record. |
| `hashCode_jagh` | No record. |
| `hashcode_Julien2313` | No record. |
| `HashCode_kartsridhar` | No record. |
| `HashCode_Pizza_karolkozak` | No record. Its stored outputs total 908,813. |
| `hashcode_pizza_ShivamShrirao` | No record. |
| `Hashcode_practice_2019_tieberthomas` | No record. |
| `hashcode_Shoomaher` | No record. |
| `hashcode_train_akpenou` | Screen and a 10-minute run: small 40, no valid output on `medium`, no output on `big` in 10 minutes. It stores valid outputs only for `small` (40) and `medium` (42,671). |
| `HashcodePizza_andresescobarcotan` | No record. |
| `HashCodePizza_boyski33` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `HashCodePizza_Brostafa` | No record. |
| `HashCodePizza_EddyCerpa` | Screen and a 10-minute run: small 42, no valid output on `medium`, no output on `big` in 10 minutes. |
| `HashCodePizza_JoaquinTrinanes` | Screen: small 32, medium 46,086, no output on `big` in 5 minutes. |
| `HashCodePizza_JoseLlorensRipolles` | No record. |
| `HashCodePizza_Nikoloutsos` | No record. |
| `HashcodePizza_nullhtp` | Screen: small 37, medium 47,680, no output on `big` in 5 minutes. |
| `HashCodePizza_RustamZakAs` | No record. |
| `HashCodePizza_Taity-mini` | No record. |
| `HashCodePizza_wdaniel1993` | No record. |
| `HashCodePractice2016_FantastiCode` | No record. |
| `HashCodePracticeProblem2019_JoseIgnacioRetamalThomsen` | Screen: small 30, invalid output on `medium`, invalid output on `big`. |
| `HashCodePratice2017_DropAllTables-bkp` | No record. |
| `HashCodeProblem2018_joseffffff` | No record. |
| `HashCodeQual2019_siowmeng` | No record. It stores valid outputs only for `medium` (39,603). |
| `HashPizza_kosyonikolov` | No record. |
| `HGC.slicePizza_DamCarduner` | No record. |
| `js_ocono_hashcode_test_sameersemna` | No record. |
| `pelicans-pizza_aurensanx` | No record. Its stored outputs total 644,544. |
| `Pizza-GoogleHashCode2018_joshiraez` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no valid output on `big`. |
| `pizza-hash_LukeDS-it` | No record. |
| `Pizza-Hashcode-Example-2018_titusmann` | No record. Its stored outputs total 196,422. |
| `Pizza-HashCode_diegologs` | No record. |
| `pizza-HashCode_guynnn` | No record. |
| `Pizza-HashCode_jesusjimsa` | No record. |
| `Pizza-HashCode_MahmoudMabrok` | No record. It stores valid outputs only for `big` (665,622). |
| `pizza-problem-hash-code_kshikha818` | No record. |
| `Pizza-Problem_mrknockturnal` | No record. |
| `pizza-slicing_stemlaur` | No record. |
| `Pizza-WarmUp_MadonnasPlays` | Screen: small 2, invalid output on `medium`, invalid output on `big`. |
| `Pizza_adamjin` | No record. |
| `Pizza_alexdoloz` | No record. |
| `pizza_bbrincat` | No record. |
| `Pizza_danielfleischer` | No record. |
| `pizza_google_hashcode_tod01` | No record. |
| `pizza_GoogleHashCode_2017_wawrzy` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `Pizza_HASH_CODE_vuslysty` | Screen and a 10-minute run: no valid output on `small`, no valid output on `medium`, no output on `big` in 10 minutes. |
| `Pizza_itcherry` | No record. |
| `pizza_kemo71` | No record. |
| `Pizza_mehmetbarisyaman` | No record. |
| `pizza_pbarbero` | No record. |
| `Pizza_Ratchet-Studios` | No record. |
| `pizza_Rwothoromo` | No record. |
| `Pizza_Tifzou` | No record. |
| `pizza_veselypeta` | No record. |
| `Pizza_yoann-dufresne` | No record. |
| `PizzaHashCode2018BruteforceSolution_abaft` | Screen and a 10-minute run: no valid output on `small`, no output on `medium` in 10 minutes, no output on `big` in 10 minutes. |
| `PizzaHashCode_Belterius` | No record. |
| `pizzaHashCode_JonathanWoollett-Light` | No record. |
| `PizzaProblem_gitaumoses4` | Screen: small 27, invalid output on `medium`, invalid output on `big`. It stores valid outputs only for `small` (27) and `medium` (1,860). |
| `PizzaProblem_martinajir` | No record. |
| `pizzapuzzle_jacksono` | No record. |
| `PizzaSlicer_sachinjegaonkar` | No record. It stores valid outputs only for `small` (30). |
| `practice_hashcode_2017_WestleyB` | No record. |
| `suha17_Laged` | No record. |
| `The-Pizza-Problem_SimonIyamu` | No record. |

## What may understate a program

- **Programs were pinned to one core.** `Google-HashCode_danicrg` runs its orderings in threads and got one core.
- **The 10-minute limit stops several programs,** among them `guillotine_block_dynamic_programming` on `big` and six removed repositories whose stored totals are above 911,228 but which wrote no valid `big` output in our runs.
- **We ran default parameters.** Tuned settings, like those behind some stored outputs, can score higher.
- **Invalid outputs count as 0.**
- **Lost records.** 153 removed repositories have no record after the restart. None of them reached the 5% line in our runs, because every program that scored 869,709 or more at the screen is accounted for above, but we cannot say which of them ran.
- **Not run:** the licensed programs in `google-hash-code-solutions_jp172` (Gurobi), `hashcode_pizza_2018_yoann-dufresne` (Gurobi) and `hashcode-2018_clemkoa` (LocalSolver).
