//https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c0f00
//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
vector<int> P;
int N, K;
int sim(int s, int e) {
	int r = e - s - 1;
	int cnt = r >> 1;
	return 1 + cnt;
}
int sim(pii s1, pii s2) {
	int c1, c2;
	if (s1.first == s1.second && (s1.first<P[0] || s1.first>P.back())) {
		if (s1.first < P[0])
			c1 = s1.first;
		else c1 = K - P.back();
	}
	else {
		c1 = max(sim(s1.first, s1.second + 1), sim(s1.first - 1, s1.second));
	}
	if (s2.first == s2.second && (s2.first<P[0] || s2.first>P.back())) {
		if (s2.first < P[0])
			c2 = s2.first;
		else c2 = K - P.back();
	}
	else {
		c2 = max(sim(s2.first, s2.second + 1), sim(s2.first - 1, s2.second));
	}
	return c1 + c2;
}
bool in(int x) {
	for (auto y : P)
		if (x == y) return 0;
	return 1;
}
int main() {
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d", &N, &K);
		int i; P.clear();
		for (i = 1; i <= N; ++i) {
			int p; scanf("%d", &p);
			P.push_back(p);
		}
		sort(P.begin(), P.end());
		P.resize(unique(P.begin(), P.end()) - P.begin());
		double ans = 0;
		int opt = 0;
		vector<pii > seg;
		if (P[0] > 1) {
			seg.push_back({ P[0] - 1,P[0] - 1 });
			opt = P[0] - 1;
		}
		for (i = 1; i < P.size(); ++i) {
			int l = P[i - 1] + 1, r = P[i] - 1;
			if (l > r) continue;
			seg.push_back({ l,r });
		}
		if (P.back() < K) {
			seg.push_back({ P.back() + 1,P.back() + 1 });
			int cnt = K - P.back();
			if (opt < cnt) opt = cnt;
		}
		for (i = 0; i < seg.size(); ++i) {
			for (int j = i + 1; j < seg.size(); ++j) {
				int cnt = sim(seg[i], seg[j]);
				if (opt < cnt) opt = cnt;
			}
		}
		for (i = 0; i < seg.size(); ++i) {
			if (seg[i].first<P[0] || seg[i].first>P.back())continue;
			int l = seg[i].first, r = seg[i].second;
			int cnt = 0;
			if (l == r) cnt = 1;
			if (l > r);
			if (l < r) {
				cnt = 2;
				int remain = r - l - 1;
				cnt += remain;
			}
			if (opt < cnt) opt = cnt;
		}
		ans = opt / (double)K;


		printf("Case #%d: %.9lf\n", tc, ans);
	}


	return 0;
}