//dp
#include <stdio.h>
 
int b[200001];
int d[200001][4];
int min(int a, int b) { return a < b ?  a : b; }
int conv(int n) {
	for (int i = 1; i <= n; ++i) for (int j = 0; j < 4; ++j) d[i][j] = 1e9;
	int init = b[1] + b[1]+b[2];
	d[2][init] = 0;
	for (int i = 3; i <= n; ++i) {
		d[i][0] = (b[i] != 0) + d[i - 1][2];
		d[i][1] = (b[i] != 1) + min(d[i - 1][0], d[i - 1][2]);
		d[i][2] = (b[i] != 0) + min(d[i - 1][1], d[i - 1][3]);
		d[i][3] = (b[i] != 1) + d[i - 1][1];
	}
	if (init == 0) return min(d[n][1], d[n][3]);
	else if (init == 3) return min(d[n][0], d[n][2]);
	int mn = min(d[n][1], d[n][2]);
	if (init == 1) mn = min(mn, d[n][3]);
	else mn = min(mn, d[n][0]);
	return mn;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			char s; scanf(" %c", &s);
			b[i] = s == 'R';
		}
		int ans = conv(n);
		b[1] = 1 - b[1];
		ans = min(ans, conv(n) + 1);
		b[2] = 1 - b[2];
		ans = min(ans, conv(n) + 2);
		b[1] = 1 - b[1];
		ans = min(ans, conv(n) + 1);
		
		printf("%d\n",ans);
		
	}
 
	return 0;
}