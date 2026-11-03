> **Guillotine-cut dynamic programming on 100-by-100 blocks**
>
> Source: https://github.com/ClementChouteau/Hashcode-2018-entrainement
>
> Method overview:
> 1. `progdyn_bloc.cpp` splits the pizza into 100-by-100 blocks and solves each block on its own.
> 2. For each sub-rectangle of a block, the best covered area is the whole rectangle if it is a valid slice, and otherwise the best sum over every horizontal or vertical cut into two parts. The results are memoized over all sub-rectangles.
> 3. It then rebuilds the slices from the table. `big` has 100 blocks, and it wrote nothing there in 10 minutes.
> 4. `glouton.cpp` in the same folder is a greedy that cuts the largest rectangle that fits at each cell. It is within 5% (943,880) but ranked 19th, so it is not kept for itself. `progdyn.cpp` is an earlier version without blocks.
>
> Our runs: first on `medium` (49,998); nothing on `big` in 10 minutes ([scores](../../output/guillotine_block_dynamic_programming/scores.md)).
