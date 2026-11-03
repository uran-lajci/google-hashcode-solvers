> **Priority queue on ingredient distance, then improvement passes**
>
> Source: https://github.com/GaspareG/HashCode-Practice
>
> Method overview:
> 1. Scores each cell by how far it is from the nearest of each ingredient (`flood`) and keeps cells in a priority queue.
> 2. Cuts slices in that order (`trovaSoluzioni`).
> 3. Runs 5,000 improvement passes (`migliora`) that grow the slices.
>
> Our runs: sum of means 954,588 ([scores](../../output/distance_priority_queue_with_improvement/scores.md)).

# HashCode-Practice
Solution for HashCode practice problem "Pizza"

Execution
-------
Run `./test.sh` in terminal

Points
-------

- Example: **15** / 15 (100%)
- Small: **38** / 42 (90.47%)
- Medium: **49,255** / 50,000 (98.51%)
- Big: **905,295** / 1,000,000 (90.52%)

Total score: **954,603** / 1,050,057 (90.90%)

Visualization 
-------------

_(images from [visualzer](https://hashcode-pizza.now.sh/))_

**EXAMPLE**

![example](/visualization/example.png)

**SMALL**

![small](/visualization/small.png)

**MEDIUM**

![medium](/visualization/medium.png)

**BIG**

![big](/visualization/big.png)
