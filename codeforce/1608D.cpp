//math
#include <stdio.h>
#define ll long long
const int mod = 998244353;
ll f[200001];
ll invf[200001];
char dom[100001][2];
ll _pow(ll x, int e=mod-2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		x = x * x%mod;
		e >>= 1;
	}
	return res;
}
ll nck(int n, int k) {
	ll div = invf[n - k] * invf[k]%mod;
	return div * f[n] % mod;
}
int main() {
	int i, n;
	int cnt[2] = { 0 };
	int un=0;
	int con = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%s", dom + i);
		if (dom[i][0] == '?' && dom[i][1] == '?') ++un;
		if (dom[i][0] == 'B' && dom[i][1] == 'B') con=1;
		if (dom[i][0] == 'W' && dom[i][1] == 'W') con = 1;
		if (dom[i][0] == 'B') ++cnt[0];
		if (dom[i][1] == 'B') ++cnt[0];
		if (dom[i][0] == 'W') ++cnt[1];
		if (dom[i][1] == 'W') ++cnt[1];
	}
	if (cnt[0] > n || cnt[1] > n) {
		printf("0");
		return 0;
	}
	int nn = n + n;
	f[1] = f[0] = 1; invf[1] = invf[0] = 1;
	for (i = 2; i <= nn; ++i) f[i] = f[i - 1] * i%mod;
	invf[nn] = _pow(f[nn]);
	for (i = nn - 1; i > 1; --i) invf[i] = invf[i + 1] * (1 + i)%mod;
 
	ll ans = nck(nn - cnt[0] - cnt[1], n - cnt[0]);
	if (con == 0) {
		ll inv = _pow(2, un);
		int ex = 2;
		for (i = 1; i <= n; ++i) {//all WB
			if (dom[i][0] == 'B' || dom[i][1] == 'W') {
				--ex;
				break;
			}
		}
		for (i = 1; i <= n; ++i) {
			if (dom[i][0] == 'W' || dom[i][1] == 'B') {
				--ex;
				break;
			}
		}
		ans -= inv - ex;
		while (ans < 0) ans += mod;
	}
	printf("%I64d",ans);
 
 
	
 
	return 0;
}