//st, lazy propagation
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int mod = 998244353;
const int LEAF = 1 << 18;
int x[200000], y[200000];
int s[200000];
int cl[200000], cr[200000];
ll st[LEAF + LEAF], lazy[LEAF + LEAF];
void propagate(int ix) {
	st[ix] = (st[ix] + lazy[ix]) % mod;
	if (ix < LEAF) {
		lazy[ix+ix] = (lazy[ix+ix] + lazy[ix]) % mod;
		lazy[ix + ix+1] = (lazy[ix + ix+1] + lazy[ix]) % mod;
	}
	lazy[ix] = 0;
}
void upd(int ix, int s, int e, int from, int to,int val) {
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		lazy[ix] = (lazy[ix] + val) % mod;
		propagate(ix);
	}
	else {
		int m = (s + e) >> 1;
		upd(ix + ix, s, m, from, to, val);
		upd(ix + ix+1, 1+m, e, from, to, val);
		st[ix] = (st[ix + ix] + st[ix + ix + 1]) % mod;
	}
}
ll push(int ix, int s,int e,int t) {
	propagate(ix);
	if (e < t || t < s) return 0;
	if (s == t && t==e) return st[ix];
	int m = (s + e) >> 1;
	ll res= push(ix + ix, s, m, t) + push(ix + ix + 1, m + 1, e, t);
	st[ix] = (st[ix + ix] + st[ix + ix + 1]) % mod;
	return res;
}
int main() {
	int i, n; 
	vector<int> v;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		scanf("%d%d%d", x + i, y + i, s + i);

		auto it = lower_bound(v.begin(), v.end(), y[i]);
		cl[i] = i; cr[i] = i - 1;
		if (it != v.end()) 
			cl[i] = it - v.begin();
		
		v.push_back(x[i]);
		if (s[i]) upd(1, 0, LEAF - 1, i, i, 1);
	}
	ll ans = (x[n-1] + 1)%mod;
	//printf("!!%I64d\n", ans);
	for (i = n - 1; i >= 0; --i) {
		ll call = push(1, 0, LEAF - 1, i);
		//printf("%d,%lld\n",i,call);
		if (call > 0) {
			if (cl[i] <= cr[i])
				upd(1, 0, LEAF - 1, cl[i], cr[i], call);
			ll dist = (x[i] - y[i]) * call%mod;
			//printf("~%d,%lld\n", i, dist);
			ans = (ans + dist) % mod;
		}
	}
	printf("%I64d",ans);
	
	

	return 0;
}