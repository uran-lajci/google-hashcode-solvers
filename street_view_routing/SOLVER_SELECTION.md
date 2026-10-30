# Street View Routing: choosing the best solvers

Google Hash Code 2014, Final round. Eighteen public solver repositories were collected. Twelve of them hold 20 programs and modes that can be run, and two solvers from two repositories were kept. One of them is a single program with four modes.

This is the first problem selected with the wider keep rule. One to five instances are too few for meaningful algorithm selection, so being first on an instance is no longer the only way in.

## What we did

1. **Collected.** We searched GitHub and GitLab and found 18 solver repositories for this problem. Files byte-identical to the official input were deleted. Each program or mode in a repository was scored as its own entry.
2. **Screened (every usable program).** The Paris instance, as the problem has no other.
   - Each program got 1 run, with seed 1 if it is randomized, and a 5-minute wall-clock limit. At most 6 ran in parallel, each pinned to its own physical core.
   - Every output was scored with the official judge in `google-hashcode-judge/street_view_routing/judge.py`. A run whose output the judge rejects counts as 0.
   - Code changes were limited to the seed and the input/output paths. Programs that cannot run or never write a submission were marked unusable and not scored.
   - Some programs needed more to run at all. The Julia packages (`gdalle`, `yuvalm11`, `tfisher013`, `davidfang00`) and `renuo` have only library code, so each got a small command-line driver. `TedevFR` targets .NET Framework 4.5.2, so it got a .NET 6 project file. `ivanmakhnyk` overflows the default Java stack, so it ran with `-Xss1g`. The `jilljenn` OCaml program was built with OCaml 4.14, because newer versions removed a function it uses. Its first screen failed because our build had failed, not because of the program, so all four of its modes were screened again after the build was fixed.
3. **Advanced.** A program went on if it is in the top 3 or within 20% of the best, which here means at least 1,544,111. Seven programs qualified. One safeguard applied: a randomized program with invalid output got 3 more seeds. `jilljenn euler_cpp` and `Artifere mainBaptiste` got them and stayed invalid. No program ended the screen at the limit without valid output.
4. **Full protocol.** The advanced programs got a 10-minute limit and 10 seeds (1, 12, 23, 34, 45, 56, 67, 78, 89, 100) if randomized, or 1 run if deterministic. `jp172` is the only deterministic one, and a second run gave a byte-identical output.
5. **Selected.** A solver is kept if either holds:
   - It is first on an instance, by its best result over all seeds.
   - Its mean score over the seeds is within 5% of the best score in the competition, which here means at least 1,827,409 (95% of 1,923,588).

   The other programs were deleted, and their sources are linked in [README.md](README.md).
6. **Renamed.** The kept solvers now live in [solvers/](solvers/), named after their methods. Each README starts with a header giving the source URL and an overview of the method. The outputs and scores are in [output/](output/) and come from the runs above, because the code did not change. As a check, `jp172` was run from its new folder (byte-identical output), and so were 12 runs of the `jilljenn` modes (the same scores), after which the re-run was stopped as unnecessary.

## Chosen and ignored

Official judge. "Screen only" scores come from the single short run, or 4 runs for the two programs given more seeds. "Mean %" is the mean as a percentage of the top team's 1,923,588, given only for programs with 10 full runs or a deterministic result. "Placement" puts the best score among the 54 finalist teams of 2014.

