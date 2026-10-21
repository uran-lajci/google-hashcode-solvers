> **Ratio-sorted feature greedy with a five-feature look-ahead (strategy 2)**
>
> Source: https://github.com/Loicyeu/google-hashcode-2021 (`strategie2` in `polyhash.py`, the strategy that
> `main()` runs as published)
>
> Method overview:
> 1. Feature orders: the same 26 orders as strategy 1 (13 sort keys from `utils/ratios.py`, each in both
>    directions). The input is parsed and solved again for each order.
> 2. Look-ahead: the next five remaining features of the order are checked against the engineers' current timelines.
>    A feature that cannot be finished before the time limit is dropped. Of the others, the one with the highest
>    estimated score is chosen.
> 3. Assignment: each binary of the chosen feature goes to the engineer with the fewest days of work so far, as in
>    strategy 1 (difficulty + services in the binary + engineers already in the binary on the start day).
> 4. The score estimate in `Challenge.is_implentable` is `min(0, L − finish day) × users`, which is always 0 for a
>    feature that can be finished. So the first feasible feature of the five is taken, and in effect strategy 2 is
>    strategy 1 that skips the features it cannot finish in time. The upstream README notes a bug on B that halves
>    the score.
> 5. Only `impl` tasks are written: no services are moved and no binaries are created.
> 6. Each of the 26 plans is written to `solutions/<order>.txt`, and the program prints its own score for each,
>    best first. In the benchmark every file was scored with the official judge and the best one was kept.
> 7. Deterministic.

# ratio_sorted_lookahead_greedy

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
| B | `b_breadth_of_choice.in.txt` | 49 s | `Users/Diff/Bin` (ties with `Users/Diff/Services` and `Users/Diff`) |
| C | `c_constrained_optimisation.in.txt` | 15 s | `Users` |
| D | `d_distinction.in.txt` | 6 s | `Users/Diff/Services` |
| E | `e_expectation_maximisation.in.txt` | 1.7 s | `Users/Bin` |
| F | `f_five_thousand.in.txt` | 2.7 s | `Users/Diff/Bin` |

Times are from the benchmark (one pinned core, Python 3.12). Most of the time goes into the parser, which looks up
every service by a linear search.

**Output.** `solutions/<order>.txt` for each of the 26 orders. The file name is the order's name with `/` replaced
by `-`, plus ` reverse` for the reversed direction (for example `solutions/Users-Diff-Bin.txt`). Each file is a
complete submission. The printed list ranks them by the program's own score.

## Changes in this collection

None: the code is as published. Strategy 1, which upstream leaves commented out in `main()`, is kept separately as
[`ratio_sorted_greedy_least_busy`](../ratio_sorted_greedy_least_busy/). The upstream README (French; team,
organisation and strategy notes) is not included.
