import glob
import json
import os
from argparse import ArgumentParser
from collections.abc import Iterator


def extract_improving_edits(log_file: str) -> Iterator[tuple[int, float, list[list[str]]]]:
    best = None
    with open(log_file, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
            except json.JSONDecodeError:
                continue

            if obj.get('event') == 'baseline':
                best = obj.get('score')
                continue

            if obj.get('event') != 'accept':
                continue

            score = obj.get('score')
            if score is None:
                continue

            if best is None or score > best:
                best = score
                yield (obj.get('iter'), score, obj.get('blocks', []))


def write_improvements(log_path: str, out_path: str) -> None:
    count = 0
    with open(out_path, 'w', encoding='utf-8') as out:
        out.write(f'Extracted from: {os.path.basename(log_path)}\n\n')
        for it, score, blocks in extract_improving_edits(log_path):
            count += 1
            out.write(f'Iteration {it}: score {score}\n')
            for i, block in enumerate(blocks, 1):
                if len(block) == 2:
                    out.write(f'  Block {i}:\n')
                    out.write('<<<<<<< SEARCH\n')
                    out.write(block[0])
                    out.write('\n=======\n')
                    out.write(block[1])
                    out.write('\n>>>>>>> REPLACE\n\n')
                else:
                    out.write(f'  Block {i}: (unexpected format) {block}\n\n')
            out.write('-' * 80 + '\n\n')
        out.write(f'Total improving edits: {count}\n')
    print(f'Wrote {count} edits to {out_path}')


def main(files: list[str]) -> None:
    for pattern in files:
        for path in glob.glob(pattern):
            if not os.path.isfile(path):
                continue
            out_path = path + '.improvements.txt'
            write_improvements(path, out_path)


if __name__ == '__main__':
    parser = ArgumentParser(description='Extract all improving edits from MicroEvolve run logs.')
    parser.add_argument('files', nargs='+', help='JSON log files or glob pattern (e.g., *.json)')

    args = parser.parse_args()
    main(args.files)
