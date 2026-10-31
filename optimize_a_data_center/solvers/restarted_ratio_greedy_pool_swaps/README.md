> **Greedy by capacity per square root of size, restarted, with pool swaps**
>
> Source: https://github.com/phlalx/hashcode-2015 (`qualification/`)
>
> Method overview:
> 1. Sorts the servers by capacity divided by the square root of their size, breaking ties at random.
> 2. Places each server and gives it to the pool that currently has the lowest guaranteed capacity.
> 3. Local search: swaps a server of the worst pool with a server of another pool whenever that raises the objective. The objective is 100 times the score, plus a bonus for having few pools at the minimum.
> 4. Restarts from a new tie-break order, forever, and keeps the best.
>
> In our runs: 400 on all 10 runs ([scores](../../output/restarted_ratio_greedy_pool_swaps/scores.md)).
>
> We added one thing: `main.cpp` writes `best.out` when a restart beats the best so far, because the original loop never reaches its output. The program also crashes with a memory error on some runs, which we did not fix (see the scores).

# hashcode-2015

> Hash Code is a team-based programming competition organized by Google for students and industry professionals across Europe, the Middle East and Africa. You pick your team and programming language, we pick a real-life engineering problem for you to solve. Are you up for the challenge?

These were submissions to the Google Hashcode 2015 contest (qualification and finale). 
See [here](https://hashcode.withgoogle.com/index.html) for a description of the problems.
