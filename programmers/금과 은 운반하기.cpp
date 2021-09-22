//https://programmers.co.kr/learn/courses/30/lessons/86053
//graph, bs
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n;
int A, B;
vector<int> gold, silver, weight, tt;
int sim(ll t) {
	ll g = 0, s = 0,d=0;
	for (int i = 0; i < n; ++i) {
		ll mv = t/tt[i];
		ll round = mv >> 1;
		ll oneway = mv & 1;
		ll flow = round + oneway;
		ll tot = flow * weight[i];
		ll dg = 0, ds = 0, dd = 0;
		if (gold[i] >= tot) {
			dg += tot; tot = 0;
		}
		else if (gold[i] < tot) {
			dg += gold[i];
			tot -= gold[i];
		}
		if (silver[i] >= tot) {
			ds += tot; tot = 0;
		}
		else if (silver[i] < tot) {
			ds += silver[i];
		}
		if (silver[i] - ds > 0)
			dd += min(dg, silver[i] - ds);//for replacing
		g += dg; s += ds; d += dd;
	}
	if (g < A) return 0;
	ll bonus = g - A;
	bonus = min(bonus, d); s += bonus;
	if (s < B) return 0;
	return 1;
	
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = -1;
	gold = g; silver = s; weight = w; tt = t;
	A = a; B = b;
	ll l=1, r=0;
	n = g.size();
	for (int i = 0; i < n; ++i) {
		int tot = g[i] + s[i];
		ll round = tot / w[i] +(tot%w[i]>0);
		ll _t = (round - 1)*t[i] * 2 + t[i];
		r = max(r, _t);
	}
	while (l <= r) {
		ll m = (l + r) >> 1;
		if (sim(m)) {
			answer = m;
			r = m - 1;
		}
		else l = 1 + m;
	}

	return answer;
}