# tabu_search_random_greedy: scores

Solver: [`solvers/tabu_search_random_greedy/`](../../solvers/tabu_search_random_greedy/). Instances B–F of Hash Code 2021 Final, 10 runs each. Every output was scored with `google-hashcode-judge/software_engineering_at_scale/judge.py`; a run the judge rejects counts as 0 in the statistics. Outputs: `<instance>/seed_<s>.out`, or `<instance>/seed_<s>.invalid.out` for a rejected output.

## Scores per run

| Seed | B (`b_breadth_of_choice`) | C (`c_constrained_optimisation`) | D (`d_distinction`) | E (`e_expectation_maximisation`) | F (`f_five_thousand`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | invalid | 89,057 | invalid | invalid | invalid | 89,057 |
| 12 | invalid | 104,281 | 90,709,511 | invalid | 150,930,087 | 241,743,879 |
| 23 | invalid | 107,395 | invalid | invalid | 150,814,851 | 150,922,246 |
| 34 | invalid | 94,106 | invalid | invalid | invalid | 94,106 |
| 45 | invalid | invalid | invalid | invalid | 151,107,531 | 151,107,531 |
| 56 | invalid | 113,316 | invalid | invalid | 151,177,982 | 151,291,298 |
| 67 | invalid | 96,528 | invalid | invalid | 151,023,820 | 151,120,348 |
| 78 | invalid | 111,464 | invalid | invalid | invalid | 111,464 |
| 89 | invalid | 116,430 | invalid | invalid | invalid | 116,430 |
| 100 | invalid | 111,464 | invalid | invalid | invalid | 111,464 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| b_breadth_of_choice | 0 | 0 | 0 | 0 | 0 | 0/10 | 578.0 |
| c_constrained_optimisation | 116,430 | 94,404 | 105,838 | 34,378 | 0 | 9/10 | 597.2 |
| d_distinction | 90,709,511 | 9,070,951 | 0 | 28,684,866 | 0 | 1/10 | 581.4 |
| e_expectation_maximisation | 0 | 0 | 0 | 0 | 0 | 0/10 | 586.9 |
| f_five_thousand | 151,177,982 | 75,505,427 | 75,407,426 | 79,589,766 | 0 | 5/10 | 585.9 |

Sum of means: 84,670,782. Sum of best runs: 242,003,923.

## Run setup

- Seeds: the 10 runs per instance are labelled 1, 12, 23, 34, 45, 56, 67, 78, 89, 100 as in the protocol, but the program cannot be seeded: it uses unseeded `new Random()` objects and `Guid.NewGuid()` shuffles. The runs therefore differ from each other and from the first benchmark round, and cannot be reproduced.
- Built with the .NET 6 SDK (6.0.428): `dotnet build -c Release HashCode2021/HashCode2021.csproj`. Command: `dotnet HashCode2021/bin/Release/net6.0/HashCode2021.dll <input> <output> <tabu file>`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`). Each run used a fresh working directory.
- Code changes, applied to a copy only (the folder in `solvers/` is unchanged):
  - the three hard-coded Windows paths (`inputFile`, `outputFile`, `algorithmFile`) are read from the command line instead;
  - a 10-minute limit: the construction's day loop, the restart loop (`while (globalScore < 1)`) and the tabu loop each stop once their longest iteration so far would no longer fit before 590 s after process start. The program's own code then writes `outputFile` as usual, and that file is the submission.
- Tabu iterations reached before the limit: B 7–10; C 0–1; D 48–58; E 81–131; F 118–157.
- The limit cut the construction itself on C (all 10 runs, at day 197–212 of 309); those plans are partial, which explains the low scores.
- The program repeats the construction while its own re-score of the plan is below 1. A second construction no longer fitted on B (4 of 10 runs), so the tabu search started from the first plan.
- 6 run(s) passed 600 s and were killed while the program was still re-scoring its plan, after `outputFile` had been written (C seed 12, C seed 34, C seed 45, C seed 67, C seed 78, C seed 89). 5 of them are valid and are scored.
- Invalid outputs (each run's judge message is listed under *Invalid runs* below): 24× uses a binary ID before that binary is created (C 1, D 9, E 10, F 4); 9× starts work on a binary while a move involving it is still running (B 8, F 1); 2× starts a move on a binary that is still being worked on (B 2). The program's own validator does not check these rules.

## Invalid runs

The judge's message for each rejected output.

| Instance | Seed | Judge message |
|---|---:|---|
| B | 1 | Invalid output: line 540: on day 139, binary 71 is busy with the move that started on line 433 |
| B | 12 | Invalid output: line 439: on day 315, binary 24 is busy with the implementation that started on line 380 |
| B | 23 | Invalid output: line 556: on day 130, binary 16 is busy with the move that started on line 384 |
| B | 34 | Invalid output: line 219: on day 178, binary 74 is busy with the move that started on line 153 |
| B | 45 | Invalid output: line 368: on day 176, binary 61 is busy with the move that started on line 79 |
| B | 56 | Invalid output: line 102: on day 240, binary 12 is busy with the move that started on line 483 |
| B | 67 | Invalid output: line 442: on day 186, binary 44 is busy with the implementation that started on line 209 |
| B | 78 | Invalid output: line 518: on day 140, binary 60 is busy with the move that started on line 78 |
| B | 89 | Invalid output: line 35: on day 204, binary 74 is busy with the move that started on line 160 |
| B | 100 | Invalid output: line 115: on day 257, binary 22 is busy with the move that started on line 242 |
| C | 45 | Invalid output: line 493: on day 47, binary 34 does not exist, expected an ID from 0 to 17 |
| D | 1 | Invalid output: line 88: on day 92, binary 69 does not exist, expected an ID from 0 to 61 |
| D | 23 | Invalid output: line 88: on day 98, binary 69 does not exist, expected an ID from 0 to 64 |
| D | 34 | Invalid output: line 156: on day 55, binary 86 does not exist, expected an ID from 0 to 43 |
| D | 45 | Invalid output: line 159: on day 106, binary 84 does not exist, expected an ID from 0 to 66 |
| D | 56 | Invalid output: line 157: on day 67, binary 87 does not exist, expected an ID from 0 to 48 |
| D | 67 | Invalid output: line 82: on day 84, binary 93 does not exist, expected an ID from 0 to 57 |
| D | 78 | Invalid output: line 155: on day 62, binary 70 does not exist, expected an ID from 0 to 44 |
| D | 89 | Invalid output: line 668: on day 100, binary 86 does not exist, expected an ID from 0 to 65 |
| D | 100 | Invalid output: line 307: on day 77, binary 60 does not exist, expected an ID from 0 to 52 |
| E | 1 | Invalid output: line 11: on day 304, binary 10 does not exist, expected an ID from 0 to 9 |
| E | 12 | Invalid output: line 59: on day 197, binary 7 does not exist, expected an ID from 0 to 5 |
| E | 23 | Invalid output: line 6: on day 105, binary 7 does not exist, expected an ID from 0 to 5 |
| E | 34 | Invalid output: line 5: on day 103, binary 6 does not exist, expected an ID from 0 to 4 |
| E | 45 | Invalid output: line 5: on day 103, binary 15 does not exist, expected an ID from 0 to 4 |
| E | 56 | Invalid output: line 50: on day 201, binary 11 does not exist, expected an ID from 0 to 6 |
| E | 67 | Invalid output: line 50: on day 103, binary 7 does not exist, expected an ID from 0 to 4 |
| E | 78 | Invalid output: line 5: on day 103, binary 15 does not exist, expected an ID from 0 to 4 |
| E | 89 | Invalid output: line 74: on day 304, binary 11 does not exist, expected an ID from 0 to 9 |
| E | 100 | Invalid output: line 6: on day 105, binary 7 does not exist, expected an ID from 0 to 5 |
| F | 1 | Invalid output: line 770: on day 35, binary 61 does not exist, expected an ID from 0 to 52 |
| F | 34 | Invalid output: line 773: on day 35, binary 84 does not exist, expected an ID from 0 to 52 |
| F | 78 | Invalid output: line 766: on day 35, binary 61 does not exist, expected an ID from 0 to 52 |
| F | 89 | Invalid output: line 604: on day 86, binary 5 is busy with the move that started on line 26 |
| F | 100 | Invalid output: line 772: on day 48, binary 86 does not exist, expected an ID from 0 to 69 |
