# Software Engineering at Scale: choosing the solvers

Google Hash Code 2021, Final round. Six public solver repositories were collected and benchmarked under the same
rules. From the results, four solvers were chosen by hand and the rest were removed.

## What we did

1. **Collected.** We searched GitHub and GitLab and found 6 solver repositories for this problem. Files byte-identical
   to the official inputs were deleted (they are listed in [README.md](README.md)).
2. **Benchmarked (first round, every usable program).** Instances B–F. A is a toy example and was left out.
   - Deterministic solvers got 1 run each. Randomized ones got 10 runs, with seeds 1, 12, 23, 34, 45, 56, 67, 78,
     89, 100. `EndritMeziu` cannot be seeded (unseeded `new Random()` and `Guid.NewGuid()`), so its 10 runs carry
     these numbers only as labels and cannot be reproduced.
   - Each run had a 10-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/software_engineering_at_scale/judge.py`.
     A run whose output the judge rejects counts as 0.
   - Code changes were limited to the seed, the input/output paths and the 10-minute stop. Two C++ programs needed
     `-include` compiler flags to build with GCC 13; their source is unchanged. Programs that write no submission,
     or are stubs, were marked unusable and not scored.
   - `Loicyeu` ships two strategies, and its `main()` runs only strategy 2. It was benchmarked twice: as published, and
     with `main()` switched to strategy 1, the one its README reports scores for.
   - `EndritMeziu`'s first time-limit patch only stopped its search loops. On C its construction alone takes more
     than 10 minutes, so it wrote nothing. The patch was extended to its construction loop as well, and all 50 runs
     were repeated with the final patch. Only those runs are reported.
3. **Selected.** From the first-round results, we chose four solvers by hand (table below). The other programs were
   deleted from the collection; their sources are linked in [README.md](README.md).
4. **Renamed and re-ran.** The four kept solvers now live in [solvers/](solvers/). Each is named after its method, and
   its README starts with a header giving the source URL and an overview of the method. All four were run again under
   the same protocol, from the new folders. The outputs and per-run scores are in [output/](output/).

## Chosen and ignored

First-round results, best run per instance (official judge). For `EndritMeziu` the number of valid runs out of 10 is
given in brackets; the four deterministic programs have one run each and `danya.cpp` gives the same output for every
seed. "Placement" puts the sum over B–F among the 38 finalist teams of 2021 (whose totals also include A, worth at
most a few hundred points).

| Collected solver | Decision | B | C | D | E | F | Sum B–F | Placement |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| `google-hashcode-2021_Loicyeu`, strategy 1 | **chosen** | 11,552,060 | 24,778,969 | 73,298,662 | 35,821,807 | 111,567,670 | 257,019,168 | 33 |
| `feature-assignment_Pankin610` | **chosen** | 11,591,350 | 23,600,735 | 73,226,608 | 35,650,621 | 111,540,577 | 255,609,891 | 33 |
| `google-hashcode-2021_Loicyeu`, strategy 2 (as published) | **chosen** | 5,543,662 | 24,881,270 | 73,185,071 | 35,821,807 | 111,280,279 | 250,712,089 | 35 |
| `HashCode2021_EndritMeziu` | **chosen** | invalid (0/10) | 119,544 (9/10) | 91,104,403 (1/10) | invalid (0/10) | 150,722,934 (2/10) | 241,946,881 | 35 |
| `polyhash_E191997S` | ignored | 10,375,250 | 23,626,824 | 44,118,001 | 35,583,325 | 67,372,399 | 181,075,799 | 36 |
| `hashcode-practice-2021-finals_AlexeyZhuravlev`, `danya.cpp` | ignored | 9,681,820 | 24,811,231 | 24,412,183 | invalid | 42,111,407 | 101,016,641 | 36 |
| `hashcode-practice-2021-finals_AlexeyZhuravlev`, `lexa.cpp`, `timur.cpp`, `template.cpp`, `dima.cpp` | ignored | — | — | — | — | — | not scored | — |
| `HashCode2022_Nanored4498` (`2021/Final/solution.cpp`) | ignored | — | — | — | — | — | not scored | — |

`EndritMeziu`'s sum of mean scores is only 39,306,910, because most of its outputs are invalid. It is still the only
solver here that moves services and creates binaries, which is what lifts its valid F runs to about 150 M; the others
reach about 111.5 M on F.

**Chosen** (with what stands out in each one's results):

- Strategy 1 of `Loicyeu`, as [ratio_sorted_greedy_least_busy](solvers/ratio_sorted_greedy_least_busy/): the highest
  sum over B–F.
- `Pankin610`, as [event_queue_ordered_feature_greedy](solvers/event_queue_ordered_feature_greedy/): the best score
  on B and the second-best sum. It is also the fastest, under 2 s per instance.
- Strategy 2 of `Loicyeu`, as published, as [ratio_sorted_lookahead_greedy](solvers/ratio_sorted_lookahead_greedy/):
  the best score on C.
- `EndritMeziu`, as [tabu_search_random_greedy](solvers/tabu_search_random_greedy/): the best scores on D and F, and
  the only solver that uses service moves and new binaries.

**Ignored:**

- `polyhash_E191997S`: a deterministic users/difficulty greedy. It is valid on every instance but lower than the
  chosen deterministic solvers on all five (181.08 M in total).
- `danya.cpp` of `AlexeyZhuravlev`: 101.02 M in total. It is invalid on E, because it lists engineers with no tasks
  (the statement requires at least one), and its seed has no effect on the output.
- The rest of `AlexeyZhuravlev`: `lexa.cpp`, `timur.cpp` and `template.cpp` are the empty team template, and
  `dima.cpp` prints the example's answer for every input.
- `Nanored4498`: `solution.cpp` never writes a submission. It builds a schedule internally and prints only its own
  score; the 275,305,718 in its README is that self-computed total, so it cannot be checked.

| Solver | Upstream | Method |
|---|---|---|
| [ratio_sorted_greedy_least_busy](solvers/ratio_sorted_greedy_least_busy/) | Loicyeu/google-hashcode-2021, strategy 1 (Python) | Sorts the features in 26 orders (13 ratio keys × 2 directions). For each order, gives every binary of each feature to the least-busy engineer. Keeps the best of the 26 plans. |
| [event_queue_ordered_feature_greedy](solvers/event_queue_ordered_feature_greedy/) | Pankin610/feature-assignment (C++) | Sorts the features once by users ÷ (difficulty × binaries). An event-queue simulation then lets every free engineer start the first feature/binary pair that nobody is working on. |
| [ratio_sorted_lookahead_greedy](solvers/ratio_sorted_lookahead_greedy/) | Loicyeu/google-hashcode-2021, strategy 2 as published (Python) | Strategy 1 with a look-ahead over the next five features. Its score estimate is always 0, so in practice it skips features that can no longer finish in time. |
| [tabu_search_random_greedy](solvers/tabu_search_random_greedy/) | EndritMeziu/HashCode2021 (C#) | A randomized day-by-day greedy that also creates binaries and moves services, followed by a tabu search that swaps two `impl` tasks of an engineer. |

## Best scores (B–F, re-run from `solvers/`, official judge)

Best run per instance, with the number of valid runs out of 10 for the randomized solver. Bold marks the highest
score on each instance.

| Solver | B | C | D | E | F | Sum of bests | Sum of means |
|---|---:|---:|---:|---:|---:|---:|---:|
| [ratio_sorted_greedy_least_busy](output/ratio_sorted_greedy_least_busy/scores.md) | 11,552,060 | 24,778,969 | 73,298,662 | **35,821,807** | 111,567,670 | 257,019,168 | 257,019,168 |
| [event_queue_ordered_feature_greedy](output/event_queue_ordered_feature_greedy/scores.md) | **11,591,350** | 23,600,735 | 73,226,608 | 35,650,621 | 111,540,577 | 255,609,891 | 255,609,891 |
| [ratio_sorted_lookahead_greedy](output/ratio_sorted_lookahead_greedy/scores.md) | 5,543,662 | **24,881,270** | 73,185,071 | **35,821,807** | 111,280,279 | 250,712,089 | 250,712,089 |
| [tabu_search_random_greedy](output/tabu_search_random_greedy/scores.md) | invalid (0/10) | 116,430 (9/10) | **90,709,511** (1/10) | invalid (0/10) | **151,177,982** (5/10) | 242,003,923 | 84,670,782 |

Taking the best output for each instance gives 314,181,920 over B–F, which would place 7th of the 38 finalist teams.
Without tabu_search_random_greedy it is 257,160,759 (33rd).

- The three deterministic solvers gave byte-identical outputs to the first round, so moving them into `solvers/`
  changed nothing.
- tabu_search_random_greedy cannot be seeded, so its re-run differs from the first round (15 valid runs out of 50
  this time, 12 the first time).
- Weak spots:
  - tabu_search_random_greedy is invalid on every run of B and E and on 9 of 10 runs of D. On C its construction
    does not finish within the 10 minutes, so its C scores come from partial plans.
  - ratio_sorted_lookahead_greedy gets about half of strategy 1's score on B (5.54 M against 11.55 M).

Per-run tables and timings are in `output/<solver>/scores.md`.

## How we ran them

All four need the official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive)
(`archive/2021/final/hashcode_2021_final_round.in/`). Each benchmark run was wrapped as
`taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/software_engineering_at_scale/judge.py -i <input>.in.txt -o <output>.out
```

| Solver | Build and run | Changes for the benchmark (made to a copy; `solvers/` is untouched) |
|---|---|---|
| ratio_sorted_greedy_least_busy | `mkdir solutions && python3 polyhash.py b_breadth_of_choice.in.txt` (Python 3.12, `PYTHONHASHSEED=0`) | None. Of the 26 plans written to `solutions/`, the one the judge scores highest is the submission. |
| event_queue_ordered_feature_greedy | `g++ -O2 -std=c++17 -I. -include stdexcept -include algorithm -o run_solution binary/run_solution.cpp sol/producer_based_solver.cpp sol/ordered_feature_implementation_producer.cpp sol/solution.cpp state/*.cpp`<br>`./run_solution < b_breadth_of_choice.in.txt > b.out` | None. Upstream builds with Bazel, which was not used; these are the Bazel target's sources. |
| ratio_sorted_lookahead_greedy | as ratio_sorted_greedy_least_busy | None. |
| tabu_search_random_greedy | `dotnet build -c Release HashCode2021/HashCode2021.csproj` (.NET 6 SDK)<br>`dotnet HashCode2021/bin/Release/net6.0/HashCode2021.dll <input> <output> <tabu file>` | The three hard-coded Windows paths are read from the command line. A 590 s stop was added in the construction's day loop, the restart loop and the tabu loop, after which the program writes its plan as usual. It cannot be seeded. |

Instances C–F use the same commands with the file name changed. The full setup notes for each solver are in the
*Run setup* section of its `output/<solver>/scores.md`.
