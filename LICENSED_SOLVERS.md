# Licensed solvers

Solvers in this collection that need a Gurobi or CPLEX license. These programs cannot be benchmarked without one, so a benchmark run without a license skips them. The repositories stay in their problem folders.

They were identified by reading the code, without running it. Solvers that use free exact methods, such as CP-SAT, SCIP or CBC, are not listed here because they can be benchmarked like any other solver.

*Stored score* is the total of the output files stored in the repository, scored with the official judge, as a share of the top score on the scoreboard. The practice rounds have no scoreboard, so Pizza, More Pizza and One Pizza use the best stored score in the collection instead. A dash means the repository does not store outputs for all of the main instances. Stored outputs may not come from the listed licensed program.

## Every solver needs a license (13)

| Problem | Repository | Solver | Licensed program | Stored score |
|---|---|---|---|---:|
| Optimize a Data Center | [`google-hash-code-solutions_jp172`](optimize_a_data_center/google-hash-code-solutions_jp172/) | Gurobi | `2015-quali/src/main.cpp` | — |
| Optimize a Data Center | [`hashcodeDataCenterOptmization_vilelabruno`](optimize_a_data_center/hashcodeDataCenterOptmization_vilelabruno/) | CPLEX | `DataCenterOpt.java` | — |
| Pizza | [`google-hash-code-solutions_jp172`](pizza/google-hash-code-solutions_jp172/) | Gurobi | `warmup-pizza/src/main.cpp` | — |
| Streaming Videos | [`M2_Optimisation_Algorithmes_et_Data_VictorBousseau`](streaming_videos/M2_Optimisation_Algorithmes_et_Data_VictorBousseau/) | Gurobi | `ProjetOptimisation/videos.py` | — |
| Streaming Videos | [`Projet_Opti_MatthiasJourdren`](streaming_videos/Projet_Opti_MatthiasJourdren/) | Gurobi | `videos.py` | — |
| Streaming Videos | [`hashcode_streamingvideos_faelitu`](streaming_videos/hashcode_streamingvideos_faelitu/) | CPLEX | `YoutubeOpt.java` | — |
| Photo Slideshow | [`Evaluation-hashcode-2019-optimizer-Loris-POHU-_Loris44150`](photo_slideshow/Evaluation-hashcode-2019-optimizer-Loris-POHU-_Loris44150/) | Gurobi | `slideshow.py` | — |
| Photo Slideshow | [`hashcode-2019-optimizer-Loris-POHU_Loris44150`](photo_slideshow/hashcode-2019-optimizer-Loris-POHU_Loris44150/) | Gurobi | `slideshow.py` | — |
| More Pizza | [`google-hash-code-more-pizza_lucas7bm`](more_pizza/google-hash-code-more-pizza_lucas7bm/) | CPLEX through PuLP | `more-pizza.py`, with a hardcoded CPLEX path | — |
| More Pizza | [`hashcode_morepizza_faelitu`](more_pizza/hashcode_morepizza_faelitu/) | CPLEX | `Pizza.java` | — |
| Book Scanning | [`BachelorThesis_AminDovigo`](book_scanning/BachelorThesis_AminDovigo/) | CPLEX through Pyomo | `modelloaggconcrete.py` | — |
| Book Scanning | [`google-hash-code-solutions_jp172`](book_scanning/google-hash-code-solutions_jp172/) | Gurobi | `2020-quali/src/main.cpp` | — |
| One Pizza | [`Google-HashCode-2022_filipesouzacit`](one_pizza/Google-HashCode-2022_filipesouzacit/) | Gurobi | `gurobi.py` | 99.9% |

## Some programs run without a license (12)

Only the licensed program is skipped. The other programs are benchmarked as usual.

| Problem | Repository | Solver | Licensed program | Runs without a license | Stored score |
|---|---|---|---|---|---:|
| Optimize a Data Center | [`OptimizeDatacenter_Hashcode2015_exo404`](optimize_a_data_center/OptimizeDatacenter_Hashcode2015_exo404/) | Gurobi | `test/ottima.py` | `eurGreedy.py` | — |
| Pizza | [`hashcode_pizza_2018_yoann-dufresne`](pizza/hashcode_pizza_2018_yoann-dufresne/) | Gurobi | `solver_gurobi.py` | `solver_hill_climbing.py`, `solver_random.py` | — |
| Router Placement | [`hashcode17_finals_matteojug`](router_placement/hashcode17_finals_matteojug/) | CPLEX | `cplex/test.cpp` | `main.cpp` | 99.3% |
| Self-driving Rides | [`hashCodeQualif_bitqr`](self_driving_rides/hashCodeQualif_bitqr/) | CPLEX | `ExactModel.java` | `Main.java` | — |
| Photo Slideshow | [`RP_HashCode_2019_lucasschott`](photo_slideshow/RP_HashCode_2019_lucasschott/) | Gurobi | `Ilp.cpp` | `Annealing.cpp`, `Greedy.cpp`, `Stoch_descent.cpp` | — |
| More Pizza | [`PLI_vs_GA-Hashcode2020_giuseppe-maglione`](more_pizza/PLI_vs_GA-Hashcode2020_giuseppe-maglione/) | Gurobi | `pli_solution.py` | `genetic_solution.py` | — |
| Book Scanning | [`Hashcode2k20_sbrodehl`](book_scanning/Hashcode2k20_sbrodehl/) | Gurobi | `solver/GurobiSolver.py` | `solver/GreedyFirst.py` (`main.py` imports every solver, so `gurobipy` must be installed) | 99.6% |
| Book Scanning | [`hashcode-2020_adnaneh`](book_scanning/hashcode-2020_adnaneh/) | Gurobi | `hashcode.py`, `main.py` | `hash_quentin.py` | — |
| Book Scanning | [`hashcode2020_HaKaen`](book_scanning/hashcode2020_HaKaen/) | Gurobi | `practice/src/PizzaProblem.cpp` | `hashCode.cpp`, `hashCode_extended.cpp` | — |
| Traffic Signaling | [`hashcode-2021_ANazaret`](traffic_signaling/hashcode-2021_ANazaret/) | Gurobi | a notebook | `main_code.py` (CP-SAT) | 84.3% |
| One Pizza | [`hashcode2022_sbrodehl`](one_pizza/hashcode2022_sbrodehl/) | Gurobi | `solver/lp.py` | `solver/random.py`, `solver/graph.py` (`main.py` imports every solver, so `gurobipy` must be installed) | 99.9% |
| One Pizza | [`hashcode_2022_practice_round_dario-99`](one_pizza/hashcode_2022_practice_round_dario-99/) | Gurobi | `gurobi_sol.ipynb` | `hill_climbing.py`, `one_pizza_heuristic_greedy.py` | — |
