//math
#include <stdio.h>
int a[10001];
int p[10001];
int ask(int t, int i, int j, int x) {
	printf("? %d %d %d %d\n", t, i, j, x); fflush(stdout);
	int ans; scanf("%d",&ans);
	return ans;
}
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, n; 
		for (scanf("%d", &n), i = 1; i <= n; ++i) a[i] = 0;
		for (i = 1; i + 1 <= n; i += 2) {
			int peak = ask(1, i, i + 1, n - 1);
			int pi = -1, pj = -1;
			if (peak == n - 1) {
				peak = ask(1, i + 1, i, n - 1);
				if (peak == n) pi = n;
			}

			if (pi == -1 && pj == -1) {
				int x = ask(1, i, i + 1, peak - 1);
				if (x == peak - 1) pi = peak;
				else pj = peak; //x==peak
			}

			if (pi == peak)
				pj = ask(2, i + 1, i, 1);
			else
				pi = ask(2, i, i + 1, 1);
			p[i] = pi; p[i + 1] = pj;
			a[pi] = a[pj] = 1;			
		}
		if (n & 1) {
			for (p[n] = 0, i = 1; i <= n && p[n] == 0; ++i) {
				if (a[i] == 0) p[n] = i;
			}
		}
		for (printf("!"), i = 1; i <= n; ++i)
			printf(" %d",p[i]);
		printf("\n"); fflush(stdout);
		


	}

	return 0;
}