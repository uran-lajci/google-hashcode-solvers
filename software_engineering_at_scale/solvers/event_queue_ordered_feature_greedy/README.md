> **Ordered feature greedy on an event-queue simulation**
>
> Source: https://github.com/Pankin610/feature-assignment
>
> Method overview:
> 1. Feature order: the features are sorted once, by users ÷ (difficulty × number of binaries that hold the
>    feature's services), highest first (`sol/ordered_feature_implementation_producer.cpp`).
> 2. Simulation: a state model with event queues tracks engineers, binaries and features. `ProducerBasedSolver` asks
>    the producer for the actions of the current day, applies them and advances time by one day, until the time
>    limit.
> 3. Each day, every free engineer takes the first feature in that order that is still unimplemented and has a
>    binary in which nobody is implementing it yet, and implements it there. This takes difficulty + services in the
>    binary + engineers already working on the binary days.
> 4. An engineer with nothing to start waits one day.
> 5. Only `impl` and `wait` tasks are written. The state model also has service moves and new binaries, but this
>    producer never uses them.
> 6. Deterministic. The plan goes to stdout and the program's own score to stderr.

# event_queue_ordered_feature_greedy

## Environment

A C++17 compiler. Upstream builds with [Bazel](https://bazel.build/); the `BUILD` files and `WORKSPACE` are kept as
published. Bazel was not used for the benchmark. It is also unnecessary: g++ can build the program directly from this
folder:

```bash
g++ -O2 -std=c++17 -I. -include stdexcept -include algorithm -o run_solution \
    binary/run_solution.cpp sol/producer_based_solver.cpp sol/ordered_feature_implementation_producer.cpp \
    sol/solution.cpp state/*.cpp
```

These are the sources of the Bazel target `//binary:run_solution`. The two `-include` flags are needed with GCC 13:
`state/binary_maintainer.h` uses `std::runtime_error` without including `<stdexcept>`, and
`sol/ordered_feature_implementation_producer.cpp` uses `std::sort` without including `<algorithm>`. Older standard
libraries included both indirectly. The flags only make those declarations visible; the code is unchanged.

With Bazel (a version that still reads `WORKSPACE`): `bazel build //binary:run_solution`, then use
`bazel-bin/binary/run_solution`.

## Input files

The program reads the instance from stdin. The official inputs are in
[google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive) under
`archive/2021/final/hashcode_2021_final_round.in/`.

## Running each instance

```bash
./run_solution < b_breadth_of_choice.in.txt > b.out
```

| Instance | Command | Time per run |
|---|---|---:|
| A | `./run_solution < a_example.in.txt > a.out` | < 0.1 s |
| B | `./run_solution < b_breadth_of_choice.in.txt > b.out` | 0.1 s |
| C | `./run_solution < c_constrained_optimisation.in.txt > c.out` | 0.5 s |
| D | `./run_solution < d_distinction.in.txt > d.out` | 0.1 s |
| E | `./run_solution < e_expectation_maximisation.in.txt > e.out` | 1.8 s |
| F | `./run_solution < f_five_thousand.in.txt > f.out` | < 0.1 s |

Times are from the benchmark (one pinned core, `g++ -O2`). There are no parameters and no randomness.

## Not included from upstream

The repository's unit tests (`tests/`, which need GoogleTest through the `WORKSPACE`) and its run scripts
(`run_all_tests.sh`, `test_list.sh`, `hashcode_tests/BUILD`, which loop over the official inputs) are not included.
`binary/get_test_info.cpp` prints input statistics and is kept because `binary/BUILD` declares it.
