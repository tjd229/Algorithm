//math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll p[200001], cumpow[200002];
ll f[200001], invf[200001];
int _pow(ll x, int e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		e >>= 1;
		x = x * x%mod;
	}
	return res;
}
int nck(int n, int k) {
	ll div = invf[n - k] * invf[k] % mod;
	return div * f[n] % mod;
}
int main() {
	int i, t;
	p[0] = 1; f[0] = 1;
	for (i = 1; i <= 200000; ++i) {
		p[i] = p[i - 1] * 2 % mod;
		f[i] = f[i - 1] * i%mod;
	}
	invf[200000] = _pow(f[200000]); invf[0] = 1;
	for (i = 200000 - 1; i > 0; --i) 
		invf[i] = invf[i + 1] * (1 + i) % mod;
	
	for (scanf("%d", &t); t--;) {
		int n, k; scanf("%d%d",&n,&k);
		ll pick_odd = 0,cum=1;
		ll ans = 0;
		for (i = 0; i < n; i += 2)
			pick_odd = (pick_odd + nck(n, i))%mod;
		cumpow[k] = p[n]; cumpow[k+1] = 1;
		for (i = k - 1; i > 0; --i) cumpow[i] = cumpow[i + 1] * p[n]%mod;
		for (i = 1; i <= k; ++i) {
			if ((n & 1) == 0) {
				ans += cum * cumpow[1+i]%mod;
				ans %= mod;
			}
			ll cnt = pick_odd+(n&1);
			cum = cum * cnt%mod;
		}
		printf("%I64d\n",(cum+ans)%mod);
	}
 
	return 0;
}