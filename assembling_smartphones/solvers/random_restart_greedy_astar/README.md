# random_restart_greedy_astar

## Environment

The pinned versions in `requirements.txt` (numpy 1.19.3, Pillow 8.0.1, matplotlib 3.3.2) only install on
Python 3.9 or older. With [uv](https://docs.astral.sh/uv/), from this folder:

```bash
uv venv --python 3.9 .venv
source .venv/bin/activate
uv pip install -r requirements.txt
```

Without uv, on a machine that has Python 3.9:

```bash
python3.9 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

The code itself only imports Pillow and `tkinter` (for the optional live view). On a newer Python, this is enough:

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install Pillow
```

`tkinter` is part of the standard library, but some Linux distributions ship it separately (Debian/Ubuntu:
`sudo apt install python3-tk`).

## Input files

`main.py` reads the official inputs from `data/input/`, relative to the folder it is run from. Put the six files
from the Hash Code 2020 Final Round there under their original names:

```
data/input/a_example.txt
data/input/b_single_arm.txt
data/input/c_few_arms.txt
data/input/d_tight_schedule.txt
data/input/e_dense_workspace.txt
data/input/f_decentralized.txt
```

For example, from a clone of [google-hashcode-archive](https://github.com/pierreavn/google-hashcode-archive):

```bash
mkdir -p data/input
cp <archive>/archive/2020/final/hashcode_2020_final_round.in/*.txt data/input/
```

## Running each instance

Run from this folder, with the environment active:

```bash
python main.py -m A
python main.py -m B
python main.py -m C
python main.py -m D
python main.py -m E
python main.py -m F
```

| Instance | Command | Parameters used | Time per run |
|---|---|---|---:|
| A | `python main.py -m A` | none: writes a fixed hand-made solution | < 1 s |
| B | `python main.py -m B` | default set for B | ~2 s |
| C | `python main.py -m C` | default set for C (`MAX_DIST_PM` and `ADDITION` drawn at random each run) | ~35 s |
| D | `python main.py -m D` | default set for D (fixed) | ~8 s |
| E | `python main.py -m E` | default set for E (fixed) | ~155 s |
| F | `python main.py -m F` | default set for F (`MAX_DIST_PM` drawn at random each run) | ~110 s |

The default sets are in `param_from_arg` in `main.py`. The authors wrote the ones for C, D and F. The ones for B and
E were added in this collection; upstream, B and E stop with an `ArgumentTypeError` unless all four parameters are
given on the command line.

**Output.** A writes `a.out`. The other instances write `<input file>_<score>.out` (for example
`d_tight_schedule.txt_1344679.out`) in the current folder, each time a run beats the best score so far.

### Optional arguments

| Argument | Meaning |
|---|---|
| `-i N`, `--iteration N` | Repeat the search N times (default 1) and keep the best solution. Each repetition draws new random parameters where a range is given, and a new mount-point order. |
| `--MAX_STUCK a [b]` | Turns a robot may be blocked before it is forced to retract (int). |
| `--MAX_DIST_PM a [b]` | Largest Manhattan distance between a robot's mount point and a task it takes (int). |
| `--ADDITION w1 w2 w3 w4` (or 8 values) | The four weights used when choosing the next task (float). |
| `--FACTEUR_CONCENTRATION_BRAS a [b]` | Scales the minimum spacing between mount points of different robots (float). |
| `-v`, `--verbose` | Prints progress. |
| `-g`, `--graphique` | Opens the live `tkinter` view (much slower). |

A parameter given with two values (eight for `ADDITION`) is drawn uniformly from that range in every iteration.
Parameters given on the command line replace the defaults. Two caveats: the command line sorts the values of
`--ADDITION`, so four values are not used in the order given, and it reads all `ADDITION` values as floats.

Example, 20 restarts on C with its default (randomized) parameters:

```bash
python main.py -m C -i 20
```

The code never seeds Python's `random` module, so scores on B, C and F change from one run to the next. D and E
gave the same score on every run we tried.
