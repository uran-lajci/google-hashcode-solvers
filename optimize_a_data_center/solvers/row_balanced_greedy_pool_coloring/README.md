> **Row-balanced greedy placement, then pool assignment by row spread**
>
> Source: https://github.com/nicolas-legroux/HashCode2015-QualificationRound
>
> Method overview:
> 1. Placement (`Repartition.java`): sorts the servers by capacity divided by size to the power 1.5. Each goes to a gap of exactly its size if there is one, otherwise a larger gap, in the row with the least capacity so far.
> 2. Pools (`Coloriage.java`): takes the servers by capacity, and gives each to the pool with the fewest servers in that server's row, using the lower pool score to break ties.
> 3. Deterministic.
>
> In our runs: 391 ([scores](../../output/row_balanced_greedy_pool_coloring/scores.md)).
