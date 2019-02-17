//graph
#include <stdio.h>
const int dx[4] = {-1,1,0,0};
const int dy[4] = { 0,0,1,-1 };
int d1[1000][1000],d2[1000][1000];
int R, C;
int vis[1000][1000];
char lyb[1000][1000];
void dfs(int x,int y,int stamp, int d[1000][1000]) {
	vis[y][x] = stamp;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
		if (vis[ny][nx] == stamp) continue;
		if (lyb[ny][nx] == '#') continue;
		d[ny][nx] = d[y][x] + 1;
		dfs(nx, ny, stamp, d);
	}
}
int main() {
	int i, j,T;
	for (scanf("%d", &T); T--;) {
		int sx, sy;
		for (scanf("%d%d", &C, &R), i = 0; i < R; ++i) {
			for (j = 0; j < C; ++j) {
				scanf(" %c",lyb[i]+j);
				if (lyb[i][j] == '.') sx = j, sy = i;
				d1[i][j] = d2[i][j] = 0;
			}
		}
		dfs(sx, sy, T + 1, d1);
		int X = 0;
		for (i = 0; i < R; ++i) {
			for (j = 0; j < C; ++j) {
				if (X < d1[i][j]) X = d1[i][j],sx=j,sy=i;
			}
		}
		dfs(sx, sy, -T - 1, d2);
		for (i = 0, X =0; i < R; ++i) {
			for (j = 0; j < C; ++j) {
				if (X < d2[i][j]) X = d2[i][j];
			}
		}
		printf("Maximum rope length is %d.\n",X);
	}
	return 0;
}