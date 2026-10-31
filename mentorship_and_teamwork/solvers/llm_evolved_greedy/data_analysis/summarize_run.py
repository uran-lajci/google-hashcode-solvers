import json
import os
from argparse import ArgumentParser

RUNS_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'runs')


def main(file_name: str) -> None:
    file_path = os.path.join(RUNS_DIR, file_name, 'history.jsonl')

    data = []
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if line:
                data.append(json.loads(line))

    accepts_improv = 0
    accepts_tie = 0
    rejects = 0
    compile_errors = 0
    apply_errors = 0
    run_errors = 0

    baseline_score = None
    for sample in data:
        if sample.get('event') == 'baseline':
            baseline_score = sample['score']
            break

    running_best = baseline_score
    for sample in data:
        event = sample.get('event')

        if event == 'accept':
            new_score = sample['score']
            if new_score > running_best:
                accepts_improv += 1
            elif new_score == running_best:
                accepts_tie += 1
            # sample['best'] is the new global best after this iteration
            running_best = sample['best']

        elif event == 'reject':
            rejects += 1

        elif event == 'compile_error':
            compile_errors += 1

        elif event == 'apply_error':
            apply_errors += 1

        elif event == 'run_error':
            run_errors += 1

    best_score = running_best
    improvement = best_score - baseline_score if baseline_score is not None else 0

    totals = next((s for s in data if s.get('event') == 'totals'), None)
    if totals:
        input_tokens = totals.get('input', 0)
        output_tokens = totals.get('output', 0)
        cache_read = totals.get('cache_read', 0)
        cache_write = totals.get('cache_write', 0)
        cost_usd = totals.get('cost_usd', 0.0)
    else:
        input_tokens = output_tokens = cache_read = cache_write = 0
        cost_usd = 0.0

    print(f'Nr Accepts Improv: {accepts_improv}')
    print(f'Nr Accepts Tie:    {accepts_tie}')
    print(f'Nr Rejects:        {rejects}')
    print(f'Compile Error:     {compile_errors}')
    print(f'Apply Error:       {apply_errors}')
    print(f'Run  Error:        {run_errors}')
    print(f'Best Score:        {best_score}')
    print(f'Improvement:       {improvement}')
    print(f'Input Tokens:      {input_tokens}')
    print(f'Output Tokens:     {output_tokens}')
    print(f'Cache Read:        {cache_read}')
    print(f'Cache Write:       {cache_write}')
    print(f'Cost (in dollars): {cost_usd:.8f}')


if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-f', '--file_name', type=str, required=True)

    args = parser.parse_args()
    main(args.file_name)
