# City Plan: choosing the best solvers

Google Hash Code 2018, Final round. Thirteen public solver repositories were collected. Twelve of them hold 22 programs that were tried, and two solvers from one repository were kept. A fourteenth repository, `Mykhailenko/hashcode2018`, was removed earlier because it only calculates scores, and it is listed in [EXCLUDED.md](../EXCLUDED.md).

## What we did

1. **Collected.** We searched GitHub and GitLab for solver repositories for this problem. Files byte-identical to the official inputs were deleted. Each program in a repository was scored as its own entry.
2. **Screened (every usable program).** Instances B–F.
   - Each program got 1 run per instance, with seed 1 if it is randomized, and a 5-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/city_plan/judge.py`. A run whose output the judge rejects counts as 0.
   - Code changes were limited to the seed, the input/output paths and the time stop. Programs that cannot run or never write a submission were marked unusable and not scored.
   - Some programs needed more to run at all. `HofmannZ-cpp` needs `-fpermissive`. `HofmannZ-dart` ran on Dart 2.19 with an SDK constraint in `pubspec.yaml` and `UTF8.decoder` changed to `utf8.decoder`. `Damien` got a small main for one instance, because upstream scans a folder with Windows calls, and two files that need Boost and are not part of the solver were left out. `Pierre` needed `time.clock` replaced, as Python 3.8 removed it. `peuziat` had its picture output removed, because it uses the removed `scipy.misc`. `mihai-bontea` got a main for one instance and was built without OpenMP.
   - `arriopolis randomness` has no default tile size, so 50 was our choice.
3. **Advanced.** A program went on if it is in the top 3 or within 20% of the best on an instance, or in the top 3 by total. Two safeguards applied:
   - A program with no valid output at the limit got a 10-minute run on that instance. That applied to `robert`, `mjbm-grid`, `Antoine` (D), `arriopolis randomness` (C, E), `mjbm-genetic` (E), `HofmannZ-dart` (B, E, F), `Pierre-adjacency` (B, D), `Pierre-unit` (C, D, F) and `mihai sol2` (D). Those that finished are scored below from that run.
   - A randomized program with invalid output got 3 more seeds. `HofmannZ-cpp` crashed on F on all 4 seeds. `arriopolis randomness_b` and `random_solution` did not get more seeds, because they crash for a reason unrelated to the seed: `randomness_b` handles only 1×1 buildings and `random_solution` gets `None` from `reduce_same_layouts`.

   Five programs advanced: `mihai sol1` and `sol2`, `arriopolis greedy_dual`, `Damien` (within 20% on B) and `HofmannZ-dart` (within 20% on E).
4. **Full protocol.** The advanced programs got a 10-minute limit and 10 seeds (1, 12, 23, 34, 45, 56, 67, 78, 89, 100) if randomized, or 1 run if deterministic. `mihai sol2` is the only randomized one. The other four were run a second time with a different `PYTHONHASHSEED`, and all 20 outputs were byte-identical to the first run.
5. **Selected.** A solver is kept if either holds:
   - It is first on an instance, by its best result over all seeds.
   - The sum of its per-instance means is within 5% of the best total in the competition, which here means at least 36,197,649 (95% of 38,102,788).

   The other programs were deleted, and their sources are linked in [README.md](README.md).
6. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods. Each README starts with a header giving the source URL and an overview of the method. The outputs and scores are in [output/](output/) and come from the runs above, because the code did not change. Both programs were compiled from their new folders to confirm that they build, and were not re-run.

## Chosen and ignored

Official judge, with the best run per instance. "Screen only" scores come from the single run per instance, which is a 10-minute run where the 5-minute one produced nothing. "—" means no valid output. "Mean %" is the sum of per-instance means as a percentage of the top team's 38,102,788, given only for programs that went through the full protocol. "Placement" puts the sum of the best scores among the 40 finalist teams of 2018, whose totals also include instance A, which is worth about 100 points.

| Program | Stage | B | C | D | E | F | Sum | Mean % | Placement |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| `mihai-bontea`, `sol2` | **chosen** (first on B, D, E, F) | **4,906,081** | 8,616,236 | **7,750,808** | **4,803,980** | **7,004,244** | 33,081,349 | 86.8% | 11 |
| `mihai-bontea`, `sol1` | **chosen** (first on C) | 3,999,070 | **8,693,408** | 7,740,180 | 4,799,060 | 5,134,486 | 30,366,204 | 79.7% | 14 |
| `arriopolis`, `greedy_dual` | full protocol | 1,639,700 | 6,524,568 | 5,771,996 | 4,550,000 | 4,383,880 | 22,870,144 | 60.0% | 24 |
| `HofmannZ`, Dart | full protocol | 1,811,500 | 5,487,824 | 5,705,006 | 4,761,200 | 3,557,484 | 21,323,014 | 56.0% | 27 |
| `Damien` | full protocol | 4,563,527 | 5,375,123 | 2,442,400 | 525,140 | 1,396,468 | 14,302,658 | 37.5% | 34 |
| `Antoine` | screen only | 1,253,267 | 3,740,103 | — | 3,204,335 | 1,485,865 | 9,683,570 | — | 38 |
| `peuziat` | screen only | 299,343 | 1,892,167 | 1,812,381 | 2,212,510 | 671,327 | 6,887,728 | — | 38 |
| `kjanko` | screen only | 627,100 | 1,535,000 | 1,060,754 | 2,525,000 | 377,500 | 6,125,354 | — | 40 |
| `arriopolis`, `randomness` | screen only | 598,680 | — | 2,102,539 | — | 2,241,177 | 4,942,396 | — | 40 |
| `Pierre`, adjacency | screen only | 60,220 | 1,485,647 | 301,590 | 1,647,325 | 276,880 | 3,771,662 | — | 40 |
| `HofmannZ`, C++ | screen only | 601,969 | 224,720 | 1,440,068 | 555,820 | — | 2,822,577 | — | 40 |
| `mjbm`, genetic | screen only | 705 | 155,316 | 1,689,633 | — | 25,912 | 1,871,566 | — | 40 |
| `arriopolis`, `randomness_b` | screen only | 926,800 | — | — | — | — | 926,800 | — | below last |
| `Pierre`, random | screen only | 6,745 | 311,070 | 38,143 | 392,375 | 19,087 | 767,420 | — | below last |
| `Pierre`, unit | screen only | 25,600 | — | — | 207,500 | — | 233,100 | — | below last |
| `robert` | screen only | — | — | — | — | — | invalid | — | — |
| `mjbm`, grid | screen only | — | — | — | — | — | invalid | — | — |
| `kostya` | screen only | — | — | — | — | — | invalid | — | — |
| `Hilla` | screen only | — | — | — | — | — | invalid | — | — |
| `arriopolis`, `random_solution` | screen only | — | — | — | — | — | invalid | — | — |
| `arriopolis`, `greedy` | screen only | — | — | — | — | — | invalid | — | — |
| `arriopolis`, `greedy_v2` | screen only | — | — | — | — | — | invalid | — | — |

**Chosen:**

- `sol2`, as [size_penalized_greedy_hill_climbing](solvers/size_penalized_greedy_hill_climbing/): first on B, D, E and F. Its sum of means is 33,068,670, which is 86.8% of the top team, so it does not reach the 5% line and is kept for being first on an instance.
- `sol1`, as [row_sweep_best_gain_greedy](solvers/row_sweep_best_gain_greedy/): first on C by 77,172 points over the best `sol2` run. It is deterministic on one core and finishes in under 2 minutes.

No program reaches the 5% line, which needs 36,197,649.

**Ignored:**

- `arriopolis greedy_dual`, `HofmannZ` Dart and `Damien`: first on no instance, and far below the 5% line. `Damien` is close only on B, at 93% of the best. `HofmannZ` Dart is close only on E, at 99% of the best.
- `kjanko`: its README reports 35,812,865 and 9th place in the final, but the program runs in under a second and totals 6,125,354. We did not find the reason. The reported score is 94.0% of the top team, so it would miss the 95% line even if a run reproduced it. No per-instance scores or outputs are stored, so we cannot say whether it would be first on an instance.
- `peuziat`: its output at the 5-minute limit scores 6,887,728. Its documentation reports about 14.2 M after about 24 h per large input, which a 10-minute limit does not allow. That is still less than half of `sol2`.
- `kostya`: the judge rejects its output, which has lines like `[14, 0, 0]` and the wrong building count. An unofficial fix of the format gave 12,807,253 and first on no instance. Its README reports a similar size of score on B, C and D.
- `robert` and `mjbm` grid: they wrote nothing within 10 minutes on any instance, so these runs say nothing about how good they would be with more time. `robert`'s output would also start with a picture of the map, which the judge would reject. `mjbm` stores outputs that its own `score.out` files put at no more than 1,783,813 on any instance.
- `HofmannZ` C++: a glibc malloc assertion on F, on all 4 seeds.
- `Hilla`: a `NameError` upstream, because `deepcopy` is never imported. With the import added, unofficially, it did not finish B in 120 s.
- `arriopolis greedy` and `greedy_v2`: they print a Python list and never write a submission, and were cut off at the 5-minute limit.

**Not scored:**

- `hashcode2018-city-plan_afonsoafonsoafonso`: an interactive program that never writes a submission.

## Limits of this benchmark

The results show what each program reaches in 10 minutes on one core, not the best its method can do. A program that writes only at the end, and does not finish in time, scores 0 on that instance.

`mihai-bontea` uses 12 threads in `sol1` and 20 in `sol2`, and ran here on one. That likely explains why the `sol2` output stored in the repository scores 7,897,054 on D against 7,750,808 here, because more threads allow more hill-climbing steps. `sol1` has no timer, so time cannot explain its differences. The order in which threads compare tied buildings is a likely cause, but we did not test it.

## Stored outputs

Outputs stored in the repositories, scored with the official judge. These are not benchmark runs, because we do not know how they were made, so they do not count for selection. On every instance the best stored output belongs to `mihai-bontea`, so they would not change which repository is kept.

| Repository | B | C | D | E | F | Sum |
|---|---:|---:|---:|---:|---:|---:|
| `mihai-bontea`, `sol2` | 4,895,099 | 8,440,605 | 7,897,054 | 4,789,890 | 7,010,895 | 33,033,543 |
| `mihai-bontea`, `sol1` | 3,799,201 | 8,867,842 | 7,573,525 | 4,795,290 | 4,940,263 | 29,976,121 |
| `HofmannZ` | 1,811,500 | 5,487,824 | 5,705,006 | 4,761,200 | 3,557,484 | 21,323,014 |
| `Damien` (`Maps/`) | 4,563,527 | 5,375,123 | 2,442,400 | 525,140 | 1,396,468 | 14,302,658 |
| `Antoine` (`best_*`) | 1,281,237 | 4,477,534 | 1,095,007 | 3,746,845 | 1,917,301 | 12,517,924 |

| Solver | Upstream | Method |
|---|---|---|
| [row_sweep_best_gain_greedy](solvers/row_sweep_best_gain_greedy/) | mihai-bontea/Google-Hash-Code-2018-Final-Round, `sol1/` (C++) | Sweeps the map row by row and, at each free cell, places the building that adds the most points right away. |
| [size_penalized_greedy_hill_climbing](solvers/size_penalized_greedy_hill_climbing/) | mihai-bontea/Google-Hash-Code-2018-Final-Round, `sol2/` (C++) | The same sweep with a size penalty, then hill climbing: removes a random building and puts the best-scoring one at that position. |

## Best scores (B–F, official judge)

Best of 10 seeds for `size_penalized_greedy_hill_climbing`, and 1 run for the deterministic `row_sweep_best_gain_greedy`. The bold score is the highest on each instance.

| Solver | B | C | D | E | F | Sum |
|---|---:|---:|---:|---:|---:|---:|
| [size_penalized_greedy_hill_climbing](output/size_penalized_greedy_hill_climbing/scores.md) | **4,906,081** | 8,616,236 | **7,750,808** | **4,803,980** | **7,004,244** | 33,081,349 |
| [row_sweep_best_gain_greedy](output/row_sweep_best_gain_greedy/scores.md) | 3,999,070 | **8,693,408** | 7,740,180 | 4,799,060 | 5,134,486 | 30,366,204 |

Taking the higher of the two on each instance gives 33,158,521. That would place 11th of the 40 finalist teams, between 33,926,615 and 32,859,078. The top team scored 38,102,788.

- Weak spots:
  - Upstream's `main.cpp` in both programs loops over the six instances at fixed paths, so `../../input_files/` has to be created and filled with the official inputs first.
  - `size_penalized_greedy_hill_climbing` writes only when its timer ends, so a kill before that leaves no output.

Per-seed tables and timings are in `output/<solver>/scores.md`.

## How we ran them

Both need the official inputs from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) (`archive/2018/final/hashcode_2018_final_round.in/`). Each benchmark run was wrapped as `taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/city_plan/judge.py -i <input>.in -o <output>.out
```

| Solver | Build and run | Changes for the benchmark (made to a copy; `solvers/` is untouched) |
|---|---|---|
| row_sweep_best_gain_greedy | In `sol1/`: `g++ -O3 -std=c++23 -w -o solve main.cpp -lgomp`<br>`./solve <input> <output>` | `main.cpp` takes one input and one output path. Built without `-fopenmp`. |
| size_penalized_greedy_hill_climbing | In `sol2/`: `g++ -O3 -std=c++23 -w -o solve main.cpp -lgomp`<br>`./solve <input> <output>` with `HC_SEED` and `HC_STOP=570` set | `main.cpp` takes one input and one output path. Built without `-fopenmp`. The timer stops at `HC_STOP` seconds instead of 10 minutes. `std::random_device` is replaced by a `static` generator seeded from `HC_SEED`. |
