> **Scored greedy with a minimum spanning tree backbone**
>
> Source: https://github.com/matteojug/hashcode17_finals
>
> Method overview:
> 1. Scores each cell by coverage, with weights for neighbouring walls and covered cells.
> 2. Places the best router the budget allows, keeping an estimate of the cable cost.
> 3. Rebuilds the backbone as a minimum spanning tree over the routers (`fix_backbone`) and continues with what is left of the budget.
> 4. `param_tuning.py` searches the weights, and we ran the defaults. `cplex/test.cpp` needs a CPLEX license and was not run.
>
> Our runs: sum of means 539,137,647 ([scores](../../output/scored_greedy_with_mst_backbone/scores.md)).
