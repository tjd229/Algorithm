//string, dp
#include <stdio.h>
char s[5001];
int lcp[5001][5001];
int d[5001];
int main() {
	int i, n, t;
	for (scanf("%d", &t); t--;) {
		scanf("%d %s",&n,s);
 
		lcp[n][n] = 0;
		for (i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j >= i; --j) {
				if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
				else lcp[i][j] = 0;
			}
		}
		int ans = n; d[0] = n;
		for (i = 1; i < n; ++i) {
			d[i] = n - i;
			for (int j = 0; j < i; ++j) {
				int common = lcp[j][i];
				if (s[j + common] < s[i + common]) {
					int upd = d[j]+n-i-common;
					if (d[i] < upd) d[i] = upd;
				}
			}
			if (ans < d[i]) ans = d[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}