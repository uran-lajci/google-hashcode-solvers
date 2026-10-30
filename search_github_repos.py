import json
import os
import time
import urllib.parse
import urllib.request
from argparse import ArgumentParser

import pandas as pd

API_URL = 'https://api.github.com/search/repositories'


def fetch_page(query: str, page: int, token: str) -> tuple[list[dict[str, str]], int]:
    params = urllib.parse.urlencode({'q': query, 'per_page': 100, 'page': page})
    request = urllib.request.Request(f'{API_URL}?{params}')
    request.add_header('Accept', 'application/vnd.github+json')
    if token:
        request.add_header('Authorization', f'Bearer {token}')

    with urllib.request.urlopen(request) as response:
        data = json.load(response)

    repos = [
        {
            'full_name': item['full_name'],
            'url': item['html_url'],
            'description': item['description'] or '',
            'language': item['language'] or '',
            'created_at': item['created_at'],
            'pushed_at': item['pushed_at'],
            'stars': str(item['stargazers_count']),
        }
        for item in data['items']
    ]
    return repos, int(data['total_count'])


def main(queries_path: str,

         output_path: str = 'repositories.csv') -> None:
    token = os.environ.get('GITHUB_TOKEN', '')
    # Search API limits: 30 requests per minute with a token, 10 without
    delay = 2.1 if token else 6.1

    with open(queries_path, encoding='utf-8') as f:
        queries = [line.strip() for line in f if line.strip()]

    found: dict[str, dict[str, str]] = {}
    for query in queries:
        page = 1
        while True:
            repos, total = fetch_page(query, page, token)
            time.sleep(delay)

            for repo in repos:
                entry = found.setdefault(repo['full_name'], {**repo, 'queries': ''})
                entry['queries'] = ' | '.join(filter(None, [entry['queries'], query]))

            # The API returns at most 1,000 results per query (10 pages of 100)
            if len(repos) < 100 or page == 10:
                break
            page += 1

        warning = '  (over 1,000: split this query)' if total > 1000 else ''
        print(f'{total:>6} results  {query}{warning}')

    df = pd.DataFrame(list(found.values())).sort_values('created_at')
    df.to_csv(output_path, index=False)
    print(f'{len(df)} unique repositories written to {output_path}')


if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-q', '--queries_path', type=str, required=True)
    parser.add_argument('-o', '--output_path', type=str, default='repositories.csv')

    args = parser.parse_args()
    main(args.queries_path, args.output_path)
    