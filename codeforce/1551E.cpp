//dp
#include <stdio.h>
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
int d[2001][2001];//pos, mv
int a[2001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, k;
		int ans = -1;
		for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
		for (i = 1; i <= n; ++i) {
			d[i][0] = d[i - 1][0] + (a[i] == i);
			if (k <= d[i][0]) 
				ans = min(ans, 0);
			
			for (int j = 1; j < i; ++j) {
				d[i][j] = d[i - 1][j]+(a[i]==i-j);
				d[i][j] = max(d[i][j], d[i - 1][j - 1]);
				if (k <= d[i][j]) ans = min(ans, j);
			}
		}
		printf("%d\n",ans);
	}
 
	return 0;
}