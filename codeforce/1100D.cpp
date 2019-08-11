//greedy, game

#include <stdio.h>
const int dx[4] = {-1,-1,1,1};
const int dy[4] = {-1,1,-1,1};
int rx[667], ry[667];
int kx, ky;
int board[1000][1000];
inline int norm(int x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	return 0;
}
int move(int dx,int dy) {
	kx += dx; ky += dy;
	if (board[ky][kx]) {
		if (dx == 0) ky -= dy;
		else kx -= dx;
	}
	printf("%d %d\n", kx, ky); fflush(stdout);
	int k, x, y; scanf("%d%d%d",&k,&x,&y);
	if (k > 0) {
		board[ry[k]][rx[k]] = 0;
		rx[k] = x;
		ry[k] = y;
		board[y][x] = k;
	}
	return k;
}
int main() {
	int i;
	for (scanf("%d%d", &kx, &ky), i = 1; i <= 666; ++i) {
		scanf("%d%d", rx + i, ry + i);
		board[ry[i]][rx[i]] = i;
	}
	int dir = 0;	
	int k = 1000;
	int s[4] = { 0 };
	
	while (k > 0 && (kx != 500 || ky != 500))
		k = move(norm(500-kx),norm(500-ky));
	
	for (i = 1; i <= 666; ++i) {
		int b2 = rx[i] > 500;
		int b1 = ry[i] > 500;
		++s[b2 + b2 + b1];
	}
	int mn = s[0];
	for (i = 1; i < 4; ++i) {
		if (mn > s[i]) {
			mn = s[i];
			dir = i;
		}
	}
	dir ^= 3;
	while (k > 0)
		k=move(dx[dir], dy[dir]);
	
	return 0;
}
