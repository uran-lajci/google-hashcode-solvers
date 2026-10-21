# Software Engineering at Scale

Google Hash Code 2021, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2021/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2021/final).

## Why only four solvers

Only four solvers are kept. They were chosen by hand after every collected solver was benchmarked on instances B–F (10-minute limit, 10 runs for randomized solvers, official judge). The choice, every solver's scores and the protocol are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers now live in [`solvers/`](solvers/) under method names, with their benchmark outputs in [`output/`](output/). Kept: `google-hashcode-2021_Loicyeu` as two solvers, strategy 1 (257.0 M over B–F) and strategy 2 as published (250.7 M); `feature-assignment_Pankin610` (255.6 M); and `HashCode2021_EndritMeziu`, the only one that moves services and creates binaries (best output on F, 150.7 M, but only 12 of its 50 runs are valid). The other three are listed under *Removed after benchmarking* below.

## Collected solvers

3 solvers: 2 documented by hand (details below the tables) and 1 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`google-hashcode-2021_Loicyeu`](google-hashcode-2021_Loicyeu/) | Python 3 | Strategy 1: A 540, B 11,552,060, C 24,778,969, D 73,299,742, E 35,821,807, F 111,547,554 (257,000,672) |
| [`feature-assignment_Pankin610`](feature-assignment_Pankin610/) | C++ (Bazel) | No scores reported (`run_all_tests.sh` runs all inputs) |

### Imported in bulk

Folder names are `<repo>_<owner>`. Commit is the snapshot imported (`.git` removed); *Notes* quotes the first descriptive line of the repo's own README, unedited.

