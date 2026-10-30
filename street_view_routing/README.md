# Street View Routing

Google Hash Code 2014, Final round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2014/final](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2014/final).

## Why only two solvers

Two solvers are kept from the 18 collected repositories. A solver is kept if it is first on an instance, or if its mean score is within 5% of the best score in the competition (1,923,588). A first screen ran every usable program with one seed and a 5-minute limit. The programs that could still be competitive then went through the full protocol (10-minute limit, 10 runs for randomized solvers, official judge). The rule, every program's score and the protocol are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers now live in [`solvers/`](solvers/) under method names, with their benchmark outputs in [`output/`](output/). Kept: `google-hash-code-solutions_jp172`, first with 1,930,138, and `hashcode2014_jilljenn`, whose four OCaml modes all have means within 5% (best 1,916,867). The other 16 repositories are listed under *Removed after benchmarking* below.

## Collected solvers

2 solvers: 2 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/pruned_bfs_best_ratio_paths`](solvers/pruned_bfs_best_ratio_paths/) | C++ | 1,930,138 (would have ranked 1st) |
| [`solvers/repeated_randomized_street_walks`](solvers/repeated_randomized_street_walks/) | OCaml | No scores recorded in the repo's README; a stored plan scores 1,916,551 |

### [`solvers/pruned_bfs_best_ratio_paths/`](solvers/pruned_bfs_best_ratio_paths/)

- **Source:** https://github.com/jp172/google-hash-code-solutions
- **Snapshot:** GitHub clone at commit `2d5f23c` (history 2020-02-24); `.git` removed on import. Only the files for this problem were copied (`2014/`), plus the repo's README; the rest of the repo covers other problems.
- **Origin:** Published after the contest by the author, as one of their solutions to past Hash Code problems.
- **Authors:** jp172
- **Language:** C++
- **Approach:** The earliest free car gets the next path. A pruned breadth-first search over paths of up to 19 streets picks the one with the most new street length per second of driving.
- **Scores:** 1,930,138 (the repo's README).
- **Bundled inputs:** Only the author's small `my_example.in`.
- **Run:** In `src/`: `g++ -O2 -std=gnu++11 -o solve main.cpp`, then `./solve paris`, with the instance in `data/paris.in` → `out/paris.out`
- **Benchmark:** 1,930,138 ([scores](output/pruned_bfs_best_ratio_paths/scores.md)).

### [`solvers/repeated_randomized_street_walks/`](solvers/repeated_randomized_street_walks/)

- **Source:** https://github.com/jilljenn/hashcode2014
- **Snapshot:** GitHub clone at commit `9aa7526` (history 2014-10-24); `.git` removed on import. Only the OCaml code in `thomas/`, its Makefile, one stored plan and the repo's README and LICENSE were copied.
- **Authors:** Nguyễn Lê Thành Dũng
- **Language:** OCaml
- **Approach:** One program with four modes (`greedy`, `center`, `clock`, `plan_clock`) that plan the cars one after another. The `iter` argument repeats a mode with new random choices and keeps the best plan.
- **Scores:** No scores in the README. The stored `sols/out_1916551` scores 1,916,551.
- **Bundled inputs:** None bundled.
- **Run:** `ocamlbuild main.native` (OCaml 4.14), then `./main.native <mode> iter < input` until stopped → `sols/out_<score>`
- **Benchmark:** best of 10 seeds, with mean in brackets: `greedy` 1,916,867 (1,912,968), `center` 1,914,622 (1,912,555), `plan_clock` 1,901,362 (1,898,725), `clock` 1,864,126 (1,864,126) ([scores](output/repeated_randomized_street_walks/scores.md)).

## Removed after benchmarking

These 16 repositories were benchmarked (or, if they cannot be run, examined) on 2026-10-30 and then deleted from the collection (see *Why only two solvers* above). Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has every score.

- `Julia_Hashcode2014.jl_davidfang00` (https://github.com/davidfang00/Julia_Hashcode2014.jl): not selected: lookahead with Dijkstra and fan-down, best 1,812,637 over 10 seeds.
- `SuperStreetViewRouter.jl_tfisher013` (https://github.com/tfisher013/SuperStreetViewRouter.jl): not selected: 1,790,843 on all 10 seeds.
- `StreetViewRouting-HashCode_ivanmakhnyk` (https://github.com/ivanmakhnyk/StreetViewRouting-HashCode): not selected: 1,467,406 at the screen (its README claims 1,487,405).
- `HashCodeBanane_Artifere` (https://github.com/Artifere/HashCodeBanane): not selected: `mainAlex` scored 1,440,746 at the screen, and `mainBaptiste` crashes on all 4 seeds.
- `HashCode2014Solution.jl_yuvalm11` (https://github.com/yuvalm11/HashCode2014Solution.jl): not selected: 1,338,975 at the screen.
- `GoogleHashCode-StreetViewRouting_TedevFR` (https://github.com/TedevFR/GoogleHashCode-StreetViewRouting): not selected: 1,205,336 at the screen.
- `Google-HashCode-2014_nicolas-legroux` (https://github.com/nicolas-legroux/Google-HashCode-2014): not selected: 1,128,637 at the screen.
- `hashcode2018-jam-streetview_renuo` (https://github.com/renuo/hashcode2018-jam-streetview): not selected: 889,148 at the screen.
- `GoogleHashCode2014.jl_gdalle` (https://github.com/gdalle/GoogleHashCode2014.jl): not selected: its random-walk baseline scored 816,451 at the screen.
- `INF580_HashCode2014_X-Wei` (https://github.com/X-Wei/INF580_HashCode2014): not selected: the LP needs AMPL, and the replay of its stored path is rejected by the judge.
- `google-hashcode-2014_Siddharth-cmd` (https://github.com/Siddharth-cmd/google-hashcode-2014): not scored: it solves Painting the Facade, the training round.
- `hashcode2014_antgus` (https://github.com/antgus/hashcode2014): not scored: it only reads the input, and its optimizer is an unfinished stub.
- `hashcode2017_Diegoriggle77` (https://github.com/Diegoriggle77/hashcode2017): not scored: it never writes a submission.
- `hashcode-streetview_kafkoders` (https://github.com/kafkoders/hashcode-streetview): not scored: its notebook only prints a total.
- `hashcode2014_nicolasbourbaki35` (https://github.com/nicolasbourbaki35/hashcode2014): not scored: it writes only coordinates to `path.txt`.
- `street_view_routing_LAnastasiia` (https://github.com/LAnastasiia/street_view_routing): not scored: it writes only a log to `results.txt`.
