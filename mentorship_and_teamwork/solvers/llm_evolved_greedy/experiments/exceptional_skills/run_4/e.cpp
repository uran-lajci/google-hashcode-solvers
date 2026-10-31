// Copyright (C) 2026, Coudert--Osmont Yoann
// SPDX-License-Identifier: MIT
// Licensed under the MIT License. See LICENSE file in the project root for full license information.

#include <algorithm>
#include <array>
#include <chrono>
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

	vector<int> av(C, 0);
	vector<int> order(P);
	vector<bool> chosen(C, false);
	mt19937 mt(12345);
	vector<int> cpri(C, 0);
	vector<int> ppri(P, 0);
	int W1 = 1000000, W2 = 20;
	const auto ckey = [&](int c, int m, int s, int l) { return make_tuple(max(av[c], m), W1*(skill[c][s] - l) + W2*ts[c] - skill[c][s] + cpri[c], av[c], skill[c][s]); };
	const auto skill0 = skill;
	const auto ts0 = ts;
	int NS = s2i.size();
	vector<vector<int>> hasSkill0(NS), hasSkill;
	for(int c = 0; c < C; ++c) for(int s = 0; s < NS; ++s) if(skill0[c][s] >= 1) hasSkill0[s].push_back(c);
	hasSkill = hasSkill0;
	int best_score = -1;
	vector<pair<int, vector<int>>> best_sol;
	auto t_start = chrono::steady_clock::now();
	for(int restart = 0; ; ++restart) {
		if(restart > 0) {
			if(chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - t_start).count() >= 570) break;
			skill = skill0;
			ts = ts0;
			hasSkill = hasSkill0;
			fill(av.begin(), av.end(), 0);
			static const int W1s[] = {1000000, 100, 10, 1, 0, 1000000, 1000000, 1000000, 1000000, 50, 5, 200000, 500000, 2000000, 20, 3, 1, 0, 1000000, 7, 1000000, 1000000, 1000000, 1000000, 500};
			static const int W2s[] = {10, 10, 10, 10, 10, 1, 100, 1000, 30, 10, 10, 30, 30, 30, 30, 3, 100, 100, 5, 2, -1, -10, -100, 0, 15};
			if(restart <= 24) {
				W1 = W1s[restart-1]; W2 = W2s[restart-1];
				fill(cpri.begin(), cpri.end(), 0);
				fill(ppri.begin(), ppri.end(), 0);
			} else {
				W1 = 1000000; W2 = 5 + (int)(mt() % 40);
				for(int c = 0; c < C; ++c) cpri[c] = (int)(mt() % 401) - 200;
				fill(ppri.begin(), ppri.end(), 0);
				for(int k = 0; k < P/10+1; ++k) ppri[mt()%P] = (int)(mt() % 21) - 10;
			}
		}
		fill(chosen.begin(), chosen.end(), false);
		score = 0;
		sol.clear();
		iota(order.begin(), order.end(), 0);
	bool need_lvl = false;
	int stale = 0;
	while(true) {
		bool bad = true;
		vector<int> fail;
		if(need_lvl) sort(order.begin(), order.end(), [&](int a, int b) {
			double ra = (double)(S[a]+B[a]) / max(1, (int)req[a].size()*D[a]) + ppri[a]*0.001;
			double rb = (double)(S[b]+B[b]) / max(1, (int)req[b].size()*D[b]) + ppri[b]*0.001;
			if(ra != rb) return ra > rb;
			if(S[a]+B[a]-D[a] != S[b]+B[b]-D[b]) return S[a]+B[a]-D[a] > S[b]+B[b]-D[b];
			if(D[a] != D[b]) return D[a] < D[b];
			if(B[a] != B[b]) return B[a] < B[b];
			return req[a].size() < req[b].size();
		});
		else sort(order.begin(), order.end(), [&](int a, int b) {
			int ka = B[a]-D[a]+ppri[a], kb = B[b]-D[b]+ppri[b];
			if(ka != kb) return ka < kb;
			double ra = (double)(S[a]+B[a]) / max(1, (int)req[a].size()*D[a]);
			double rb = (double)(S[b]+B[b]) / max(1, (int)req[b].size()*D[b]);
			if(ra != rb) return ra > rb;
			if(D[a] != D[b]) return D[a] < D[b];
			if(B[a] != B[b]) return B[a] < B[b];
			if(S[a] != S[b]) return S[a] > S[b];
			return req[a].size() > req[b].size();
		});
		for(int p : order) {
			int mav = 0;
			vector<int> ord(req[p].size());
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int a, int b) { return req[p][a].second > req[p][b].second; });
			vector<int> cs(req[p].size(), -1);
			static array<int,800> ms2;
			vector<int> used;
			for(auto [s, l] : req[p]) { ms2[s] = 0; used.push_back(s); }
			bool ok = true;
			for(int ri : ord) {
				auto [s, l] = req[p][ri];
				if(ms2[s] >= l) --l;
				int best = -1;
				if(l >= 1) {
					for(int c : hasSkill[s]) if(!chosen[c] && skill[c][s] >= l)
						if(best == -1 || ckey(c, mav, s, l) < ckey(best, mav, s, l))
							best = c;
				} else {
					for(int c = 0; c < C; ++c) if(!chosen[c] && skill[c][s] >= l)
						if(best == -1 || ckey(c, mav, s, l) < ckey(best, mav, s, l))
							best = c;
				}
				if(best == -1) { ok = false; break; }
				cs[ri] = best;
				for(int u : used) ms2[u] = max(ms2[u], skill[best][u]);
				chosen[best] = true;
				mav = max(mav, av[best]);
			}
			for(int c : cs) if(c != -1) chosen[c] = false;
			int end = mav+D[p];
			if(!ok || (!need_lvl && end > B[p]+S[p])) {
				fail.push_back(p);
				continue;
			}
			for(bool changed = true; changed; ) {
				changed = false;
				for(int i = 1; i < (int)cs.size(); ++i) if(skill[cs[i]][req[p][i].first] > req[p][i].second)
					for(int j = 0; j < i; ++j) if(skill[cs[j]][req[p][j].first] > req[p][j].second)
						if(skill[cs[i]][req[p][j].first] >= req[p][j].second-1 && skill[cs[j]][req[p][i].first] >= req[p][i].second-1)
							{ swap(cs[i], cs[j]); changed = true; }
			}
			bool impLvl = false;
			for(int i = 0; i < cs.size(); ++i) {
				av[cs[i]] = end;
				auto [s, l] = req[p][i];
				if(skill[cs[i]][s] <= l) {
					++ skill[cs[i]][s];
					++ ts[cs[i]];
					impLvl = true;
					if(skill[cs[i]][s] == 1) hasSkill[s].push_back(cs[i]);
				}
			}
			if(need_lvl && !impLvl && end > B[p]+S[p]) {
				fail.push_back(p);
				continue;
			}
			score += max(0, S[p] - max(0, end-B[p]));
			sol.emplace_back(p, cs);
			bad = false;
		}
		if(bad) {
			if(need_lvl) {
				if(++stale >= 20) break;
				need_lvl = false;
			} else need_lvl = true;
		} else stale = 0;
		order = fail;
	}
		if(score > best_score) {
			best_score = score;
			best_sol = sol;
		}
	}
	score = best_score;
	sol = best_sol;

	cerr << score << endl;
	cout << sol.size() << endl;
	for(const auto &[p, cs] : sol) {
		cout << Pnames[p] << '\n';
		for(int c : cs) cout << Cnames[c] << ' ';
		cout << '\n';
	}

	return 0;
}