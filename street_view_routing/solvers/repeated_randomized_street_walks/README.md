> **Repeated randomized street walks**
>
> Source: https://github.com/jilljenn/hashcode2014 (`thomas/`)
>
> Method overview:
> 1. One OCaml program with four modes for planning the cars, one after another:
>    - `greedy`: each car takes the shortest path to a random junction, then keeps taking the unused street with the
>      best score. When no unused street is next to it, Dijkstra takes it to the nearest one.
>    - `center`: each car gets a random junction as its center, and the street choice is weighted towards staying near it.
>    - `clock`: each car turns by a clockwise rule at each junction, taking an unused street if there is one. Otherwise
>      it follows Dijkstra to the nearest unused street.
>    - `plan_clock`: as `clock`, but every car after the first starts from a random junction.
> 2. The `iter` argument repeats the chosen mode with new random choices, without end, and writes each plan that beats
>    the best so far to `sols/out_<score>`.
>
> Run it as `./main.native <mode> iter < hashcode_2014_final_round.in`. It does not stop by itself, and the highest
> `sols/out_<score>` file is the result. A kill during a write can cut the newest file short, so check it with the judge.
> `sols/out_1916551` is the only stored plan kept from upstream: the judge gives it 1,916,551, the score of the second-placed team.
> Only the OCaml code and its Makefile were copied, not the repo's other files (including `main.cpp`, whose outputs the
> judge rejected, and the stored plans). OCaml 4.14 is needed, because OCaml 5 removed `Scanf.fscanf`.
>
> The rest of this file is the upstream README.

hashcode2014
============

Solutions for Google Hash Code 2014
