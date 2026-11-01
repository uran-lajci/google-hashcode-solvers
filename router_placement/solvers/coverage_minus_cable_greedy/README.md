> **Greedy on coverage minus cable distance**
>
> Source: https://github.com/antonin-arquey/polyhash2017
>
> Method overview:
> 1. Scores each cell by the targets a router there would cover, minus its distance to the nearest cable.
> 2. Places the best router, links it to the nearest cable with diagonal steps, and updates the scores.
> 3. Stops when the budget runs out.
>
> Our runs: sum of means 542,187,100 ([scores](../../output/coverage_minus_cable_greedy/scores.md)).

# School project : A solution to the Google Hashcode 2017

This is a solution written in C++ to the 2017 Google Hashcode final task, which is a problem where we needed to optimize router placement.
There is also another program which can validate a solution and calculate the score.
