//dp, st
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
const int LEAF = 1 << 13;
int a[5001];
ll d[5002][5001];
ll scale[5002][5001];
ll step[5001];
ll st[LEAF + LEAF];
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = (st[ix + ix] + st[ix + ix + 1]) % mod;
		ix >>= 1;
	}
}
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
	for (i = 1; i <= n; ++i) upd(i + LEAF, a[i] * step[i] % mod);
	while (q--) {
		int x; scanf("%d%d", &i, &x);
		a[i] = x;
		upd(i + LEAF, a[i] * step[i] % mod);
 
		printf("%I64d\n", st[1]);
	}
 
	return 0;
}