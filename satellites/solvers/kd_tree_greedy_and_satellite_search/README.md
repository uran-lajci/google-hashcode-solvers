> **Greedy with a k-d tree (`gui`), and a search for each satellite (`raph`)**
>
> Source: https://github.com/aliphen/hashCode2016 (`Hashcode.Finale/`)
>
> Method overview:
> 1. `gui`: takes the satellites by camera range, widest first. At each turn it asks a k-d tree for images near the satellite, keeps those it can reach in an open time range, and takes the farthest.
> 2. `raph`: takes the satellites by camera range, narrowest first. For each it keeps a set of partial plans, each with its own camera range, adds a plan for each image in reach, and drops plans not worth keeping. The best plan is fixed before the next satellite.
> 3. `gui` runs on all four instances. `raph` is better on `forever_alone`, wrote nothing in 10 minutes on `weekend` and `constellation`, and crashes on `overlap`.
>
> In our runs: `gui` 48,000, 47,522, 61,817 and **32,857** on `forever_alone`, `weekend`, `constellation` and `overlap`; `raph` **55,728** on `forever_alone`. Bold is first on that instance. ([scores](../../output/kd_tree_greedy_and_satellite_search/scores.md)).
>
> We changed three things. The .NET Framework project is replaced by a .NET 6 project in `Hashcode.Finale/hc/`. `Program.cs` now solves one instance, named by `HC_INST`, with the mode given as its argument, and writes in the current folder, where it used to loop over four fixed paths. `SolverRaph.cs` takes `Stopwatch` from `System.Diagnostics`, because the old NUnit namespace is gone.
