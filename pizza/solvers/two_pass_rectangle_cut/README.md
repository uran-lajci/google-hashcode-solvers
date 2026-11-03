> **Two passes of rectangle cuts, in Rust**
>
> Source: https://github.com/nappa85/HashCode2018
>
> Method overview:
> 1. `cut` scans the free cells and saves the first valid rectangle from each.
> 2. A second pass over the cells follows. It scores 954,688, against 942,563 for the PHP version in the same author's 2017 repository.
>
> Our runs: sum of means 954,688 ([scores](../../output/two_pass_rectangle_cut/scores.md)).
