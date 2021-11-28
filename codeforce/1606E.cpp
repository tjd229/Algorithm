//dp, math
#include <stdio.h>
#define ll long long
const int mod=998244353;
ll nck[501][501];
ll d[501][501],p[501][501];
int main() {
	int i, n, x; scanf("%d%d",&n,&x);
	nck[0][0]  = 1;
	for (i = 1; i<=x ||i <= n; ++i) {
		nck[i][0] = 1;
		for (int j = 1; j <=i; ++j)
			nck[i][j] = (nck[i - 1][j - 1] + nck[i - 1][j]) % mod;
		p[i][0] = 1;
		for (int j = 1; j <= n; ++j) p[i][j] = p[i][j - 1] * i%mod;
	}
	d[n][0] = 1;
	for (i = n; i > 1; --i) {
		int dmg = i - 1;
		for (int j = 0; j < x; ++j) {
			int cum = dmg + j;
			int hp = dmg;
			if (cum > x) {
				hp -= cum - x;//-delta
				cum = x;
			}
			for (int k = 0; k <= i; ++k) {
				ll coef= nck[i][k] * p[hp][k] % mod;
				
				d[i - k][cum] += coef * d[i][j]%mod;
				d[i - k][cum] %= mod;
			}
		}
	}
	ll ans = 0;
	for (i = 1; i <= x; ++i) ans = (ans + d[0][i]) % mod;
	printf("%I64d\n",ans);
	return 0;
}