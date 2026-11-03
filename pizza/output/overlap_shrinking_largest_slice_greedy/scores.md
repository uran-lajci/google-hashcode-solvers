# overlap_shrinking_largest_slice_greedy: scores

Solver: [`solvers/overlap_shrinking_largest_slice_greedy/`](../../solvers/overlap_shrinking_largest_slice_greedy/). The three main instances of the Hash Code 2017 practice round.

## Scores

| Instance | Mean | Best run | Time (s) | Runs |
|---|---:|---:|---:|---:|
| small | 42 | **42** | 0 | 2 |
| medium | 49,576 | 49,576 | 1 | 2 |
| big | 909,569 | **909,569** | 14 | 2 |

The sum of means is 959,187.

There is no scoreboard for this practice round. The kept solvers are the ten with the highest sums of means, all within 5% of the best (959,187, `overlap_shrinking_largest_slice_greedy`), and any program that alone has the best result on an instance. Bold marks a best score across all programs we ran.

Output files are `<instance>/deterministic.out`, or `<instance>/best_run.out` where runs differ.

## Run setup

- Scored with the official judge, `google-hashcode-judge/pizza/judge.py`. The example instance was not run.
- Each run was pinned with `taskset` to its own physical core, at most 6 at a time, with a 10-minute wall-clock limit and 3.5 GB of memory.
- Programs whose runs can differ got 10 runs; the others got 2, the second with another `PYTHONHASHSEED`.
- **Run.** In `HashCode_Pizza/`: `dotnet build -c Release hc.csproj`, then `dotnet bin/Release/net6.0/hc.dll <input>`, which writes `<input>.out`.
- **Code changes.** `Program.cs` no longer saves a picture of the slices, which needs `System.Drawing`. We added `hc.csproj`, a .NET 6 project over the same sources, and renamed the old .NET Framework project file and `Properties/AssemblyInfo.cs` with `.old`.
