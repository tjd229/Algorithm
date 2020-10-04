//dp, strings
#include <stdio.h>
#include <memory.h>
char s[201], t[2];
int d[202][202][202];
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
	int i, n, k;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf(" %c",s+i);
	scanf("%s",t);
	if (t[0] == t[1]) {
		int cnt = k;
		for (i = 1; i <= n; ++i) cnt += s[i] == t[0];
		if (cnt > n) cnt = n;
		printf("%d",(cnt*(cnt-1))>>1);
	}
	else {
		int ans = 0;
		memset(d, -1,sizeof(d));
		d[0][0][0] = 0;
		
		for (i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int l = 0; l <= k; ++l) {
					if (d[i][j][l] < 0) continue;
					int eq0 = s[i+1] == t[0];
					int eq1 = s[i+1] == t[1];
					d[i + 1][j+eq0][l] = max(d[i + 1][j+eq0][l], d[i][j][l] + eq1*j);
					d[i + 1][j + 1][l + 1] = max(d[i + 1][j + 1][l + 1], d[i][j][l]); //to t[0]
					d[i + 1][j][l + 1] = max(d[i + 1][j][l + 1], d[i][j][l] + j); //to t[1]
					ans = max(ans, d[i][j][l]);
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}