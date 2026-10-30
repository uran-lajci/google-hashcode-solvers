# City Plan

Google Hash Code 2018, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2018/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2018/final).

## Why only two solvers

Two solvers are kept, both from one of the 13 collected repositories. A solver is kept if it is first on an instance, or if the sum of its per-instance means is within 5% of the best total in the competition (at least 36,197,649, 95% of 38,102,788). A first screen ran every usable program on instances B–F with one seed and a 5-minute limit. The programs that could still be competitive then went through the full protocol (10-minute limit, 10 runs for randomized solvers, official judge). The rule, every program's scores and the protocol are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers now live in [`solvers/`](solvers/) under method names, with their benchmark outputs in [`output/`](output/). Kept: the two programs of `Google-Hash-Code-2018-Final-Round_mihai-bontea`: `sol2`, first on B, D, E and F, and `sol1`, first on C. Neither reaches the 5% line, so both are kept for being first on an instance. The other 12 repositories are listed under *Removed after benchmarking* below.

## Collected solvers

2 solvers: 2 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/row_sweep_best_gain_greedy`](solvers/row_sweep_best_gain_greedy/) | C++ | sol1: A 100, B 3,825,406, C 8,770,728, D 7,587,032, E 4,795,290, F 4,940,263 (29,918,819) |
| [`solvers/size_penalized_greedy_hill_climbing`](solvers/size_penalized_greedy_hill_climbing/) | C++ | sol2: A 100, B 4,895,099, C 8,440,605, D 7,897,054, E 4,789,890, F 7,010,895 (33,033,643) |

### [`solvers/row_sweep_best_gain_greedy/`](solvers/row_sweep_best_gain_greedy/)

- **Source:** https://github.com/mihai-bontea/Google-Hash-Code-2018-Final-Round
- **Snapshot:** GitHub clone at commit `3c64372` (history 2025-05-07 → 2025-10-04); `.git` removed on import. Only `sol1/`, `output_files/sol1/`, the validator, the visualizer and the repo's README were copied. The repo has no LICENSE.
- **Origin:** Independent post-contest project.
- **Authors:** Mihai Bontea
- **Language:** C++ (+ Python validator and visualiser)
- **Approach:** Sweep the map row by row and, at each free cell, place the building that adds the most points right away, with a collision map.
- **Scores:** The repo's README: 29,918,819 over A–F. The stored outputs score 29,976,121 over B–F with the official judge, with different scores from the README's on B, C and D.
- **Bundled inputs:** None bundled.
- **Run:** In `sol1/`: `g++ -O3 -std=c++23 -fopenmp -o solve main.cpp`; `main.cpp` reads `../../input_files/` and writes `../../output_files/sol1/`
- **Benchmark:** B 3,999,070, C 8,693,408, D 7,740,180, E 4,799,060, F 5,134,486 (30,366,204), first on C ([scores](output/row_sweep_best_gain_greedy/scores.md)).

### [`solvers/size_penalized_greedy_hill_climbing/`](solvers/size_penalized_greedy_hill_climbing/)

- **Source:** https://github.com/mihai-bontea/Google-Hash-Code-2018-Final-Round
- **Snapshot:** GitHub clone at commit `3c64372` (history 2025-05-07 → 2025-10-04); `.git` removed on import. Only `sol2/`, `output_files/sol2/`, the validator, the visualizer and the repo's README were copied. The repo has no LICENSE.
- **Origin:** Independent post-contest project.
- **Authors:** Mihai Bontea
- **Language:** C++ (+ Python validator and visualiser)
- **Approach:** The same row sweep with a size penalty, then 10 minutes of hill climbing that removes a random building and puts the best-scoring one at that position.
- **Scores:** The repo's README: 33,033,643 over A–F, which the stored outputs confirm with the official judge.
- **Bundled inputs:** None bundled.
- **Run:** In `sol2/`: `g++ -O3 -std=c++23 -fopenmp -o solve main.cpp`; `main.cpp` reads `../../input_files/` and writes `../../output_files/sol2/`
- **Benchmark:** best of 10 seeds, with mean in brackets: B 4,906,081 (4,902,995), C 8,616,236 (8,610,296), D 7,750,808 (7,748,090), E 4,803,980 (4,803,858), F 7,004,244 (7,003,430); sum of means 33,068,670, first on B, D, E and F ([scores](output/size_penalized_greedy_hill_climbing/scores.md)).

## Removed after benchmarking

These 12 repositories were benchmarked (or, if they cannot be run, examined) on 2026-10-30 and then deleted from the collection (see *Why only two solvers* above). Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has every score. The last two entries were never collected: they were examined at import and hold no solver.

- `hashcode-2018_HofmannZ` (https://github.com/HofmannZ/hashcode-2018): not selected: the Dart programs total 21,323,014, and none is first on an instance. Its C++ program totals 2,822,577 and crashes on F.
- `HashCode_arriopolis` (https://github.com/arriopolis/HashCode): not selected: `greedy_dual` totals 22,870,144, and none is first on an instance. The other programs score less, crash or never write a submission.
- `Google-Hashcode2018_DamienCvl` (https://github.com/DamienCvl/Google-Hashcode2018): not selected: 14,302,658, with B 4,563,527 its only close result.
- `google-hashcode-2018_AntoineMrj` (https://github.com/AntoineMrj/google-hashcode-2018): not selected: 9,683,570 at the screen, with no output on D within 10 minutes.
- `PolyHash2018_thomas-peuziat` (https://github.com/thomas-peuziat/PolyHash2018): not selected: 6,887,728 at the screen. Its README reports about 14.2 M after about 24 h per large input.
- `hashcode18-19_kjanko` (https://github.com/kjanko/hashcode18-19): not selected: 6,125,354 at the screen, against 35,812,865 (9th place) in its README, which would still be below the 5% line.
- `Google-HashCode-Polyhash-2018_PierreLeGuen` (https://github.com/PierreLeGuen/Google-HashCode-Polyhash-2018): not selected: at most 3,771,662 at the screen and the 10-minute runs.
- `polyhash-mjbm` (source URL not recorded): not selected: the genetic program totals 1,871,566, and the grid program writes nothing within 10 minutes.
- `Google-HashCode-2018_robert-panduru` (https://github.com/robert-panduru/Google-HashCode-2018): not selected: no output on any instance within 10 minutes.
- `CityPlan_kostyaHrytsyuk` (https://github.com/kostyaHrytsyuk/CityPlan): not selected: the judge rejects its output format on every instance.
- `HashCode_HillaShx` (https://github.com/HillaShx/HashCode): cannot run: it stops with a `NameError` because `deepcopy` is never imported.
- `hashcode2018-city-plan_afonsoafonsoafonso` (https://github.com/afonsoafonsoafonso/hashcode2018-city-plan): not scored: an interactive program that never writes a submission.
- `Hamdaoui1/Algo-Skel-CityPlan` (Java, `36a9449`): a course skeleton that validates building plans and places two buildings by hand on a toy map. It has no solver.
- `Tejpbit/google-hashcode-2018-final` (Kotlin, `b8a19dc`): the Gradle scaffold only; `main.kt` is two lines.

## Duplicates removed during import

- [simonbhh/googlehashcode2018](https://github.com/simonbhh/googlehashcode2018) (`e79b162`): same source code (after normalising line endings and whitespace) as `google-hashcode-2018_AntoineMrj`.