| Program | Stage | Best | Mean | Mean % | Placement |
|---|---|---:|---:|---:|---:|
| `google-hash-code-solutions_jp172` | **chosen** (first, and within 5%) | **1,930,138** | 1,930,138 | 100.3% | 1 |
| `hashcode2014_jilljenn`, `greedy` | **chosen** (within 5%) | 1,916,867 | 1,912,968 | 99.4% | 2 |
| `hashcode2014_jilljenn`, `center` | **chosen** (within 5%) | 1,914,622 | 1,912,555 | 99.4% | 3 |
| `hashcode2014_jilljenn`, `plan_clock` | **chosen** (within 5%) | 1,901,362 | 1,898,725 | 98.7% | 6 |
| `hashcode2014_jilljenn`, `clock` | **chosen** (within 5%) | 1,864,126 | 1,864,126 | 96.9% | 9 |
| `Julia_Hashcode2014.jl_davidfang00`, `greedy_lookahead_dijkstras_fandown` | full protocol | 1,812,637 | 1,703,387 | 88.6% | 10 |
| `SuperStreetViewRouter.jl_tfisher013` | full protocol | 1,790,843 | 1,790,843 | 93.1% | 11 |
| `StreetViewRouting-HashCode_ivanmakhnyk` | screen only | 1,467,406 | — | — | 25 |
| `HashCodeBanane_Artifere`, `mainAlex` | screen only | 1,440,746 | — | — | 29 |
| `Julia_Hashcode2014.jl_davidfang00`, `fandown_greedy` | screen only | 1,424,977 | — | — | 30 |
| `Julia_Hashcode2014.jl_davidfang00`, `greedy_lookahead` | screen only | 1,389,983 | — | — | 33 |
| `HashCode2014Solution.jl_yuvalm11` | screen only | 1,338,975 | — | — | 36 |
| `GoogleHashCode-StreetViewRouting_TedevFR` | screen only | 1,205,336 | — | — | 43 |
| `Julia_Hashcode2014.jl_davidfang00`, `greedy` | screen only | 1,201,760 | — | — | 44 |
| `Google-HashCode-2014_nicolas-legroux` | screen only | 1,128,637 | — | — | 47 |
| `hashcode2018-jam-streetview_renuo` | screen only | 889,148 | — | — | 50 |
| `GoogleHashCode2014.jl_gdalle`, random walk | screen only | 816,451 | — | — | 52 |
| `hashcode2014_jilljenn`, `euler_cpp` | screen only | invalid (0/4) | — | — | — |
| `HashCodeBanane_Artifere`, `mainBaptiste` | screen only | invalid (0/4) | — | — | — |
| `INF580_HashCode2014_X-Wei`, replay of a stored path | screen only | invalid | — | — | — |

**Chosen:**

- `jp172`, as [pruned_bfs_best_ratio_paths](solvers/pruned_bfs_best_ratio_paths/): first by 13,271 points over the best other run, and above the contest winner by 6,550. It took 7.5 and 11.5 s in the timed runs, and its README reports the same score.
- `jilljenn` OCaml, as [repeated_randomized_street_walks](solvers/repeated_randomized_street_walks/): all four modes have means within 5% of the top team. `greedy` is the closest to `jp172`. `clock` scores the same on every seed. Each mode runs until the limit stops it.

**Ignored:**

- `tfisher013`: 1,790,843 on all 10 seeds, so the seed has no effect. That is 93.1% of the top team, below the 95% needed.
- `davidfang00`, lookahead with Dijkstra and fan-down: the seed matters, from 1,624,174 to 1,812,637, and the mean is 88.6%. It ran with its defaults (lookahead 15, sequence 15). Its docs report 1.83 M with 21 and 19, a setting not run here. A mean at that level would only just reach the 95% line (1,827,409). Its three simpler programs were too far behind at the screen.
- `jilljenn euler_cpp`: every output is rejected, because a car overruns T by a few seconds (54,005 in the screen run). The repository also stores `thomas/sols/out_1916551`, which the judge scores 1,916,551, the score of the second-placed team. That file is kept in the solver's `sols/` folder, but no run reproduced it.
- `ivanmakhnyk`: its README claims 1,487,405, but the judge gives 1,467,406 on both a fresh run and the output stored in the repository.
- `Artifere mainAlex`, `yuvalm11`, `legroux`, `renuo` and `gdalle`: too far behind at the screen. `gdalle`'s random walk is the package's example baseline.
- `TedevFR`: too far behind at the screen. It exits with an error at `Console.ReadKey` when run without a console, after it has written its output, and that output was scored.
- `Artifere mainBaptiste`: crashes on all 4 seeds, leaving a cut-off file.
- `X-Wei`: the LP that produces its path needs AMPL, so only its replay step could run. The replay is rejected because a car reaches a junction at 54,010, after T = 54,000. The stored `final_solution.txt` is rejected too.

