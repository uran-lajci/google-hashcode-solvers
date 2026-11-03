> **Priority on shape counts, with recursive repair**
>
> Source: https://github.com/RobertObkircher/pizza
>
> Method overview:
> 1. Counts the valid shapes at each cell and places slices where options are fewest.
> 2. `solve_recursive` then tries combinations around the leftover cells to raise the score.
>
> Our runs: sum of means 951,505 ([scores](../../output/shape_count_priority_with_recursive_repair/scores.md)).

# pizza
Hash Code is a coding competition by Google.

This is my attempt at solving one of the practice problems.

The exact problem statement is in "pizza.pdf".

Current score
-------------

### main_without_useless_stuff.c

- Medium 49509 

- Big 897164 

(0.07 seconds for all 4 input files)

### main.c

- Medium 48887 

- Big 902584 

(~3 seconds for all 4 input files)
