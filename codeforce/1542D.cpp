//dp, math
#include <stdio.h>
#define ll long long
const int mod = 998244353;
int n,A[501];
ll sim(int pos) {
	int x = A[pos];
	ll d[501][502] = { 0 };
	d[0][0] = 1;
	for (int i = 1; i < pos; ++i) {
		if (A[i] == mod) {
			for (int j = 0; j <= n; ++j)
				d[i][j] = (d[i - 1][j] + d[i - 1][j + 1]) % mod;
			d[i][0] = (d[i][0] + d[i - 1][0]) % mod;
		}
		else if (A[i] <= x) {
			for (int j = 1; j <= n; ++j)
				d[i][j] = (d[i-1][j - 1] + d[i-1][j]) % mod;
			d[i][0] = d[i - 1][0];
		}
		else {
			for (int j = 0; j <= n; ++j) d[i][j] = (d[i - 1][j]+d[i-1][j])%mod;
		}
	}
	for (int j = 0; j <= n; ++j) d[pos][j] = d[pos - 1][j];
	for (int i = pos + 1; i <= n; ++i) {
		if (A[i] == mod) {
			for (int j = 0; j <= n; ++j)
				d[i][j] = (d[i - 1][j] + d[i - 1][j + 1]) % mod;
		}
		else if (A[i] < x) {
			for (int j = 1; j <= n; ++j)
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % mod;
			d[i][0] = d[i - 1][0];
		}
		else {
			for (int j = 0; j <= n; ++j) d[i][j] = (d[i - 1][j] + d[i - 1][j]) % mod;
		}
	}
	ll cnt = 0;
	for (int j = 0; j <= n; ++j) cnt = (cnt + d[n][j]) % mod;
	return cnt * x%mod;
}
int main() {
	int i;
	ll ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		char cmd; scanf(" %c",&cmd);
		if (cmd == '-') A[i] = mod;
		else scanf("%d",A+i);
	}
	for (i = 1; i <= n; ++i) {
		if (A[i] < mod)
			ans = (ans + sim(i) )% mod;
	}
	printf("%I64d",ans);
 
	return 0;
}