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
	int bestScore = -1;
	vector<pair<int, vector<int>>> bestSol;

	vector<int> av(C, 0);
	vector<int> order(P);
	vector<bool> chosen(C, false);
	mt19937 mt(42);
	int skw = 100000;
	int lw = 1;
	int avw = 1;
	int rmode = 0;
	int slack = 0;
	const auto ckey = [&](int c, int m, int s, int l) { return make_tuple(max(av[c], m), skill[c][s]-l, ts[c]-skw*skill[c][s]); };
	vector<pair<int,int>> levlog;
	const unsigned seeds[] = {42u, 123456789u, 777u, 2022u, 9999u, 31337u, 555u, 2718281u, 11u, 22u, 33u, 44u, 55u, 66u, 77u, 88u, 101u, 202u, 303u, 404u, 505u, 606u, 707u, 808u, 909u, 1234u, 5678u, 4321u, 8765u, 246u, 135u, 999u};
	const int skws[] = {100000, 100000, 50000, 200000, 100000, 30000, 100000, 100000, 80000, 150000, 60000, 100000, 40000, 120000, 90000, 100000, 70000, 110000, 45000, 130000, 95000, 35000, -50000, 0, 100000, 75000, 125000, 55000, 175000, 100000, 65000, 100000};
	(void)skws;
	int sortmode = 0;
	for(int restart = 0; restart < 32; ++restart) {
	mt.seed(seeds[restart]);
	skw = skws[restart];
	sortmode = restart % 4;
	lw = (restart % 4 == 3) ? 3 : (restart % 7 == 6 ? 2 : 1);
	avw = (restart % 10 == 9) ? 3 : (restart % 5 == 4) ? 2 : 1;
	rmode = (restart % 6 == 5) ? 1 : 0;
	slack = (restart % 8 == 7) ? 30 : 0;
	if(restart == 0) skw = 100000, sortmode = 0, lw = 1;
	score = 0;
	sol.clear();
	fill(av.begin(), av.end(), 0);
	iota(order.begin(), order.end(), 0);
	while(true) {
		bool bad = true;
		vector<int> fail;
		sort(order.begin(), order.end(), [&](int a, int b) {
			long long ka = rmode ? (long long)S[a]*D[b] : (long long)S[a]*D[b]*req[b].size();
			long long kb = rmode ? (long long)S[b]*D[a] : (long long)S[b]*D[a]*req[a].size();
			if(sortmode == 1 && B[a] != B[b]) return B[a] < B[b];
			if(sortmode == 2 && S[a] != S[b]) return S[a] > S[b];
			if(sortmode == 3 && D[a] != D[b]) return D[a] < D[b];
			if(ka != kb) return ka > kb;
			if(B[a] != B[b]) return B[a] < B[b];
			if(req[a].size() != req[b].size()) return req[a].size() < req[b].size();
			if(S[a] != S[b]) return S[a] > S[b];
			if(D[a] != D[b]) return D[a] < D[b];
			return a < b;
		});
		for(int p : order) {
			int beste = -1, besto = -1;
			vector<int> cs(req[p].size(), 0), cs2, ro=cs;
			iota(ro.begin(), ro.end(), 0);
			array<int, NS> ms;
			vector<int> psk;
			for(auto &pr : req[p]) psk.push_back(pr.first);
			sort(psk.begin(), psk.end());
			psk.erase(unique(psk.begin(), psk.end()), psk.end());
			const int TT = 66 + (restart % 3) * 4;
			for(int test = 0; test < TT; ++test) {
				if(test == TT-1) sort(ro.begin(), ro.end(), [&](int a, int b) { return req[p][a].second > req[p][b].second; });
				else shuffle(ro.begin(), ro.end(), mt);
				for(int i : psk) ms[i] = 0;
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
					if(skill[best][s] <= l0) oo += lw;
					for(int i : psk) ms[i] = max(ms[i], skill[best][i]);
					chosen[best] = true;
					mav = max(mav, av[best]);
				}
				for(int c : cs) chosen[c] = false;
				int end = mav+D[p];
				if(nr || end >= B[p]+S[p]+slack) continue;
				for(int i = 1; i < cs.size(); ++i) if(skill[cs[i]][req[p][i].first] > req[p][i].second)
					for(int j = 0; j < i; ++j) if(skill[cs[j]][req[p][j].first] > req[p][j].second)
						if(skill[cs[i]][req[p][j].first] >= req[p][j].second-1 && skill[cs[j]][req[p][i].first] >= req[p][i].second-1) {
							swap(cs[i], cs[j]);
							oo += 2;
						}
				oo += (1000000-mav)*avw;
				if(oo > besto) {
					besto = oo;
					beste = end;
					cs2 = cs;
				}
			}
			int end = beste;
			if(cs2.empty() || end >= B[p]+S[p]+slack) {
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
					levlog.emplace_back(cs[i], s);
				}
			}
			sol.emplace_back(p, cs);
			bad = false;
		}
		if(bad) break;
		order = fail;
	}
	if(score > bestScore) {
		bestScore = score;
		bestSol = sol;
	}
	for(auto &cs : levlog) { --skill[cs.first][cs.second]; --ts[cs.first]; }
	levlog.clear();
	}
	score = bestScore;
	sol = bestSol;

	cerr << score << endl;
	cout << sol.size() << endl;
	for(const auto &[p, cs] : sol) {
		cout << Pnames[p] << '\n';
		for(int c : cs) cout << Cnames[c] << ' ';
		cout << '\n';
	}

	return 0;
}
