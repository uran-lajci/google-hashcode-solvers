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

	vector<int> av(C, 0);
	vector<int> order(P);
	vector<bool> chosen(C, false);
	iota(order.begin(), order.end(), 0);
	mt19937 mt;
	int tsdir = 1;
	const auto ckey = [&](int c, int m, int s, int l) { return make_tuple(max(av[c], m), skill[c][s] - l, av[c], skill[c][s], tsdir*ts[c], tsdir*(ts[c]-skill[c][s]), c); };
	const auto skill0 = skill;
	const auto ts0 = ts;
	int bestScore = -1;
	vector<pair<int, vector<int>>> bestSol;
	for(int bmd : {18*16+3*2, 18*16+1*2, 18*16+5*2, 18*16+7*2, 16*16+3*2, 20*16+3*2, 14*16+3*2, 22*16+3*2, 9*16+3*2, 36*16+7*2, 18*16+3*2+1, 16*16+3*2+1, 20*16+3*2+1, 17*16+3*2, 19*16+3*2, 15*16+3*2, 21*16+3*2, 12*16+3*2, 24*16+3*2, 18*16+2*2, 18*16+4*2, 28*16+5*2, 13*16+3*2, 11*16+3*2, 18*16+6*2, 18*16+0*2, 23*16+3*2, 25*16+3*2, 10*16+3*2, 30*16+5*2, 26*16+4*2, 32*16+6*2, 27*16+3*2, 29*16+3*2, 31*16+3*2, 33*16+3*2, 34*16+5*2, 40*16+7*2, 8*16+3*2, 7*16+3*2, 18*16+3*2+1, 19*16+4*2, 17*16+2*2, 16*16+2*2, 20*16+4*2, 22*16+5*2, 14*16+2*2, 35*16+6*2, 38*16+7*2, 18*16+5*2+1, 16*16+4*2, 20*16+5*2, 19*16+3*2+1, 17*16+4*2, 14*16+3*2+1, 22*16+3*2+1, 24*16+3*2+1, 28*16+5*2+1, 16*16+2*2+1, 20*16+4*2+1}) {
	int bm = bmd / 16, dc = (bmd % 16) / 2 + 1;
	tsdir = (bmd & 1) ? -1 : 1;
	for(int sc : {2, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 24, -1, -2, -3, -4, -5, -6}) {
	skill = skill0; ts = ts0;
	fill(av.begin(), av.end(), 0);
	fill(chosen.begin(), chosen.end(), false);
	score = 0; sol.clear();
	order.resize(P); iota(order.begin(), order.end(), 0);
	bool need_lvl = false;
	while(true) {
		bool bad = true;
		vector<int> fail;
		if(need_lvl) sort(order.begin(), order.end(), [&](int a, int b) { long long ka = (4LL-sc)*S[a]+3*bm*B[a]-2*dc*D[a], kb = (4LL-sc)*S[b]+3*bm*B[b]-2*dc*D[b]; return ka != kb ? ka > kb : ((int)req[a].size() != (int)req[b].size() ? req[a].size() > req[b].size() : (S[a] != S[b] ? S[a] > S[b] : (D[a] != D[b] ? D[a] > D[b] : B[a] < B[b]))); });
		else sort(order.begin(), order.end(), [&](int a, int b) { long long ka = 2*(long long)bm*B[a]-dc*D[a]-sc*S[a], kb = 2*(long long)bm*B[b]-dc*D[b]-sc*S[b]; return ka != kb ? ka < kb : (S[a] != S[b] ? S[a] > S[b] : (S[a]*D[b] != S[b]*D[a] ? S[a]*D[b] > S[b]*D[a] : (req[a].size() != req[b].size() ? req[a].size() > req[b].size() : (D[a] != D[b] ? D[a] > D[b] : B[a] > B[b])))); });
		for(int p : order) {
			int mav = 0;
			int R = req[p].size();
			vector<int> cs(R, -1);
			vector<int> ord(R);
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int a, int b) { return req[p][a].second != req[p][b].second ? req[p][a].second > req[p][b].second : (tsdir > 0 ? a < b : a > b); });
			array<int, 800> ms; ms.fill(0);
			bool ok = true;
			for(int ri : ord) {
				auto [s, l] = req[p][ri];
				if(ms[s] >= l) --l;
				int best = -1;
				for(int c = 0; c < C; ++c) if(!chosen[c] && skill[c][s] >= l)
					if(best == -1 || ckey(c, mav, s, l) < ckey(best, mav, s, l))
						best = c;
				if(best == -1) { ok = false; break; }
				cs[ri] = best;
				for(int i = 0; i < s2i.size(); ++i) ms[i] = max(ms[i], skill[best][i]);
				chosen[best] = true;
				mav = max(mav, av[best]);
			}
			for(int c : cs) if(c != -1) chosen[c] = false;
			int end = mav+D[p];
			if(!ok || (!need_lvl && end >= B[p]+S[p])) {
				fail.push_back(p);
				continue;
			}
			for(bool sw = true; sw; ) {
				sw = false;
				for(int i = 1; i < cs.size(); ++i) if(skill[cs[i]][req[p][i].first] > req[p][i].second)
					for(int j = 0; j < i; ++j) if(skill[cs[j]][req[p][j].first] > req[p][j].second)
						if(skill[cs[i]][req[p][j].first] >= req[p][j].second-1 && skill[cs[j]][req[p][i].first] >= req[p][i].second-1)
							{ swap(cs[i], cs[j]); sw = true; }
			}
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
			if(need_lvl) break;
			need_lvl = true;
		}
		order = fail;
	}
	if(score > bestScore) { bestScore = score; bestSol = sol; }
	}
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