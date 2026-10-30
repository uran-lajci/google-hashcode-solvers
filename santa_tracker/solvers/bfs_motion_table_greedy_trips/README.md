> **Greedy trips over a precomputed motion table**
>
> Source: https://github.com/Nanored4498/HashCode2022 (`2022/Final/`)
>
> Method overview:
> 1. One program per instance: `b.cpp` to `f.cpp` share the method but have their own constants and rules. There is
>    no program for the example (A).
> 2. Motion table: a breadth-first search over (position, velocity) on one axis gives the fewest seconds, and the
>    carrots needed, to cover any distance and stop. The two axes are flown one after the other. `c`, `e` and `f` keep
>    one table per acceleration range and try both axis orders.
> 3. Greedy choice: from the current position the program repeatedly picks the next target by score per second.
>    `d` (range 0) picks a single gift, and charges for its weight and carrots as well. `b`, `c`, `e` and `f` pick the
>    target cell that reaches the most score within range; `b` only considers gifts on one side of the map.
> 4. `c`, `e` and `f` deliver every gift within range of the flown path, taken by score per kilogram while the load
>    limit allows, and they also charge the score rate for the weight used.
> 5. Trips: the carrots and gifts of a trip are added up while it is planned and loaded at its start. When nothing
>    more fits, or the score rate gets too low, the sleigh returns to Lapland for the next trip. `b` flies one trip.
> 6. Deterministic. The plan goes to stdout, and the program's own score and progress to stderr. The `#pragma omp`
>    lines only take effect when built with `-fopenmp`; the benchmark ran on one core without it.

Scores are given at the end of the contest and after some improvements after the constest.

## HashCode 2022

Solutions of the team Quiche LORIAinne.

### Qualification

| Input | Score at end of contest | Score after contest |
| --- | --- | --- |
| A - An example | 33 | 33 |
| B - Better start small | 897157 | 1003496 |
| C - Collaboration | 228971 | 242898 |
| D - Dense schedule | 251751 | 2178519 |
| E - Exceptional skills | 1640416 | 1648976 |
| F - Find great mentors | 635791 | 899143 |
| Total | 3654119 | 5973065 |
| Rank | 31st | 1st |

### Final

| Input | Score at end of contest | Score after contest |
| --- | --- | --- |
| A - An example | 16 | 16 |
| B - Better hurry | 7329 | 122311 |
| C - Carousel | 830751 | 1692098 |
| D - Decorated houses | 616053 | 621478 |
| E - Excellent weather | 352789 | 1109883 |
| F - Festive flyover | 106507 | 1061182 |
| Total | 1913445 | 4606968 |
| Rank | 18th | 3rd |

## HashCode 2021

### Qualification (not participant / just training)

| Input | Score |
| --- | --- |
| A - An example | 2002 |
| B - By the ocean | 4569829 |
| C - Checkmate | 1313963 |
| D - Daily commute | 2498525 |
| E - Etoile | 731591 |
| F - Forever jammed | 1474439 |
| Total | 10590349 |
| Rank | 1st |

### Final (not participant / just training)

| Input | Score |
| --- | --- |
| A - An example | 540 |
| B - Breadth of choice | 11583040 |
| C - Constrained optimisation | 26632538 |
| D - Distinction | 80845851 |
| E - Expectation Maximisation | 35807231 |
| F - Five Thousand | 120436518 |
| Total | 275305718 |
| Rank | 16th |

## HashCode 2019

Solutions of the team "TEAM TEAM". The code was bugged. After debugging at the end of the contest, we got the following scores

### Qualification

| Input | Score |
| --- | --- |
| A - Example | 3 |
| B - Lovely landscapes | 212583 |
| C - Memorable moments | 1752 |
| D - Pet pictures | 426213 |
| E - Shiny selfies | 445345 |
| Total | 1085896 |
| Rank | 26th |

### Final (not participant / just training)

| Input | Score |
| --- | --- |
| A - Example | 60 |
| B - Narrow | 1530065 |
| C - Urgent | 1934841 |
| D - Typical | 1250354 |
| E - Intriguing | 524288 |
| F - Big | 840971 |
| Total | 6080579 |
| Rank | 7th |