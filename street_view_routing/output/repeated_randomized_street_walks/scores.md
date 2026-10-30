# repeated_randomized_street_walks: scores

Solver: [`solvers/repeated_randomized_street_walks/`](../../solvers/repeated_randomized_street_walks/). The single instance of Hash Code 2014 Final (Paris), four modes of one program, 10 runs each. Every output was scored with `google-hashcode-judge/street_view_routing/judge.py`. Outputs are in the instance folder next to this file, named `<mode>_seed_<n>.out`.

## Scores per run

| Seed | `greedy` | `center` | `plan_clock` | `clock` |
|---:|---:|---:|---:|---:|
| 1 | 1,913,071 | 1,912,091 | 1,898,386 | 1,864,126 |
| 12 | 1,913,204 | 1,909,277 | 1,899,863 | 1,864,126 |
| 23 | 1,910,500 | 1,914,622 | 1,898,009 | 1,864,126 |
| 34 | 1,911,510 | 1,911,993 | 1,900,210 | 1,864,126 |
| 45 | 1,911,927 | 1,914,622 | 1,901,362 | 1,864,126 |
| 56 | 1,914,513 | 1,914,489 | 1,895,677 | 1,864,126 |
| 67 | 1,912,614 | 1,912,001 | 1,899,373 | 1,864,126 |
| 78 | 1,916,867 | 1,911,997 | 1,897,135 | 1,864,126 |
| 89 | 1,911,844 | 1,909,840 | 1,900,010 | 1,864,126 |
| 100 | 1,913,634 | 1,914,622 | 1,897,223 | 1,864,126 |

## Statistics per mode

| Mode | Best | Mean | Median | Std dev | Worst | Valid runs | Mean as % of the top team |
|---|---:|---:|---:|---:|---:|---:|---:|
| `greedy` | 1,916,867 | 1,912,968 | 1,912,842 | 1,788 | 1,910,500 | 10/10 | 99.4% |
| `center` | 1,914,622 | 1,912,555 | 1,912,046 | 1,995 | 1,909,277 | 10/10 | 99.4% |
| `plan_clock` | 1,901,362 | 1,898,725 | 1,898,880 | 1,739 | 1,895,677 | 10/10 | 98.7% |
| `clock` | 1,864,126 | 1,864,126 | 1,864,126 | 0 | 1,864,126 | 10/10 | 96.9% |

The top team scored 1,923,588. Every run used the full 600 s, because `iter` does not stop by itself.

## Run setup

- Built with OCaml 4.14 as `ocamlbuild -classic-display main.native` and run as `./main.native <mode> iter < hashcode_2014_final_round.in`. Plans go to `sols/out_<score>`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- The kill can cut the newest plan short, so the two highest `sols/out_<score>` files were judged and the best valid one is reported.
- One code change, to set the seed. `greedy.ml` and `clockwise.ml` use `Random.self_init ()` upstream and `centered.ml` uses `Random.init 43`, and all three were changed to read the seed from `HC_SEED`. The `solvers/` copy is unpatched.
- These runs used a copy of the upstream repository. After the move to `solvers/`, 12 runs from the new folder (all of `greedy`, and seeds 1 and 12 of `center`) gave the same scores, and the re-run was then stopped as unnecessary.
