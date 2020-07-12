//greedy
#include <stdio.h>
int A[301][301];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n, k;
		for (scanf("%d%d", &n, &k), i = 0; i < n; ++i) 
			for (j = 0; j < n; ++j) A[i][j] = 0;
		int d = 0;
		while (k) {
			for (i = 0; i < n && k; ++i) {
				j = (i + d)%n;
				A[i][j] = 1;
				--k;
			}
			++d;
		}
		int ans = 0;
		int mn=1e9, mx=0;
		for (i = 0; i < n; ++i) {
			int R = 0;
			for (j = 0; j < n; ++j) {
				R += A[i][j];
			}
			if (mn > R) mn = R;
			if (mx < R) mx = R;
		}
		ans += (mx - mn) * (mx - mn);
		mn = 1e9, mx = 0;
		for (j = 0; j < n; ++j) {
			int C = 0;
			for (i = 0; i < n; ++i) C += A[i][j];
			if (mn > C) mn = C;
			if (mx < C) mx = C;
		}
		ans += (mx - mn) * (mx - mn);
		//printf("%d\n",ans);
		for (printf("%d\n", ans), i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) printf("%d",A[i][j]);
			puts("");
		}
	}
	return 0;
}