| Folder | Source | Commit (history) | Language | Notes |
|---|---|---|---|---|
| [`HashCode2021_EndritMeziu`](HashCode2021_EndritMeziu/) | [EndritMeziu/HashCode2021](https://github.com/EndritMeziu/HashCode2021) | `95d85b6` (2022-09-23 → 2022-09-23, 1 commit) | C# | 6 official input copies removed (see list below). |

### [`google-hashcode-2021_Loicyeu/`](google-hashcode-2021_Loicyeu/)

- **Source:** https://github.com/Loicyeu/google-hashcode-2021
- **Snapshot:** GitHub clone at commit `42555c6` (history 2021-10-26 → 2022-01-20); `.git` removed on import.
- **Origin:** Student project from the *Poly#* (PolyHash) 2021 course at Polytech Nantes (Université de Nantes). Code and comments are mostly in French. Originally hosted at https://gitlab.univ-nantes.fr/polyhash-n/polyhash.
- **Authors:** Killian Blain, Nathan Charpentier, Loïc Henry, Yousri Lajnef (team N, "Napoléon")
- **Language:** Python 3
- **Approach:** Only implements features (no binary creation or service moves). Strategy 1 sorts features by computed ratios and gives each to the least-busy engineer. Strategy 2 also looks ahead at the next few features and picks the one with the best score that can still finish in time.
- **Scores:** Strategy 1: A 540, B 11,552,060, C 24,778,969, D 73,299,742, E 35,821,807, F 111,547,554 (257,000,672). The README also gives strategy 2 scores and run times. These are the program's own scores; the official judge gives the same strategy 1 plans D 73,298,662 and F 111,567,670.
- **Bundled inputs:** None bundled.
- **Run:** `python3 polyhash.py <input>` from a folder that has a `solutions/` subfolder; it writes one plan per feature order there (26 files)
- **Benchmarked as two solvers:** strategy 2 as published (`main()` calls `strategie2`) and strategy 1 (`main()` switched to `strategie1`, which upstream leaves commented out). Both were kept.
- **Removed on import:** 6 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

### [`feature-assignment_Pankin610/`](feature-assignment_Pankin610/)

- **Source:** https://github.com/Pankin610/feature-assignment
- **Snapshot:** GitHub clone at commit `e7c46e8` (history 2023-01-03 → 2023-01-10); `.git` removed on import.
- **Origin:** Self-study project.
- **Authors:** Pankin610
- **Language:** C++ (Bazel)
- **Approach:** Event-queue simulation of engineers, binaries and features, with a producer-based solver. Producers include "first take" and "ordered feature implementation". Has unit tests for the state model and the solver.
- **Scores:** No scores reported (`run_all_tests.sh` runs all inputs).
- **Bundled inputs:** `hashcode_tests/`: the six official inputs (`.in.txt`).
- **Run:** `bazel run //binary:run_solution -- <input>`, or `./run_all_tests.sh`
- **Removed on import:** 6 files byte-identical to official archive inputs (listed under *Official inputs removed* below).

## Removed after benchmarking

These three solvers were benchmarked (or, if they write no submission, examined) on 2026-10-20 and 2026-10-21 and then deleted from the collection (see *Why only four solvers* above). Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has every score.

- `polyhash_E191997S` (https://gitlab.univ-nantes.fr/E191997S/polyhash): not selected: deterministic users/difficulty greedy, 181.08 M over B–F (36th of the 38 finalist teams).
- `hashcode-practice-2021-finals_AlexeyZhuravlev` (https://github.com/AlexeyZhuravlev/hashcode-practice-2021-finals): not selected: `danya.cpp` scored 101.02 M over B–F and is invalid on E (it lists engineers with no tasks); its seed has no effect on the output. `lexa.cpp`, `timur.cpp` and `template.cpp` are empty templates and `dima.cpp` prints the example answer.
- `HashCode2022_Nanored4498` (https://github.com/Nanored4498/HashCode2022, `2021/Final/solution.cpp`): never writes a submission: it only prints its own score to stderr (the README's 275,305,718 is that self-computed total), so it cannot be scored.

## Official inputs removed

18 files in 3 solvers were byte-identical copies of official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) and were deleted to keep the collection small. To run a solver, copy the archive file back to the listed path.

<details><summary><code>feature-assignment_Pankin610</code> (6 files)</summary>

- `hashcode_tests/a_example.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/a_example.in.txt`
- `hashcode_tests/b_breadth_of_choice.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/b_breadth_of_choice.in.txt`
- `hashcode_tests/c_constrained_optimisation.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/c_constrained_optimisation.in.txt`
- `hashcode_tests/d_distinction.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/d_distinction.in.txt`
- `hashcode_tests/e_expectation_maximisation.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/e_expectation_maximisation.in.txt`
- `hashcode_tests/f_five_thousand.in.txt` ← `archive/2021/final/hashcode_2021_final_round.in/f_five_thousand.in.txt`

</details>

<details><summary><code>google-hashcode-2021_Loicyeu</code> (6 files)</summary>

- `challenges/an_example.txt` ← `archive/2021/final/hashcode_2021_final_round.in/a_example.in.txt`
- `challenges/breadth_of_choice.txt` ← `archive/2021/final/hashcode_2021_final_round.in/b_breadth_of_choice.in.txt`
- `challenges/constrained_optimisation.txt` ← `archive/2021/final/hashcode_2021_final_round.in/c_constrained_optimisation.in.txt`
- `challenges/distinction.txt` ← `archive/2021/final/hashcode_2021_final_round.in/d_distinction.in.txt`
- `challenges/expectation_maximisation.txt` ← `archive/2021/final/hashcode_2021_final_round.in/e_expectation_maximisation.in.txt`
- `challenges/five_thousand.txt` ← `archive/2021/final/hashcode_2021_final_round.in/f_five_thousand.in.txt`

</details>

<details><summary><code>HashCode2021_EndritMeziu</code> (6 files)</summary>

- `HashCode2021/Instances/an_example.txt` ← `archive/2021/final/hashcode_2021_final_round.in/a_example.in.txt`
- `HashCode2021/Instances/breadth_of_choice.txt` ← `archive/2021/final/hashcode_2021_final_round.in/b_breadth_of_choice.in.txt`
- `HashCode2021/Instances/constrained_optimisation.txt` ← `archive/2021/final/hashcode_2021_final_round.in/c_constrained_optimisation.in.txt`
- `HashCode2021/Instances/distinction.txt` ← `archive/2021/final/hashcode_2021_final_round.in/d_distinction.in.txt`
- `HashCode2021/Instances/expectation_maximisation.txt` ← `archive/2021/final/hashcode_2021_final_round.in/e_expectation_maximisation.in.txt`
- `HashCode2021/Instances/five_thousand.txt` ← `archive/2021/final/hashcode_2021_final_round.in/f_five_thousand.in.txt`

</details>
