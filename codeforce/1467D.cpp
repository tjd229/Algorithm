//dp
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int a[5001];
ll d[5002][5002];
ll scale[5002][5002];
ll step[5001];
int main() {
	int t;
 
	int i, n, k, q;
	for (scanf("%d%d%d", &n, &k, &q), i = 1; i <= n; ++i) scanf("%d", a + i), d[i][0] = 1;
	for (int mv = 1; mv <= k; ++mv) {
		for (i = 1; i <= n; ++i)
			d[i][mv] = (d[i - 1][mv - 1] + d[i + 1][mv - 1]) % mod;
	}
	for (i = 1; i <= n; ++i) scale[i][k] = 1;
	for (int mv = k - 1; mv >= 0; --mv) {
		for (i = 1; i <= n; ++i) {
			scale[i][mv] = (scale[i + 1][mv + 1] + scale[i - 1][mv + 1]) % mod;
		}
	}
	for (i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			step[i] += d[i][j] * scale[i][j] % mod;
			step[i] %= mod;
		}
	}
	//for (i = 1; i <= n; ++i) printf("%lld ",step[i]);
	//puts("");
	ll val = 0;
	for (i = 1; i <= n; ++i) val = (val + step[i] * a[i]) % mod;
	while (q--) {
		int x; scanf("%d%d", &i, &x);
		val -= step[i] * a[i]%mod;
		a[i] = x;
		val += step[i] * a[i]%mod;
		while (val < 0) val += mod;
		val %= mod;
		printf("%I64d\n", val);
	}
 
	return 0;
}