**Not scored:**

- `google-hashcode-2014_Siddharth-cmd`: it solves Painting the Facade, the training round, a different problem.
- `hashcode2014_antgus`: it only reads the input, and its optimizer is an unfinished stub.
- `hashcode2017_Diegoriggle77`: it stops after Dijkstra and never writes a submission.
- `hashcode-streetview_kafkoders`: its notebook only prints a total.
- `hashcode2014_nicolasbourbaki35`: it writes only coordinates to `path.txt`.
- `street_view_routing_LAnastasiia`: it writes only a log to `results.txt`.
- In `HashCodeBanane_Artifere`, `main.cpp` only reads the input and `trial/` is the training round. Its other two programs are scored above.

| Solver | Upstream | Method |
|---|---|---|
| [pruned_bfs_best_ratio_paths](solvers/pruned_bfs_best_ratio_paths/) | jp172/google-hash-code-solutions, `2014/src/main.cpp` (C++) | The earliest free car gets the next path. A pruned breadth-first search over paths of up to 19 streets picks the one with the most new street length per second of driving. |
| [repeated_randomized_street_walks](solvers/repeated_randomized_street_walks/) | jilljenn/hashcode2014, `thomas/` (OCaml) | Plans the cars one after another with one of four modes: greedy from a random junction, greedy around a random center, a clockwise turning rule, or that rule from random junctions. It repeats with new random choices and keeps the best plan. |

## Best scores (Paris, official judge)

Best of 10 seeds for the randomized modes, and 1 run for the deterministic solver. The bold score is the highest.

| Solver | Mode | Best | Mean |
|---|---|---:|---:|
| [pruned_bfs_best_ratio_paths](output/pruned_bfs_best_ratio_paths/scores.md) | — | **1,930,138** | 1,930,138 |
| [repeated_randomized_street_walks](output/repeated_randomized_street_walks/scores.md) | `greedy` | 1,916,867 | 1,912,968 |
| | `center` | 1,914,622 | 1,912,555 |
| | `plan_clock` | 1,901,362 | 1,898,725 |
| | `clock` | 1,864,126 | 1,864,126 |

The best score would place 1st of the 54 finalist teams, above the best team scores of 1,923,588 and 1,916,551.

- Weak spots:
  - pruned_bfs_best_ratio_paths has the start junction hard-coded as 4516, the one in the Paris instance, so it needs that line changed for any other instance.
  - repeated_randomized_street_walks never stops by itself, and a kill during a write can cut its newest plan short, so the two highest files have to be checked with the judge.

Per-seed tables and timings are in `output/<solver>/scores.md`.

## How we ran them

Both need the official input from [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) (`archive/2014/final/hashcode_2014_final_round.in`). Each benchmark run was wrapped as `taskset -c <0|2|4|6|8|10> timeout -k 10 600 <command>` and scored with:

```bash
python3 -I ../google-hashcode-judge/street_view_routing/judge.py -i hashcode_2014_final_round.in -o <output>.out
```

| Solver | Build and run | Changes for the benchmark (made to a copy; `solvers/` is untouched) |
|---|---|---|
| pruned_bfs_best_ratio_paths | In `src/`: `g++ -O2 -std=gnu++11 -w -o solve main.cpp`<br>Copy the input to `data/paris.in`, then `./solve paris`, which writes `out/paris.out` | None. |
| repeated_randomized_street_walks | OCaml 4.14: `ocamlbuild -classic-display main.native`<br>`./main.native <mode> iter < hashcode_2014_final_round.in`, which writes `sols/out_<score>` | The seed: `Random.self_init ()` in `greedy.ml` and `clockwise.ml`, and `Random.init 43` in `centered.ml`, now read `HC_SEED`. |
