# Compiling Google: choosing the three best solvers

Google Hash Code 2019, Final round. Twelve public solver repositories were collected. They hold 28 programs that can be run, and three of those, from two repositories, were kept.

This is the first problem selected with a screening round, to spend the full protocol only on programs that can still win. The final protocol for the kept solvers is unchanged.

## What we did

1. **Collected.** We searched GitHub and GitLab and found 12 solver repositories for this problem. Files byte-identical to the official inputs were deleted. Each program in a repository was treated as its own solver.
2. **Screened (every usable program).** Instances B–F, A being a toy example.
   - Each program got 1 run, with seed 1 if it is randomized, and a 5-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/compiling_google/judge.py`. A run whose output the judge rejects counts as 0.
   - Code changes were limited to the seed and the input/output paths. Programs that cannot run or never write a submission were marked unusable and not scored.
   - Some programs needed more to run at all. `hashCode2019UI_mrDreaml` is a browser app, so it got a native build and a command-line driver with the UI's default parameters. `hashcode2019-final-round_danvixent` cannot be seeded, so its seeds are labels only. `g_hashcodes_kobr4` never seeds `rand()`, so a seed was added. `Hashcode-final-2019_LarsAstrom` ran on PyPy 2.7, as its README recommends, and the other Python programs on CPython 3.12.
   - The screen took 8 minutes for 116 runs, because most programs finish in seconds.
3. **Advanced.** A program went on if it is in the top 3 or within 20% of the best on any instance, or in the top 3 by total. Fifteen programs qualified. Two safeguards stopped the screen from rejecting a program on its own:
   - A program with no valid output at the limit got a full 10-minute run: `LarsAstrom improved` on E, `naive` on F, `Mogstene` on F and `kobr4 default` on F. `naive` and `Mogstene` then scored 0, and the other two still wrote nothing valid, so none of the four changed the outcome.
   - A randomized program with invalid output got 3 more seeds: `danvixent` and `kobr4 heuristic`. They stayed invalid.
4. **Full protocol.** The advanced programs got the first-round rules used for the other problems: a 10-minute limit, 10 seeds (1, 12, 23, 34, 45, 56, 67, 78, 89, 100) for randomized programs and 1 run for deterministic ones.
   - The deterministic programs were run a second time with a different `PYTHONHASHSEED`. Their outputs were byte-identical, except for `HashCode_arriopolis`, whose set ordering depends on the hash seed. So every `arriopolis` program got 10 hash seeds, including the ones that had not advanced.
   - Programs written for one instance were also run on the others, to test that assumption. None scored above 0 elsewhere. `e_solution.py` has its input hard-coded and could not be tried on the others.
5. **Selected.** A program is kept if it is first on an instance by its best result over all seeds, because the published tables report the best output. A program that only ties a kept solver adds nothing and was not kept. The other programs were deleted, and their sources are linked in [README.md](README.md).
6. **Renamed and re-ran.** The three kept solvers now live in [solvers/](solvers/). Each is named after its method, and its README starts with a header giving the source URL and an overview of the method. All three were run again under the full protocol. The outputs and per-seed scores are in [output/](output/).

## Chosen and ignored

Best run per instance (official judge). Bold marks the highest score on each instance. "Screen only" scores come from the single short run, or 4 runs for the two programs given more seeds; every `arriopolis` program has 10 hash seeds. "Placement" puts the sum over B–F among the 41 finalist teams of 2019, whose totals also include A (worth at most 60 points on the kept solvers).

| Program | Stage | B | C | D | E | F | Sum B–F | Placement |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| `HashCode2022_Nanored4498` | **chosen** | **1,530,065** | 1,934,841 | 1,250,354 | **524,288** | **840,971** | 6,080,519 | 7 |
| `Hashcode-final-2019_LarsAstrom`, `mm_sort_shuffle` | **chosen** | 1,482,186 | 1,456,275 | **1,277,337** | 1 | invalid | 4,215,799 | 31 |
| `Hashcode-final-2019_LarsAstrom`, `solve_c_la` | **chosen** | invalid | **1,950,379** | invalid | invalid | 0 | 1,950,379 | 39 |
| `Hashcode-final-2019_LarsAstrom`, `la_sort_on_target` | full protocol | 1,499,984 | 1,378,558 | 1,073,008 | 1 | invalid | 3,951,551 | 32 |
| `Hashcode-final-2019_LarsAstrom`, `improved` | full protocol | 1,503,171 | 1,384,545 | 934,863 | invalid | invalid | 3,822,579 | 33 |
| `HashCode_arriopolis`, `greedy_lower_bound_v2` | full protocol | 1,294,475 | 1,356,006 | 258,174 | 0 | invalid | 2,908,655 | 38 |
| `HashCode_arriopolis`, `greedy_lower_bound` | full protocol | 1,294,475 | 1,356,006 | 257,330 | 0 | 0 | 2,907,811 | 38 |
| `hashcode-2019-final-training_AlexeyZhuravlev`, `timur` | screen only | 923,044 | 1,145,099 | 682,528 | 0 | 0 | 2,750,671 | 38 |
| `HashCode_arriopolis`, `greedy_target_v2` | screen only | 664,793 | 1,299,626 | 737,834 | 0 | 0 | 2,702,253 | 38 |
| `HashCode_arriopolis`, `greedy` | full protocol | 1,294,475 | 1,267,563 | 0 | 0 | 0 | 2,562,038 | 38 |
| `hashcode-2019-final-training_AlexeyZhuravlev`, `lexa` | full protocol | 992,418 | 268,070 | 3,724 | 0 | **840,971** | 2,105,183 | 39 |
| `hashcode-2019-final-training_AlexeyZhuravlev`, `lexa2` | full protocol | 992,418 | 268,070 | 3,724 | 0 | **840,971** | 2,105,183 | 39 |
| `Hashcode-final-2019_LarsAstrom`, `naive` | full protocol | 1,484,604 | 58,042 | 0 | 0 | 0 | 1,542,646 | 40 |
| `hashcode-2019_nilswende` | screen only | 992,418 | 268,070 | invalid | 0 | 42,431 | 1,302,919 | 40 |
| `g_hashcodes_kobr4`, `bigdata` | screen only | 992,418 | 268,070 | 2,297 | 0 | 468 | 1,263,253 | 40 |
| `g_hashcodes_kobr4`, `default` | screen only | 992,418 | 268,070 | 2,113 | 0 | invalid | 1,262,601 | 40 |
| `hashCode2019UI_mrDreaml` | screen only | 272,558 | 408,804 | 239,470 | 0 | 0 | 920,832 | 41 |
| `Hashcode-final-2019_LarsAstrom`, `solve_f` | full protocol | invalid | invalid | invalid | invalid | **840,971** | 840,971 | 41 |
| `HashCode_arriopolis`, `Solver_f` | full protocol | invalid | invalid | invalid | invalid | **840,971** | 840,971 | 41 |
| `Google-HashCode-2019_Mogstene` | screen only | 559,465 | 126,822 | 0 | 1 | 0 | 686,288 | 41 |
| `Hashcode-final-2019_LarsAstrom`, `solve_c` | screen only | invalid | 524,288 | invalid | invalid | 0 | 524,288 | 41 |
| `Hashcode-final-2019_LarsAstrom`, `solve_e_mm` | full protocol | invalid | invalid | invalid | **524,288** | invalid | 524,288 | 41 |
| `HashCode_arriopolis`, `e_solution` | full protocol | — | — | — | **524,288** | — | 524,288 | 41 |
| `Hashcode-final-2019_LarsAstrom`, `supernaive_bm` | screen only | 262,991 | 0 | 0 | 1 | 0 | 262,992 | below all |
| `g_hashcodes_kobr4`, `heuristic` | screen only | invalid | invalid | invalid | 0 | 468 | 468 | below all |
| `HashCode_arriopolis`, `greedy_target` | screen only | 0 | 0 | 400 | 0 | invalid | 400 | below all |
| `hashcode2019-final-round_danvixent` | screen only | invalid | invalid | invalid | invalid | invalid | 0 | below all |

**Chosen:**

- `Nanored4498`, as [instance_tailored_target_scheduler](solvers/instance_tailored_target_scheduler/): the best score on B, the top scores on E and F, and by far the highest sum. It finishes each instance in under a second.
- `LarsAstrom solve_c_la`, as [subset_sum_partition_scheduler](solvers/subset_sum_partition_scheduler/): the best on C (1,950,379 against Nanored's 1,934,841). All 10 seeds beat Nanored; the worst scores 1,937,085.
- `LarsAstrom mm_sort_shuffle`, as [shuffled_deadline_order_greedy](solvers/shuffled_deadline_order_greedy/): the best result on D, 1,277,337 against Nanored's 1,250,354. Its mean over the seeds is lower (1,150,461), so this result depends on the seed.

**Ignored:**

- Ties: `solve_e_mm` and `e_solution` reach 524,288 on E, and `lexa`, `lexa2`, `Solver_f` and `solve_f` reach 840,971 on F. Nanored already has both scores.
- `LarsAstrom la_sort_on_target`, `improved` and `naive`: strong on B (up to 1,503,171), but behind Nanored on every instance.
- `arriopolis greedy`, `greedy_lower_bound`, `greedy_lower_bound_v2` and `greedy_target_v2`: first on no instance, on any of the 10 hash seeds.
- `AlexeyZhuravlev timur`, `nilswende`, `kobr4 default` and `bigdata`, `mrDreaml`, `Mogstene`, `LarsAstrom supernaive_bm` and `solve_c`, and `arriopolis greedy_target`: too far behind at the screen.
- `danvixent`: rejected on every run, because it lists files before the dependencies they need. `kobr4 heuristic` writes an empty plan on B and C and crashes on D.

**Not scored:**

- `compile_scheduler_lekemula`: it never writes a submission. `printResults` prints only `TOTAL SCORE`, and the line that would print the solution is commented out.
- `HashCode2019_ishaanzaveri`: `Module1.vb` reads `b_lovely_landscapes.txt`, so it solves Photo Slideshow, a different problem.
- `hashcode2021_gnitsua`: `practice/Solver.py` does not parse (a `for` loop with no body).
- `LarsAstrom improved2`: does not parse either (`def srting(finish_time,target.d,target.g):`). `solve.py` is the template's stub, and `analyze_e.py` and the other helper scripts are not solvers.
- `AlexeyZhuravlev miron`, `kinan` and `template`: the empty team template. `arriopolis d_solution.py`: an empty file.

| Solver | Upstream | Method |
|---|---|---|
| [instance_tailored_target_scheduler](solvers/instance_tailored_target_scheduler/) | Nanored4498/HashCode2022, `2019/` (C++) | One program per group of instances, each using that instance's structure: subset-sum partitions of a target's dependencies, a greedy over targets by gain per server time, and one server per target on F. |
| [subset_sum_partition_scheduler](solvers/subset_sum_partition_scheduler/) | LarsAstrom/Hashcode-final-2019, `solve_c_la.py` (Python 2) | Written for C. A subset-sum dynamic program splits one large target over the servers, then the other targets go into the earliest free slots. |
| [shuffled_deadline_order_greedy](solvers/shuffled_deadline_order_greedy/) | LarsAstrom/Hashcode-final-2019, `mm_sort_shuffle.py` (Python 2) | Sorts targets by deadline, shuffles the first 17, and schedules each target's files in the earliest free slots, undoing a target that would miss its deadline. |

## Best scores (B–F, re-run from `solvers/`, official judge)

Best of 10 seeds for the two randomized solvers, and 1 run for the deterministic one. Bold marks the highest score on each instance.

| Solver | B | C | D | E | F | Sum of bests | Sum of means |
|---|---:|---:|---:|---:|---:|---:|---:|
| [instance_tailored_target_scheduler](output/instance_tailored_target_scheduler/scores.md) | **1,530,065** | 1,934,841 | 1,250,354 | **524,288** | **840,971** | 6,080,519 | 6,080,519 |
| [subset_sum_partition_scheduler](output/subset_sum_partition_scheduler/scores.md) | not run | **1,950,379** | not run | not run | not run | 1,950,379 | 1,943,920 |
| [shuffled_deadline_order_greedy](output/shuffled_deadline_order_greedy/scores.md) | 1,482,186 | 1,456,275 | **1,277,337** | 1 | invalid (0/10) | 4,215,799 | 4,066,058 |

Taking the best output for each instance gives 6,123,040 over B–F, which would place 7th of the 41 finalist teams. The 6th team has 6,134,316 and the winner 6,228,032.

- All 55 valid outputs are byte-identical to the first round, so moving the solvers into `solvers/` changed nothing.
- Weak spots:
  - shuffled_deadline_order_greedy depends heavily on its seed on D (1,080,541 to 1,277,337), scores 1 on E, and writes an empty plan on F.
  - subset_sum_partition_scheduler solves only C. On B, D and E it crashes, and on F it scores 0.
  - Three programs reach the same 524,288 on E, and five reach 840,971 on F. A simple bound that ignores server limits gives 848,324 on F, so little is left to gain there.

Per-seed tables and timings are in `output/<solver>/scores.md`.

## How we ran them

All three need the official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) (`archive/2019/final/hashcode_2019_final_round.in/`). Each benchmark run was wrapped as `taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/compiling_google/judge.py -i <input>.in -o <output>.out
```

| Solver | Build and run | Changes for the benchmark |
|---|---|---|
| instance_tailored_target_scheduler | `g++ -O2 -std=c++17 -o acd acd.cpp`, also `b`, `e` and `f`<br>`./acd < c_urgent.in > c.out`; `acd` runs C and D | None. |
| subset_sum_partition_scheduler | PyPy 2.7: `pypy main.py c_urgent -s <seed> -i -f -l error --solve module=solve_c_la`, with the instance in `in/c_urgent.in`; writes `submission/c_urgent.ans` | None. `-i -f` make the harness write the plan even if the program's own scorer disagrees. |
| shuffled_deadline_order_greedy | PyPy 2.7: as above with `b_narrow` and so on, and `module=mm_sort_shuffle` | None. |

Instances C–F use the same commands with the name changed. The full setup notes for each solver are in the *Run setup* section of its `scores.md`.
