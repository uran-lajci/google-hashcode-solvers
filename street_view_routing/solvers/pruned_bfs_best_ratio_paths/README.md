> **Pruned BFS for the path with the best length per second**
>
> Source: https://github.com/jp172/google-hash-code-solutions (`2014/`)
>
> Method overview:
> 1. Simulation: the cars sit in a queue ordered by the time each becomes free. The earliest free car gets its next
>    path, then returns to the queue. A car with no useful path left drops out.
> 2. Search: a breadth-first search from the car's junction tries paths of up to 19 streets that never repeat a
>    junction and end by time T. A path's value is the length of its streets not yet covered, divided by its total
>    driving time.
> 3. Pruning: a path ending on an uncovered street is extended only if its value is above half of the best value found
>    so far. A path ending on a covered street is always extended, because it costs time but may reach new streets.
> 4. The car takes the whole best path, and its streets are marked covered at once.
>
> The program is deterministic. The start junction is hard-coded as 4516, the one in the official Paris instance, so
> other instances need that line changed. Run it from `src/`: it reads `../data/<name>.in` and writes `../out/<name>.out`.
>
> The rest of this file is the upstream README, which also covers the author's solutions to other problems. Those are
> not part of this folder.

# Google Hash Code Solutions
In this repo I gradually add my solutions to various google hash code tasks I solved throughout the years. You can find the original problem statements and input data [here](https://codingcompetitions.withgoogle.com/hashcode/archive).

# Results on original instances
* Pizza Warm-Up: With an area choice of 15x15, the pizza is cut quite decent with 49987/50000 on medium and 965521/1000000 on big.
* (2014) Street View Routing: The pruned bfs yields 1930138, outperforming the on-site scores.
* (2015) Optimize a data center: The result of 390 is a top 15 place regarding the on-site scores.
* (2016) Drone delivery: The algorithm gives a score of ~273100, which would have been enough to get into the finals.
* (2017) Streaming Videos: This solution would have placed you 21st in the qualifications. Back then, I got into 50th with AG Global Opt :) (using a Knapsack for populating every cache server one after another)
