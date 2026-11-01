> **Coverage greedy with a Steiner tree**
>
> Source: https://github.com/amadoukane96/Google-HashCode-2017
>
> Method overview:
> 1. Places routers one at a time at the cell that covers the most targets, ignoring cable cost.
> 2. Connects them with the Takahashi-Matsuyama Steiner tree heuristic.
> 3. While over budget, drops the last router and rebuilds the tree.
>
> Our runs: sum of means 539,104,228 ([scores](../../output/greedy_coverage_steiner_tree/scores.md)).

# Google-HashCode-2017