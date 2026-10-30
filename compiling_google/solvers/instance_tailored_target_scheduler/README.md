> **Target schedulers tailored to each instance**
>
> Source: https://github.com/Nanored4498/HashCode2022 (`2019/`)
>
> Method overview:
> 1. One program per group of instances: `acd.cpp` (A, C, D), `b.cpp`, `e.cpp` and `f.cpp`. Each exploits the structure
>    of its instances. They were written after the contest, as training. `verifier.cpp` is the author's own checker.
> 2. `acd.cpp`, partition: a target with exactly 100 dependencies gets a subset-sum dynamic program that splits them
>    over the servers so that it just meets its deadline.
> 3. `acd.cpp`, greedy: for each remaining target it simulates compiling the target's files in order of critical-path
>    length, each on the server where it can start first, and it keeps the target with the best gain per added server
>    time. This repeats until no target fits.
> 4. `b.cpp` uses a fixed layout: the shared files are compiled per target on fixed groups of servers, and the remaining
>    dependencies go to the server that fits best.
> 5. `e.cpp` splits the dependencies of a single target over the servers with repeated subset-sum dynamic programs.
> 6. `f.cpp` gives every target that can meet its deadline its own server, and compiles its direct dependencies there.
> 7. Deterministic: there is no randomness. The plan goes to stdout and the program's own score to stderr.

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