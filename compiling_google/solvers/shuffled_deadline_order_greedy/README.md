> **Earliest-slot greedy over targets in a shuffled deadline order**
>
> Source: https://github.com/LarsAstrom/Hashcode-final-2019 (`mm_sort_shuffle.py`)
>
> Method overview:
> 1. Target order: the targets are sorted by deadline, latest first, and the first 17 are shuffled with the seed. This
>    shuffle is the only randomness, and it decides the score on D (1.08 M to 1.28 M across the 10 seeds).
> 2. Greedy: for each target, every dependency and then the target itself goes to the server with the earliest slot in
>    which its dependencies are available, counting replication times.
> 3. If a file cannot be placed, or the target would miss its deadline, the target is undone and its slots are freed.
> 4. Results: valid on B–E. On E it delivers 1 point, and on F it schedules nothing, which the judge rejects.
> 5. Run: `pypy main.py <instance> -s <seed> --solve module=mm_sort_shuffle` with PyPy 2.7 and the official instance
>    in `in/<instance>.in`. The plan is written to `submission/<instance>.ans`. `main.py`, `util.py`, `score.py` and
>    `default.cfg` are the team's harness.
> 6. The team wrote this on contest day. Only the files this solver needs were copied from the upstream repository.
