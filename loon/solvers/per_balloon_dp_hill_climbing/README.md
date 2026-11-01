> **Dynamic programming per balloon, with hill climbing**
>
> Source: https://github.com/yoann-dufresne/loon
>
> Method overview:
> 1. Plans one balloon at a time with dynamic programming over turn, row, column and altitude. A cell is worth the targets it covers at that turn that no other balloon covers yet, so each balloon works around the ones before it.
> 2. A balloon may launch in the first 20 turns.
> 3. Hill climbing: takes out two random balloons, plans them again, and puts the old paths back if the score fell.
>
> In our runs: 683,482 best, mean 682,207.0 ([scores](../../output/per_balloon_dp_hill_climbing/scores.md)).
>
> We changed three things. The original driver plans only up to 6 balloons, so `loon.cpp` now plans all 53 and then repeats the hill climbing step, writing `results/best.txt` as the score improves. The arrays in `DynamicProgramming.cpp` were one altitude too small, which crashed the program, so they now have room for it. We also added the missing `#include <cstddef>` to `Coordz.h`, so it compiles.
