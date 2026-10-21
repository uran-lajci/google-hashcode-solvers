> **Randomized greedy with service moves, followed by a tabu search**
>
> Source: https://github.com/EndritMeziu/HashCode2021
>
> Method overview:
> 1. Construction (`InitialSolution` in `Program.cs`) goes day by day. Each free engineer tries, in this order:
>    - while there are fewer binaries than services: create a new binary and move into it one of the two services
>      that the most features need, taken from a binary chosen by the engineer's ID (the pick between the two is
>      random);
>    - at most 3 times per day: move a random, not yet moved, needed service from one of the larger binaries to the
>      smallest binary;
>    - implement the remaining feature with the best users ÷ total implementation time, in a random binary of that
>      feature, if the binary is free and the work fits in the engineer's remaining days. Up to 10 features down
>      the list are tried; otherwise the engineer waits one day.
> 2. The construction is repeated until the program's own re-score of the plan is at least 1.
> 3. Tabu search (`PerformTabuSearch`), up to 1,000,000 iterations. Each iteration makes up to 15 valid neighbours
>    (at most 100 attempts) by swapping two `impl` tasks of one random engineer and re-timing the tasks between
>    them. A swapped pair becomes tabu for 40 iterations, and a neighbour that repeats a tabu pair is discarded. The
>    best neighbour replaces the plan if it scores at least as well.
> 4. Randomness comes from unseeded `new Random()` objects and `Guid.NewGuid()` shuffles, so runs cannot be
>    reproduced.
> 5. It writes all four task types (`impl`, `move`, `new`, `wait`). It is the only solver of this problem in the
>    collection that moves services and creates binaries.
> 6. Known problems:
>    - The program's own validator only checks that two engineers do not implement the same feature in the same
>      binary at the same time. Most outputs break another rule of the statement: they start work on a binary
>      during a move that involves it, start a move on a binary that is being worked on, or use a binary ID before
>      that binary exists. See `../../SOLVER_SELECTION.md` for how often this happened.
>    - With fewer than 4 binaries in the current state (as in instance A), the service-move step divides by zero
>      and the program crashes.

# tabu_search_random_greedy

## Environment

The [.NET 6 SDK](https://dotnet.microsoft.com/download/dotnet/6.0); the project targets `net6.0`. Build from this
folder:

```bash
dotnet build -c Release HashCode2021/HashCode2021.csproj
```

The project needs no NuGet packages. The benchmark used SDK 6.0.428 on Linux, installed per user with
[`dotnet-install.sh`](https://learn.microsoft.com/dotnet/core/tools/dotnet-install-script) (`--channel 6.0`).

## Input files

`Program.cs` hard-codes three Windows paths at the top (lines 8–10). Set them before building:

| Variable | Upstream value (file name) | Meaning |
|---|---|---|
| `inputFile` | `Instances\five_thousand.txt` | the instance to solve |
| `outputFile` | `Solutions\an_example.txt` | written after each construction and at the end of the tabu search |
| `algorithmFile` | `Solutions\hill_climbing.txt` | rewritten each time the tabu search accepts a plan |

The official inputs are in [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) under
`archive/2021/final/hashcode_2021_final_round.in/`. For the benchmark the three variables were read from the command
line instead (`args[0]`, `args[1]`, `args[2]`).

## Running each instance

```bash
dotnet HashCode2021/bin/Release/net6.0/HashCode2021.dll
```

In practice the program does not stop on its own: 1,000,000 tabu iterations take far longer than the contest
allows. It prints the score after each accepted step. The benchmark stopped each run after 590 s. Over both
benchmark rounds (20 runs per instance), the tabu search got this far in that time:

| Instance | Tabu iterations in 590 s | Notes |
|---|---:|---|
| B | 6–10 | in 9 of 20 runs the program's re-score asked for a second construction, which no longer fitted (one construction takes more than 295 s) |
| C | 0–1 | the construction does not finish in 590 s (cut at day 197–215 of 309) |
| D | 48–58 | |
| E | 75–139 | |
| F | 118–163 | |

Times are from the benchmark (one pinned core per run).

## Not included from upstream

`HashCode2021.Validator/` (a separate scoring tool, which needs the NuGet package
`Microsoft.Extensions.DependencyInjection`), `HashCode2021.sln`, the one-line README and `.gitignore`. The code in
`HashCode2021/` is unchanged. `LICENSE` (MIT) is kept.
