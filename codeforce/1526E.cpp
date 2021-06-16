//math
#include <stdio.h>
#define ll long long
const int mod = 998244353;
int rank[200002],s[200002];
ll f[400001], invf[400001];
ll _pow(ll x, int e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		e >>= 1;
		x = x * x%mod;
	}
	return res;
}
ll nck(int n, int k) {
	ll div = invf[k] * invf[n - k] % mod;
	return f[n] * div%mod;
}
int main() {
	int i, n, k;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) {
		scanf("%d", s + i);
		rank[s[i]]=i;
	}
	ll ans = 0;
	int mn = 1;
	for (i = 1; i < n; ++i) {
		if (rank[s[i] + 1] > rank[s[i+1] + 1]) ++mn;
	}
	f[0] = invf[0] = 1;
	for (i = 1; i <= n+k; ++i) {
		f[i] = f[i - 1] * i%mod;
		invf[i] = _pow(f[i]);
	}
	
	for (i = mn; i <= k; ++i) {
		int _n = i - mn;
		int _k = n;
		//printf("%d:%d,%d\n",i,_n,_k);
		ans = (ans + nck(_n + _k - 1, _k - 1)) % mod;
	}
	printf("%I64d",ans);


	return 0;
}
