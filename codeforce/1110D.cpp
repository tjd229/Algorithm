//dp
#include <stdio.h>
#include <memory.h>
int cnt[1000001];
int d[1000002][3][3];
int max(int a, int b) {  return a < b ? b : a; }
int main() {
	int i, j, k,l;
	int n, m;
	for (scanf("%d%d", &n, &m), i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	memset(d, -1, sizeof(d));
	d[0][0][0] = 0;
	for (i = 0; i <= m; ++i) {
		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				if (d[i][j][k] < 0) continue;
				int r = cnt[i + 1] - j - k;
				for (l = 0; l < 3; ++l) {
					if (l > r) break;
					d[i + 1][k][l] = max(d[i + 1][k][l], d[i][j][k] + l + (r-l) / 3);
				}
			}
		}
	}
	printf("%d",d[m+1][0][0]);
	return 0;
}
