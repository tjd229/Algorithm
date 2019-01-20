//implementation

#include <stdio.h>
int board[10][10];
int lay_x[20], lay_y[20];
int N;
int max(int a, int b) { return a < b ? b : a; }
int dfs(int i,int j) {
	if (i >= N) {
		++j;
		i = (i & 1) ^ 1;
	}
	if (j >= N) return 0;
	int res = 0;
	if (board[i][j] && !lay_x[j - i + N] && !lay_y[j + i]) {
		lay_x[j - i + N] =lay_y[j + i] = 1;
		res=1+dfs(i+2, j);
		lay_x[j - i + N] = lay_y[j + i] = 0;
	}
	return max(res,dfs(i+2, j));
}
int main() {
	int i, j;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) scanf("%d",board[i]+j);
	}
	printf("%d",dfs(0,0)+dfs(1,0));

	return 0;
}
