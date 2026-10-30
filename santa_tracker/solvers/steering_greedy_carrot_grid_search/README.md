> **Steering greedy with a grid search over load and carrots**
>
> Source: https://github.com/indjev99/Optimizational-Problems-Solutions (`santa.cpp`)
>
> Method overview:
> 1. Grid search: the whole simulation is repeated for pairs (gift capacity, carrots per trip). The total weight goes
>    from the heaviest weight limit down to half of it in steps of ÷1.25, and carrots grow from 1 in steps of ×1.25.
>    The plan with the highest score is written.
> 2. One simulation advances one second at a time. Each second it delivers every unused gift within range that still
>    fits the capacity left, then feeds at most one carrot, then floats for one second.
> 3. Steering: the target is the unused gift with the best score ÷ distance from the sleigh's next position; with no
>    such gift, it is Lapland. The wanted velocity points at the target, fast (3.5 × range + 8 × acceleration + 1) when
>    the target is more than 12 ranges away and at range speed otherwise. Each second the axis with the larger
>    velocity error is corrected.
> 4. Trips: whenever the sleigh passes within range of Lapland, carrots and capacity are restored. Gifts are decided
>    only when delivered: their `LoadGift` lines are inserted afterwards at the last visit to Lapland.
> 5. Deterministic (`srand(42)` is called, but nothing uses it).
> 6. Input and output: the program reads the instance number from stdin (0 = A, 1 = B, …), reads `a.txt` to `f.txt`
>    and writes `sol_<letter>.txt`, all in the working directory.

# Optimizational-Problems-Solutions

The rest of this repository covers other contests. Only `santa.cpp` was copied, and the upstream repository has no
licence file.
