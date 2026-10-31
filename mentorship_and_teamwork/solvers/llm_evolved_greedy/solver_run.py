import os
import re
import shutil
import subprocess
import sys
from argparse import ArgumentParser

COMPILER = 'g++'

# Tried in order; the first standard that compiles wins, so a C++17 solver
# keeps building under C++17 and a C++20-only solver falls through to C++20.
CPP_STANDARDS = ('c++17', 'c++20')

# Matches ANSI colour escapes the validator wraps around the score number.
_ANSI_RE = re.compile(r'\x1b\[[0-9;]*m')
_SCORE_RE = re.compile(r'Score:\s*([\d,]+)')


def compile_solver(source_path):
    """Compile the solver, trying each C++ standard in turn.

    Returns (ok, binary_path, stderr). On success stderr is from the standard
    that built; on failure it is from the last standard tried.
    """
    binary_path = os.path.splitext(source_path)[0]
    stderr = ''
    for std in CPP_STANDARDS:
        compile_cmd = [COMPILER, '-O2', f'-std={std}', '-pipe', source_path, '-o', binary_path]
        proc = subprocess.run(compile_cmd, capture_output=True, text=True)
        stderr = proc.stderr
        if proc.returncode == 0:
            return True, binary_path, stderr

    return False, binary_path, stderr


def run_and_score(binary_path, input_path, output_path, validator_dir, timeout=600):
    """Run the solver on input_path, validate the output, and parse the score.

    Returns (score, detail). score is an int on success, or None on a hard
    failure (crash, timeout, or an invalid submission with no Score: line);
    detail is a short human-readable explanation in that case.
    """
    # The solver writes its answer to stdout and progress logs to stderr.
    with open(input_path) as stdin, open(output_path, 'w') as stdout:
        try:
            result = subprocess.run(
                [os.path.abspath(binary_path)],
                stdin=stdin,
                stdout=stdout,
                stderr=subprocess.DEVNULL,
                timeout=timeout,
            )
        except subprocess.TimeoutExpired:
            return None, f'solver exceeded {timeout}s budget'

    if result.returncode != 0:
        return None, f'solver exited with code {result.returncode}'

    # The validator's readFile always joins __dirname with the given path,
    # so we must pass a path relative to the validator directory, and the
    # submission must live next to the input as <input>.out.txt.
    abs_input = os.path.abspath(input_path)
    rel_input = os.path.relpath(abs_input, validator_dir)
    expected_out = f'{abs_input}.out.txt'
    if os.path.abspath(output_path) != expected_out:
        shutil.copy2(output_path, expected_out)

    val = subprocess.run(
        ['node', 'index.js', rel_input],
        cwd=validator_dir,
        capture_output=True,
        text=True,
    )
    out = _ANSI_RE.sub('', val.stdout)
    match = _SCORE_RE.search(out)
    if match is None:
        detail = (val.stderr or out or 'validator produced no Score: line').strip()
        return None, f'invalid submission: {detail[:200]}'
    return int(match.group(1).replace(',', '')), 'ok'


def main(solver_path, input_path, output_path, validator_dir):
    ok, binary_path, stderr = compile_solver(solver_path)
    if not ok:
        print(stderr, file=sys.stderr)
        sys.exit('Compilation failed.')

    score, detail = run_and_score(binary_path, input_path, output_path, validator_dir)
    if score is None:
        sys.exit(detail)
    print(f'Score: {score}')


if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-s', '--solver', type=str, required=True, help='path to the .cpp solver')
    parser.add_argument('-i', '--input_path', type=str, required=True)
    parser.add_argument('-o', '--output_path', type=str, required=True)
    parser.add_argument('-V', '--validator', type=str, required=True, help='validator directory')

    args = parser.parse_args()
    main(args.solver, args.input_path, args.output_path, args.validator)
    