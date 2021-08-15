//math, dp
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll f[3000010], invf[3000010];
ll d[3000010][3];
int _pow(ll x, int e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		e >>=1;
		x = x * x%mod;
	}
	return res;
}
ll nck(int n, int k) {
	if (invf[k] < 0) invf[k] = _pow(f[k]);
	if (invf[n-k] < 0) invf[n-k] = _pow(f[n-k]);
	ll div = invf[k] * invf[n - k]%mod;
	return f[n] * div%mod;
}
int main() {
	int i, n, q; scanf("%d%d",&n,&q);
	int nnn = n + n + n;
	f[0] = invf[0] = 1;
	f[1] = invf[1] = 1;
	d[0][0] = d[0][1] = d[0][2] = n;
	for (i = 2; i <= nnn ; ++i) 
		f[i] = f[i - 1] * i%mod;
	invf[nnn] = _pow(f[nnn]);
	for (i = nnn - 1; i > 1; --i) 
		invf[i] = invf[i + 1] * (i + 1) % mod;
	
	ll inv3 = _pow(3);
	for (i = 1; i <= nnn; ++i) {
		ll h = nck(nnn, 1 + i);
		d[i][0]= h-d[i-1][1]-d[i-1][0]-d[i-1][0];
		while (d[i][0] < 0) d[i][0] += mod;
		d[i][0] = d[i][0] * inv3%mod;
		d[i][1] = (d[i][0] + d[i - 1][0]) % mod;
		d[i][2] = (d[i][1] + d[i - 1][1]) % mod;
	}
	while (q--) {
		int x; scanf("%d",&x);
		printf("%I64d\n", (d[x][0]+nck(nnn,x))%mod);
	}


	return 0;
}