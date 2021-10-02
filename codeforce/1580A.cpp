//line sweeping
#include <stdio.h>
int A[401][401];
int s[401][401];
int range[401];
int range_sum(int sx, int sy, int ex, int ey) {
	return s[ex][ey] - s[ex][sy - 1] - s[sx - 1][ey] + s[sx-1][sy-1];
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) scanf("%1d", A[i] + j);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j)
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + A[i][j];
			
		}
		int ans = -1;
		for (int st = 1; st + 4 <= n; ++st) {
			for (int ed = st + 4; ed <= n; ++ed) {
				int l = (ed - st - 1) - range_sum(st+1,1,ed-1,1);
				for (i = 4; i <= m; ++i) {
					int r = (ed - st - 1) - range_sum(st + 1, i, ed - 1, i);
					int up = i - 2 - range_sum(st, 2, st, i-1);
					int dn = i - 2 - range_sum(ed, 2, ed, i-1);
					int area = range_sum(st+1,2,ed-1,i-1);
					range[i] = area + up + dn + r;
				}
				for (i = m - 1; i >= 4; --i) {
					if (range[i] > range[i + 1])
						range[i] = range[i + 1];
				}
				for (i = 1; i + 3 <= m; ++i) {
					if (i > 1) {
						l = (ed - st - 1) - range_sum(st + 1, i, ed - 1, i);
						l -= (i - 1) - range_sum(st, 2, st, i);
						l -= (i - 1) - range_sum(ed, 2, ed, i);
						l -= range_sum(st + 1, 2, ed - 1, i);
					}
					int cost = l + range[i + 3];
					if (ans<0 || ans>cost) ans = cost;
				}
			}
		}
		printf("%d\n",ans);

	}

	return 0;
}