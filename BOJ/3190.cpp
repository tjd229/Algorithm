//graph
#include <stdio.h>
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
int board[101][101];
int hist[101][101];
int X[101];
char C[101];
int main() {
	int N,K,L;
	int i;
	for (scanf("%d%d", &N, &K); K--;) {
		int x, y;
		scanf("%d%d",&y,&x);
		board[y][x] = 1;
	}
	int turn = 0;
	int hx, hy;
	int tx, ty;
	int dir = 0;
	int evt = 0;
	hx = hy = tx = ty = 1;
	board[1][1] = -1;
	for (scanf("%d", &L), i = 0; i < L; ++i) 
		scanf(" %d %c",X+i,C+i);
	while (1) {
		++turn;
		int x = hx + dx[dir];
		int y = hy + dy[dir];
		hist[hy][hx] = dir;
		if (x == 0 || y == 0 || x > N || y > N) break;
		if (board[y][x] == 0) {
			int d = hist[ty][tx];
			board[ty][tx] = 0;
			tx += dx[d];
			ty += dy[d];
		}
		if (board[y][x] == -1) break;
		board[y][x] = -1;
		hx = x; hy = y;
		if (turn == X[evt]) {
			if (C[evt] == 'L') dir = (dir + 1) % 4;
			else if (--dir < 0) dir = 3;
			++evt;
		}

	}
	printf("%d",turn);
	return 0;
}
