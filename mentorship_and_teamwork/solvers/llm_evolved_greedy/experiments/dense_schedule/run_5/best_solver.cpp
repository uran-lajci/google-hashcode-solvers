// Copyright (C) 2026, Coudert--Osmont Yoann
// SPDX-License-Identifier: MIT
// Licensed under the MIT License. See LICENSE file in the project root for full license information.

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;
const int NS = 800;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, P;
	cin >> C >> P;
	vector<string> Cnames(C), Pnames(P);
	unordered_map<string, int> s2i;
	vector<array<int, NS>> skill(C);
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
	cerr << C << ' ' << P << ' ' << s2i.size() << endl;

	int score = 0;
	vector<pair<int, vector<int>>> sol;

	vector<int> av(C, 0);
	vector<int> order(P);
	vector<bool> chosen(C, false);
	mt19937 mt(98765);
	const auto ckey = [&](int c, int m, int s, int l) { return make_tuple(max(av[c], m), skill[c][s] - l, ts[c]); };
	const auto skill0 = skill;
	const auto ts0 = ts;
	vector<pair<int, vector<int>>> bestSol;
	int bestScore = -1;
	for(int seed : {98765, 50000, 271828, 161803, 99991, 314159, 654321, 111111, 202020, 808080, 42424, 5318008, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800}) {
	skill = skill0; ts = ts0;
	fill(av.begin(), av.end(), 0);
	score = 0; sol.clear();
	mt.seed(seed);
	iota(order.begin(), order.end(), 0);
	while(true) {
		bool bad = true;
		vector<int> fail;
		sort(order.begin(), order.end(), [&](int a, int b) {
			long long va = (long long)S[a]*D[b]*req[b].size(), vb = (long long)S[b]*D[a]*req[a].size();
			if(va != vb) return vb < va;
			if(B[a] != B[b]) return B[a] < B[b];
			if(D[a] != D[b]) return D[a] < D[b];
			return S[a] > S[b];
		});
		for(int p : order) {
			int beste = -1, besto = -1;
			vector<int> cs(req[p].size(), 0), cs2, ro=cs;
			iota(ro.begin(), ro.end(), 0);
			array<int, NS> ms;
			for(int test = 0; test < 72; ++test) {
				if(test == 70)
					sort(ro.begin(), ro.end(), [&](int a, int b) { return req[p][a].second > req[p][b].second; });
				else if(test == 71)
					sort(ro.begin(), ro.end(), [&](int a, int b) { return req[p][a].second < req[p][b].second; });
				else
					shuffle(ro.begin(), ro.end(), mt);
				ms.fill(0);
				int mav = 0, oo = 0, nr = req[p].size();
				for(int o : ro) {
					auto [s, l] = req[p][o];
					const int l0 = l;
					if(ms[s] >= l) --l;
					int best = -1;
					for(int c = 0; c < C; ++c) if(!chosen[c] && skill[c][s] >= l)
						if(best == -1 || ckey(c, mav, s, l0) < ckey(best, mav, s, l0))
							best = c;
					if(best == -1) break;
					-- nr;
					cs[o] = best;
					if(skill[best][s] <= l0) ++oo;
					for(int i = 0; i < s2i.size(); ++i) ms[i] = max(ms[i], skill[best][i]);
					chosen[best] = true;
					mav = max(mav, av[best]);
				}
				for(int c : cs) chosen[c] = false;
				int tsum = 0;
				for(int c : cs) tsum += ts[c];
				int end = mav+D[p];
				if(nr || end > B[p]+S[p]) continue;
				int late = max(0, end-B[p]);
				for(int pass = 0; pass < 2; ++pass)
				for(int i = 1; i < cs.size(); ++i) if(skill[cs[i]][req[p][i].first] > req[p][i].second)
					for(int j = 0; j < i; ++j) if(skill[cs[j]][req[p][j].first] > req[p][j].second)
						if(skill[cs[i]][req[p][j].first] >= req[p][j].second-1 && skill[cs[j]][req[p][i].first] >= req[p][i].second-1) {
							swap(cs[i], cs[j]);
							oo += 2;
						}
				oo += 1000000-mav - tsum/100 + 5*(int)cs.size();
				if(oo > besto) {
					besto = oo;
					beste = end;
					cs2 = cs;
				}
			}
			int end = beste;
			if(cs2.empty() || end > B[p]+S[p]) {
				fail.push_back(p);
				continue;
			}
			cs = cs2;
			score += S[p] - max(0, end-B[p]);
			for(int i = 0; i < cs.size(); ++i) {
				av[cs[i]] = end;
				auto [s, l] = req[p][i];
				if(skill[cs[i]][s] <= l) {
					++ skill[cs[i]][s];
					++ ts[cs[i]];
				}
			}
			sol.emplace_back(p, cs);
			bad = false;
		}
		if(bad) break;
		order = fail;
	}
	if(score > bestScore) { bestScore = score; bestSol = sol; }
	}
	score = bestScore; sol = bestSol;

	cerr << score << endl;
	cout << sol.size() << endl;
	for(const auto &[p, cs] : sol) {
		cout << Pnames[p] << '\n';
		for(int c : cs) cout << Cnames[c] << ' ';
		cout << '\n';
	}

	return 0;
}
