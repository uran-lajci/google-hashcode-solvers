# random_restart_greedy_astar: scores

Solver: [`solvers/random_restart_greedy_astar/`](../../solvers/random_restart_greedy_astar/). Instances B–F of Hash Code 2020 Final, 10 seeds each. Every output was scored with `google-hashcode-judge/assembling_smartphones/judge.py`. Outputs: `<instance>/seed_<s>.out`.

## Scores per run

| Seed | B (`b_single_arm`) | C (`c_few_arms`) | D (`d_tight_schedule`) | E (`e_dense_workspace`) | F (`f_decentralized`) | Sum |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 342,964 | 1,431,890 | 1,344,679 | 1,105,254 | 1,720,065 | 5,944,852 |
| 12 | 342,964 | 447,800 | 1,344,679 | 1,105,254 | 1,720,065 | 4,960,762 |
| 23 | 327,642 | 1,230,747 | 1,344,679 | 1,105,254 | 1,767,691 | 5,776,013 |
| 34 | 337,993 | 1,337,669 | 1,344,679 | 1,105,254 | 1,758,645 | 5,884,240 |
| 45 | 348,704 | 500,236 | 1,344,679 | 1,105,254 | 1,719,474 | 5,018,347 |
| 56 | 348,704 | 1,230,747 | 1,344,679 | 1,105,254 | 1,758,645 | 5,788,029 |
| 67 | 353,434 | 1,446,935 | 1,344,679 | 1,105,254 | 1,767,691 | 6,017,993 |
| 78 | 342,964 | 1,364,050 | 1,344,679 | 1,105,254 | 1,720,065 | 5,877,012 |
| 89 | 351,250 | 848,568 | 1,344,679 | 1,105,254 | 1,720,065 | 5,369,816 |
| 100 | 353,247 | 1,296,749 | 1,344,679 | 1,105,254 | 1,719,474 | 5,819,403 |

## Statistics per instance

| Instance | Best | Mean | Median | Std dev | Worst | Valid runs | Mean time (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| b_single_arm | 353,434 | 344,987 | 345,834 | 7,948 | 327,642 | 10/10 | 0.7 |
| c_few_arms | 1,446,935 | 1,113,539 | 1,263,748 | 376,547 | 447,800 | 10/10 | 50.0 |
| d_tight_schedule | 1,344,679 | 1,344,679 | 1,344,679 | 0 | 1,344,679 | 10/10 | 8.9 |
| e_dense_workspace | 1,105,254 | 1,105,254 | 1,105,254 | 0 | 1,105,254 | 10/10 | 60.8 |
| f_decentralized | 1,767,691 | 1,737,188 | 1,720,065 | 22,564 | 1,719,474 | 10/10 | 110.3 |

Sum of means: 5,645,647. Sum of best runs: 6,017,993.

## Run setup

- Seeds: 1, 12, 23, 34, 45, 56, 67, 78, 89, 100.
- Command: `python main.py -m <B|C|D|E|F>` from a fresh copy of the folder, with the default parameters in `param_from_arg` and one iteration (no `-i`). Python 3.12 with Pillow 13.0.0, `PYTHONHASHSEED=0`.
- At most 6 runs at a time, each pinned with `taskset` to its own physical core (CPUs 0, 2, 4, 6, 8, 10), with a 10-minute wall-clock limit (`timeout -k 10 600`).
- One code change, applied to the copy only (the folder in `solvers/` is unchanged): `random.seed(int(os.environ["HC_SEED"]))` right after `import random` in `main.py`. Upstream never seeds `random`.
- The output file of each run (`<input>.txt_<score>.out`) was copied to `<instance>/seed_<s>.out`.
