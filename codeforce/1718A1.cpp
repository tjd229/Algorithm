//dp
#include <stdio.h>
int a[5001];
int d[5001][9001];
const int inf = 1e9;
int min(int a, int b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
int main() {
	int i, t;
	int mxj = 1 << 13;
	for (scanf("%d", &t); t--;) {
		int n; int j;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			for (j = 0; j <= 9000; ++j) d[i][j] = inf;
		}
		if (n == 1) {
			printf("%d\n",a[1]>0);
			continue;
		}
		d[1][a[1]] = 0;
		for (i = 1; i < n; ++i) {
			if (d[i][0] != inf) {
				int nxt = a[i + 1];
				d[i + 1][nxt] = min(d[i + 1][nxt], d[i][0]);
			}
			for (j = 1; j < mxj; ++j) {
				if (d[i][j] == inf) continue;
				//printf("%d,%d\n",i,j);
				int nxt = a[i + 1];
				d[i + 1][nxt] = min(d[i + 1][nxt], d[i][j]+1);
				nxt = a[i + 1] ^ j;
				d[i + 1][nxt] = min(d[i + 1][nxt], d[i][j] + 1);
			}
		}
		int cost = d[n][0];
		for (j = 1; j <= 9000; ++j) {
			if (d[n][j] == inf) continue;
			cost = min(cost, d[n][j] + 1);
		}
		printf("%d\n",cost);
		
 
	}
 
	return 0;
}