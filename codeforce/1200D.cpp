//implementation
#include <stdio.h>
char cell[2001][2001];
int row[4005][4005];
int col[4005][4005];
int main() {
	int i, j, n, k;
	int s, e;
	int ans = 0;
	int mx = 0;
	for (scanf("%d%d",&n, &k), i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) scanf(" %c",cell[i]+j);
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n && cell[i][j] == 'W'; ++j);
		s = j;
		for (j = n; j > 0 && cell[i][j] == 'W'; --j);
		e = j;
		if (s >e)++ans;
		else if (e - s + 1<=k) {
			++row[i][e];
			--row[i][s + k];
			--row[i + k][e];
			++row[i + k][s + k];
		}
	}
	for (j = 1; j <= n; ++j) {
		for (i = 1; i <= n && cell[i][j] == 'W'; ++i);
		s = i;
		for (i = n; i > 0 && cell[i][j] == 'W'; --i);
		e = i;
		if (s > e) ++ans;
		else if (e - s + 1 <= k) {
			++col[e][j];
			--col[s+k][j];
			--col[e][j + k];
			++col[s+k][j+k];
		}
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			row[i][j] += row[i - 1][j] + row[i][j - 1] - row[i - 1][j - 1];
			col[i][j] += col[i - 1][j] + col[i][j - 1] - col[i - 1][j - 1];
			//printf("%d ",col[i][j]);
		}//puts("");
	}
	for (i = k; i <= n; ++i) {
		for (j = k; j <= n; ++j) {
			if (mx < row[i][j] + col[i][j]) mx = row[i][j] + col[i][j];
		}
	}
	printf("%d",ans+mx);
	return 0;
}