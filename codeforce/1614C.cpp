//math, st
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int mod=1e9 + 7;
const int LEAF = 1 << 18;
const int mask = (1 << 30) - 1;
int st[LEAF + LEAF];
int l[200001], r[200001], x[200001],a[200001];
ll f[200001], invf[200001];
ll nck(int n,int k) {
	ll div = invf[n - k] * invf[k] % mod;
	return div * f[n] % mod;
}
ll _pow(ll x, int e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		x = x * x%mod;
		e >>= 1;
	}
	return res;
}
void upd(int ix, int val) {
	st[ix] = val; ix >>= 1;
	while (ix > 0) {
		st[ix] = st[ix + ix] & st[ix + ix + 1];
		ix >>= 1;
	}
}
 
int main() {
	int t;
	f[0] = invf[0] = 1;
	for (int i = 1; i <= 200000; ++i) f[i] = f[i - 1] * i%mod;
	invf[200000] = _pow(f[200000]);
	for (int i = 199999; i > 0; --i) invf[i] = invf[i + 1] * (i+1)%mod;
	for (int i = 0; i < LEAF + LEAF; ++i) st[i] = mask;
	
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		vector<pii > evt;
		for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
			scanf("%d%d%d",l+i,r+i,x+i);
			evt.push_back({ l[i],i });
			evt.push_back({ r[i]+1,-i });
		}
		sort(evt.begin(), evt.end());
		reverse(evt.begin(), evt.end());
 
		for (i = 1; i <= n; ++i) {
			while (evt.size() && evt.back().first == i) {
				int seg = evt.back().second; evt.pop_back();
				if (seg > 0) {
					upd(LEAF + seg, x[seg]);
				}
				else {
					seg = -seg;
					upd(LEAF + seg, mask);
				}
			}
			a[i] = st[1];
		}
		while (evt.size()) {
			int seg = evt.back().second; evt.pop_back();
			seg = -seg; upd(LEAF + seg, mask);
		}
 
		ll ans = 0;
		for (ll base = 1; base <= mask; base+=base) {
			ll r = 1;
			int N = 0;
			for (i = 1; i <= n; ++i) {
				if (a[i] & base) ++N;
				else r = (r + r) % mod;
			}
			ll one = 0;
			for (i = 1; i <= N; i += 2) {
				one += nck(N, i); one %= mod;
			}
			ll cnt = one * r%mod;
			ans += cnt * base%mod;
			ans %= mod;
		}
		printf("%I64d\n",ans);
 
	}
 
	return 0;
}
