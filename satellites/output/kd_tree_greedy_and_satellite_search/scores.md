# kd_tree_greedy_and_satellite_search: scores

Solver: [`solvers/kd_tree_greedy_and_satellite_search/`](../../solvers/kd_tree_greedy_and_satellite_search/). The four instances of Hash Code 2016 Final. One program with two modes, 10 runs per mode on each instance where it finishes.

## Scores

| Instance | `gui` | Time (s) | `raph` | Time (s) |
|---|---:|---:|---:|---:|
| forever_alone | 48,000 | 3 | **55,728** | 10 |
| weekend | 47,522 | 166 | no output | limit |
| constellation | 61,817 | 151 | no output | limit |
| overlap | **32,857** | 421 | crashes | 1 |

The `gui` sum is 190,196. The top team's total is 1,017,218. Bold marks a best score across all programs we ran. Every run of a mode on an instance gave the same score.

Output files are `<instance>/<mode>_deterministic.out`, or `<mode>_run_1.out` where the bytes differ between runs.

## Run setup

- Scored with the official judge, `google-hashcode-judge/satellites/judge.py`.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit.
- Built and run as `dotnet build Hashcode.Finale/hc/hc.csproj -c Release -o out`, then, with the instance in the current folder, `HC_INST=overlap dotnet out/hc.dll gui` (or `raph`). It writes `<instance>-<score>.out`, and the number in that name is the program's own count.
- **Code changes.** We changed three things. The .NET Framework project is replaced by a .NET 6 project in `Hashcode.Finale/hc/`. `Program.cs` now solves one instance, named by `HC_INST`, with the mode given as its argument, and writes in the current folder, where it used to loop over four fixed paths. `SolverRaph.cs` takes `Stopwatch` from `System.Diagnostics`, because the old NUnit namespace is gone.
- `raph` was also given 3 cores on `weekend` and `constellation`, because it uses `Parallel.ForEach`. It still wrote nothing in 10 minutes.
- On `overlap`, `gui` reports 7,548 for itself and the judge gives 32,857. The judge's score is the one used.
