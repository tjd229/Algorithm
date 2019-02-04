//graph
#include <stdio.h>
int hexa[102][102];
int vis[102][102];
int W, H;
int ans;
const int dx[2][6] = { {-1,0,-1,1,-1,0},{0,1,-1,1,0,1} };
const int dy[6] = { -1,-1,0,0,1,1 };
void dfs(int x,int y) {
	vis[y][x] = 1;
	int odd = y & 1;
	//printf("%d,%d\n",x,y);
	for (int i = 0; i < 6; ++i) {
		int nx = x + dx[odd][i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>W+1 || ny>H+1) continue;
		ans += hexa[ny][nx];
		if (vis[ny][nx] + hexa[ny][nx] == 0) dfs(nx, ny);
	}

}
int main() {
	int i, j;
	for (scanf("%d%d", &W, &H), i = 1; i <= H; ++i) {
		for (j = 1; j <= W; ++j) scanf("%d",hexa[i]+j);
	}
	dfs(0, 0);
	printf("%d",ans);
	return 0;
}
