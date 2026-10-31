from __future__ import annotations

import csv
import glob
import json
import os
from argparse import ArgumentParser

FIELDNAMES = ['run', 'iteration', 'event', 'score', 'best_score', 'decision']


def process_file(log_path: str, writer: csv.DictWriter[str], run_name: str) -> None:
    best_score = None

    with open(log_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
            except json.JSONDecodeError:
                continue

            it = obj.get('iter')
            if it is None:
                continue

            event = obj.get('event')
            score = obj.get('score')
            best_score = obj.get('best', best_score)

            if event == 'baseline':
                decision = 'baseline'
                if score is not None:
                    best_score = score
            elif event == 'accept':
                decision = 'accepted'
                if score is not None and (best_score is None or score > best_score):
                    best_score = score
            elif event == 'reject':
                decision = 'rejected'
            else:
                # Any error event (compile_error, run_error, apply_error, parse_error): no score
                decision = 'failed'
                score = -1

            writer.writerow({
                'run': run_name,
                'iteration': it,
                'event': event,
                'score': score if score is not None else -1,
                'best_score': best_score if best_score is not None else -1,
                'decision': decision,
            })


def main(files: list[str], output: str = 'traces.csv') -> None:
    all_files = []
    for pattern in files:
        for path in glob.glob(pattern):
            if os.path.isfile(path):
                all_files.append(path)

    if not all_files:
        print('No files found.')
        return

    with open(output, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=FIELDNAMES)
        writer.writeheader()

        for path in all_files:
            run_name = os.path.basename(path)
            print(f'Processing {run_name}...')
            process_file(path, writer, run_name)

    print(f'Done. Wrote traces to {output}')


if __name__ == '__main__':
    parser = ArgumentParser(description='Extract per-iteration traces from JSON logs.')
    parser.add_argument('files', nargs='+', help='JSON log files or glob pattern (e.g., *.json)')

    parser.add_argument('-o', '--output', type=str, default='traces.csv', help='Output CSV file name')

    args = parser.parse_args()
    main(args.files, args.output)
