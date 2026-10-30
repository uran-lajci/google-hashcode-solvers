> **Subset-sum partition for C, then earliest-slot greedy**
>
> Source: https://github.com/LarsAstrom/Hashcode-final-2019 (`solve_c_la.py`)
>
> Method overview:
> 1. This solver is written for instance C only. On the other instances it crashes or scores 0.
> 2. Partition: the target with exactly 100 direct dependencies is split over the servers by a subset-sum dynamic
>    program, so that each server's total compile time stays just under the target's limit.
> 3. Greedy: the remaining targets are taken in order. Each file of a target goes to the server with the earliest free
>    slot in which its dependencies are available. A target that cannot meet its deadline is undone.
> 4. Randomized: `random.seed(seed)` with the `-s` option, and part of the order is shuffled.
> 5. Run: `pypy main.py c_urgent -s <seed> --solve module=solve_c_la` with PyPy 2.7 and the official instance in
>    `in/c_urgent.in`. The plan is written to `submission/c_urgent.ans`. `main.py`, `util.py`, `score.py` and `default.cfg`
>    are the team's harness.
> 6. The team wrote this on contest day. Only the files this solver needs were copied from the upstream repository.
