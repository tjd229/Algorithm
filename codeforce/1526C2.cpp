//greedy, st, lazy propagation
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int LEAF = 1 << 18;
const ll inf = 1e18;
ll st[LEAF + LEAF],lazy[LEAF+LEAF];
int a[200001];
void push(int ix) {
	st[ix] += lazy[ix];
	if (ix < LEAF) {
		lazy[ix + ix] += lazy[ix];
		lazy[ix + ix + 1] += lazy[ix];
	}
	lazy[ix] = 0;
}
void upd(int ix,int s,int e,int from,int to,int val) {
	push(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		lazy[ix] += val;
		push(ix);
	}
	else {
		int m = (s + e) >> 1;
		upd(ix + ix, s, m, from, to, val);
		upd(ix + ix + 1, m + 1, e, from, to, val);
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
	}
}
ll mn(int ix, int s, int e, int from, int to) {
	push(ix);
	if (e < from || to < s) return inf;
	if (from <= s && e <= to) 
		return st[ix];
	
	int m = (s + e) >> 1;
	ll l = mn(ix + ix, s, m, from, to);
	ll r = mn(ix + ix+1,1+m,e, from, to);
	return l < r ? l : r;
}
int main() {
	int i, n;
	vector<pii > v;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		v.push_back({a[i],i});
	}
	int ans = 0;
	sort(v.begin(), v.end());
	while (v.size()) {
		int ix, val;  tie(val, ix) = v.back();
		v.pop_back();
		if (mn(1, 0, LEAF - 1, ix, n) + val >= 0) {
			++ans;
			upd(1, 0, LEAF - 1, ix, n, val);
		}
	}
	printf("%d",ans);
}