> **Ratio-sorted feature greedy with least-busy engineers (strategy 1)**
>
> Source: https://github.com/Loicyeu/google-hashcode-2021 (`strategie1` in `polyhash.py`)
>
> Method overview:
> 1. Feature orders: 13 sort keys (users, difficulty, number of binaries, number of services, and quotients of these
>    such as users/difficulty or users/difficulty/binaries; `utils/ratios.py`), each in both directions, give 26
>    feature orders. The input is parsed and solved again for each order.
> 2. Assignment: the features are taken in order. For every binary that holds services of the feature, the engineer
>    with the fewest days of work so far implements the feature in that binary. This takes difficulty + services in
>    the binary + engineers already in the binary on the start day.
> 3. Each engineer has a private timeline (the days worked so far). An order is finished once every engineer has
>    passed the time limit, or once no feature is left.
> 4. Only `impl` tasks are written: no services are moved and no binaries are created.
> 5. Each of the 26 plans is written to `solutions/<order>.txt`, and the program prints its own score for each,
>    best first. Its scorer is approximate: the upstream README says it applies the same-day binary penalty to the
>    wrong engineers. In the benchmark every file was scored with the official judge and the best one was kept.
> 6. Deterministic.

# ratio_sorted_greedy_least_busy

## Environment

Python 3.9 or newer (the code uses `list[...]` type hints). There are no third-party packages; upstream's
`requirements.txt` only listed the linters `flake8` and `pep8-naming`.

## Input files

`polyhash.py` takes the instance path as its only argument. The official inputs are in
[google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) under
`archive/2021/final/hashcode_2021_final_round.in/`.

## Running each instance

From the folder you want the results in (it needs a `solutions/` subfolder):

```bash
mkdir -p solutions
python3 <path to this folder>/polyhash.py b_breadth_of_choice.in.txt
```

| Instance | Input | Time per run (all 26 orders) | Best order (official judge) |
|---|---|---:|---|
| A | `a_example.in.txt` | < 0.1 s | several tie |
| B | `b_breadth_of_choice.in.txt` | 43 s | `Users/Diff/Bin` (ties with `Users/Diff/Services`) |
| C | `c_constrained_optimisation.in.txt` | 10 s | `Users` |
| D | `d_distinction.in.txt` | 5 s | `Users/Diff/Services` |
| E | `e_expectation_maximisation.in.txt` | 0.3 s | `Users/Bin` |
| F | `f_five_thousand.in.txt` | 2.4 s | `Users/Diff/Bin` |

Times are from the benchmark (one pinned core, Python 3.12). Most of the time goes into the parser, which looks up
every service by a linear search.

**Output.** `solutions/<order>.txt` for each of the 26 orders. The file name is the order's name with `/` replaced
by `-`, plus ` reverse` for the reversed direction (for example `solutions/Users-Diff-Bin.txt`). Each file is a
complete submission. The printed list ranks them by the program's own score.

## Changes in this collection

`main()` in `polyhash.py` calls `strategie1`. Upstream calls `strategie2` there and leaves `strategie1` commented
out; the upstream README reports strategy 1's scores. Strategy 2, as shipped, is kept separately as
[`ratio_sorted_lookahead_greedy`](../ratio_sorted_lookahead_greedy/). This is the only change, and it is marked
with a comment. The upstream README (French; team, organisation and strategy notes) is not included.
