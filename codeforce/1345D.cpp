//implementation
#include <stdio.h>
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int n, m;
int grid[1002][1002];
int p[1002][1002];
bool vis[1002][1002];
bool dfs(int x,int y) {
	if (x == 0 || y == 0 || x > m || y > n) return 0;
	if (grid[y][x] == 0) return 0;
	if (vis[y][x]) return 0;
	vis[y][x]=1;
	for (int d = 0; d < 4; ++d)
		dfs(x + dx[d], y + dy[d]);
	return 1;
}
 
bool chk() {
	bool flag = 1;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		int last = -1;
		for (int j = 1; j <= m; ++j) {
			if (last == 0 && sum > 0 && grid[i][j]) flag = 0;
			sum += grid[i][j];
			last = grid[i][j];
		}
		if (sum == 0) {
			for (int j = 1; j <= m; ++j) ++p[i][j];
		}
	}
	
	for (int j = 1; j <= m; ++j) {
		int sum = 0;
		int last = -1;
		for (int i = 1; i <= n; ++i) {
			if (last == 0 && sum > 0 && grid[i][j]) flag = 0;
			sum += grid[i][j];
			last = grid[i][j];
		}
		if (sum == 0) {
			for (int i = 1; i <= n; ++i) ++p[i][j];
		}
	}
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			printf("%d",p[i][j]);
		puts("");
	}*/
	for (int i = 1; i <= n; ++i) {
		int cnt[3] = { 0 };
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 1) cnt[1] = -1e9;
			++cnt[p[i][j]];
		}
		if (cnt[1] > 0 && cnt[2] == 0) flag = 0;
	}
	for (int j = 1; j <= m; ++j) {
		int cnt[3] = { 0 };
		for (int i = 1; i <= n; ++i) {
			if (grid[i][j] == 1) cnt[1] = -1e9;
			++cnt[p[i][j]];
		}
		if (cnt[1] > 0 && cnt[2] == 0) flag = 0;
	}
	return flag;
}
int main() {
	int i, j;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			char c; scanf(" %c",&c);
			if (c == '#') grid[i][j] = 1;
		}
	}
	//fill();
	if (!chk())
		printf("-1");
	else {
		int ans = 0;
		for (i = 1; i <= n; ++i) for (j = 1; j <= m; ++j) ans += dfs(j, i);
		printf("%d",ans);
	}
 
	return 0;
}