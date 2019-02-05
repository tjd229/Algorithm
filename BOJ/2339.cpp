//d&c
#include <stdio.h>
int dust[21][21];
int gem[21][21];
int st[21][21];
int N;
int sum(int sx,int sy,int ex,int ey,int s[21][21]) {
	return s[ey][ex] - s[ey][sx - 1] - s[sy - 1][ex] + s[sy - 1][sx - 1];
}
int cut(int sx,int sy,int ex,int ey,int dir) {//-,|
	if (sum(sx, sy, ex, ey, dust) == 0)
		return sum(sx, sy, ex, ey, gem) == 1;
	int res = 0;
	if (dir) {//|
		for (int i = sx+1; i < ex; ++i) {
			if (sum(i, sy, i, ey, gem) == 0 && sum(i, sy, i, ey, dust)) {
				res += cut(sx, sy, i - 1, ey,1-dir)*cut(i + 1, sy, ex, ey,1-dir);
			}
		}
	}
	else {
		for (int i = sy + 1; i < ey; ++i) {
			if (sum(sx, i, ex, i, gem) == 0 && sum(sx, i, ex, i, dust)) {
				res += cut(sx,sy,ex,i-1,1-dir)*cut(sx,i+1,ex,ey,1-dir);
			}
		}
	}
	return res;
}
int main() {
	int i, j;
	int ans = 0;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			scanf("%d",st[i]+j);
			dust[i][j] = dust[i - 1][j] + dust[i][j - 1] - dust[i - 1][j - 1];
			gem[i][j] = gem[i - 1][j] + gem[i][j - 1] - gem[i - 1][j - 1];
			if (st[i][j] == 1) ++dust[i][j];
			else if (st[i][j] == 2) ++gem[i][j];
		}
	}
	ans = cut(1, 1, N, N, 0);
	if(gem[N][N]!=1)
		ans +=cut(1,1,N,N,1);
	printf("%d",ans? ans:-1);
	return 0;
}