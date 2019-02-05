//d&c
#include <stdio.h>
int N;
bool star[2187+1][2187+1];
void dandc(int x,int y,int lev) {
	if (lev == 1) {
		star[y][x] = 1;
		return;
	}
	int nxt = lev / 3;
	dandc(x, y, nxt);
	dandc(x+nxt, y, nxt);
	dandc(x + nxt+nxt, y, nxt);
	dandc(x, y+nxt, nxt);
	dandc(x + nxt + nxt, y + nxt, nxt);
	dandc(x, y + nxt + nxt, nxt);
	dandc(x + nxt, y + nxt + nxt, nxt);
	dandc(x + nxt + nxt, y + nxt + nxt, nxt);
}
int main() {
	scanf("%d",&N);
	dandc(1, 1, N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			printf("%c",star[i][j]? '*':' ');
		puts("");
	}
	return 0;
}