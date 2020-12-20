//dp
#include <stdio.h>
#include <memory.h>
int d[101][101][10001];
int a[101], b[101];
int main() {
	int i, n;
	int tot_a=0, tot_b = 0;
	for (scanf("%d",&n), i = 1; i <= n; ++i) {
		scanf("%d%d", a + i, b + i);
		tot_a += a[i];
		tot_b += b[i];
	}
	memset(d, -1, sizeof(d));
	
	for (i = 1; i <= n; ++i) {
		d[i - 1][0][0] = 0;
		for (int k = 1; k <= n; ++k) {
			for (int j = 0; j <= tot_a; ++j) {
				d[i][k][j] = d[i - 1][k][j];
				if (j - a[i] >= 0 && d[i - 1][k - 1][j - a[i]] != -1
					&& d[i - 1][k - 1][j - a[i]] + b[i] > d[i][k][j])
					d[i][k][j] = d[i - 1][k - 1][j - a[i]] + b[i];					
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		double ans = 0;
		for (int j = 0; j <= tot_a; ++j) {
			if (d[n][k][j] < 0) continue;
			double water =(d[n][k][j]+tot_b)/2.0;
			if (water > j) water = j;
			if (ans < water) ans = water;
		}
		printf("%.9lf ",ans);
	}
 
	return 0;
}