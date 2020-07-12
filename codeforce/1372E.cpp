//dp, line sweeping
#include <stdio.h>
int d[101][101];
int s[101][101], e[101][101];
int main() {
	int i, j,k, m, n;
	int l, r;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		for (scanf("%d", &k); k--;) {
			int l, r; 
			for (scanf("%d%d", &l, &r), j = l; j <= r; ++j)
				s[i][j] = l, e[i][j] = r;			
		}
	}
	for (r = 1; r <= m; ++r) {
		for (l = r; l > 0; --l) {
			for (k = r; k >= l; --k) {
				int cnt = 0;
				for (i = 1; i <= n; ++i) {
					cnt += l <= s[i][k] && e[i][k] <= r;
				}
				int nd = cnt * cnt;
				if (l <= k - 1) nd += d[l][k - 1];
				if (k + 1 <= r) nd += d[k + 1][r];
				if (d[l][r] < nd) d[l][r] = nd;
			}
		}
	}
	printf("%d",d[1][m]);
	return 0;
}