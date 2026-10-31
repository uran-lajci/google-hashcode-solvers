// Copyright (C) 2026, Coudert--Osmont Yoann
// SPDX-License-Identifier: MIT
// Licensed under the MIT License. See LICENSE file in the project root for full license information.

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, P;
	cin >> C >> P;
	vector<string> Cnames(C), Pnames(P);
	unordered_map<string, int> s2i;
	vector<array<int, 800>> skill(C);
	vector<int> ts(C, 0);
	vector<vector<pair<int, int>>> req(P);
	vector<int> D(P), S(P), B(P);

	for(int c = 0; c < C; ++c) {
		int n;
		cin >> Cnames[c] >> n;
		skill[c].fill(0);
		while(n--) {
			string s; int l;
			cin >> s >> l;
			if(!s2i.count(s)) s2i[s] = s2i.size();
			skill[c][s2i[s]] = l;
			ts[c] += l;
		}
	}
	for(int p = 0; p < P; ++p) {
		int r;
		cin >> Pnames[p] >> D[p] >> S[p] >> B[p] >> r;
		while(r--) {
			string s; int l;
			cin >> s >> l;
			if(!s2i.count(s)) s2i[s] = s2i.size();
			req[p].emplace_back(s2i[s], l);
		}
	}

	int score = 0;
	vector<pair<int, vector<int>>> sol;

	vector<int> scnt(s2i.size(), 0);
	vector<vector<int>> cskills(C);
	vector<vector<int>> cbyskill(s2i.size());
	for(int c = 0; c < C; ++c) for(int s = 0; s < (int)s2i.size(); ++s) if(skill[c][s] > 0) { ++scnt[s]; cskills[c].push_back(s); cbyskill[s].push_back(c); }
	vector<int> av(C, 0);
	vector<int> order(P);
	vector<bool> chosen(C, false);
	iota(order.begin(), order.end(), 0);
	mt19937 mt;
	const auto ckey = [&](int c, int m, int s) { return make_tuple(max(av[c], m), skill[c][s], 2048*skill[c][s] + ts[c] + 256*av[c], 5*av[c] + ts[c], ts[c] - 2048*skill[c][s], c); };
	bool need_lvl = false;
	while(true) {
		bool bad = true;
		vector<int> fail;
		if(need_lvl) sort(order.begin(), order.end(), [&](int a, int b) { return S[a] != S[b] ? S[a] > S[b] : (B[a]-D[a] != B[b]-D[b] ? B[a]-D[a] < B[b]-D[b] : (req[a].size() != req[b].size() ? req[a].size() > req[b].size() : D[a] < D[b])); });
		else sort(order.begin(), order.end(), [&](int a, int b) { return B[a]-D[a] != B[b]-D[b] ? B[a]-D[a] < B[b]-D[b] : (S[a] != S[b] ? S[a] > S[b] : (req[a].size() != req[b].size() ? req[a].size() < req[b].size() : D[a] < D[b])); });
		for(int p : order) {
			int mav = 0;
			int R = req[p].size();
			vector<int> ord(R);
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int a, int b) { return req[p][a].second != req[p][b].second ? req[p][a].second > req[p][b].second : scnt[req[p][a].first] < scnt[req[p][b].first]; });
			vector<int> csp(R, -1);
			array<int, 800> ms; ms.fill(0);
			int filled = 0;
			for(int oi : ord) {
				int s = req[p][oi].first, l = req[p][oi].second;
				if(ms[s] >= l) --l;
				int best = -1;
				for(int c = 0; c < C; ++c) if(!chosen[c] && skill[c][s] >= l)
					if(best == -1 || ckey(c, mav, s) < ckey(best, mav, s))
						best = c;
				if(best == -1) break;
				csp[oi] = best;
				++filled;
				for(int i : cskills[best]) ms[i] = max(ms[i], skill[best][i]);
				chosen[best] = true;
				mav = max(mav, av[best]);
			}
			vector<int> cs;
			if(filled == R) cs = csp;
			else for(int oi : ord) if(csp[oi] != -1) chosen[csp[oi]] = false;
			for(int c : cs) chosen[c] = false;
			int end = mav+D[p];
			if(cs.size() < req[p].size() || (!need_lvl && end >= B[p]+S[p])) {
				fail.push_back(p);
				continue;
			}
			for(int pass = 0; pass < 16; ++pass)
			for(int i = 1; i < cs.size(); ++i) if(skill[cs[i]][req[p][i].first] > req[p][i].second)
				for(int j = 0; j < i; ++j) if(skill[cs[j]][req[p][j].first] > req[p][j].second)
					if(skill[cs[i]][req[p][j].first] >= req[p][j].second-1 && skill[cs[j]][req[p][i].first] >= req[p][i].second-1)
						swap(cs[i], cs[j]);
			bool impLvl = false;
			for(int i = 0; i < cs.size(); ++i) {
				av[cs[i]] = end;
				auto [s, l] = req[p][i];
				if(skill[cs[i]][s] <= l) {
					++ skill[cs[i]][s];
					++ ts[cs[i]];
					impLvl = true;
				}
			}
			if(need_lvl && !impLvl && end >= B[p]+S[p]) {
				fail.push_back(p);
				continue;
			}
			score += max(0, S[p] - max(0, end-B[p]));
			sol.emplace_back(p, cs);
			bad = false;
		}
		if(bad) {
			if(need_lvl) {
				if(fail.empty()) break;
				need_lvl = false;
				static int stale = 0;
				if(++stale > 11000) break;
			} else need_lvl = true;
		}
		order = fail;
	}

	cerr << score << endl;
	cout << sol.size() << endl;
	for(const auto &[p, cs] : sol) {
		cout << Pnames[p] << '\n';
		for(int c : cs) cout << Cnames[c] << ' ';
		cout << '\n';
	}

	return 0;
}