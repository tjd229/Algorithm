//implementation
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

#include <stdio.h>
int M[101][101];
int N;
bool chk_row(int r) {
	int cnt[101] = { 0 };
	int mx = 0;
	for (int j = 1; j <= N; ++j) {
		if (cnt[M[r][j]]++) return 1;
		if (mx < M[r][j]) mx = M[r][j];
	}
	return mx != N;
}
bool chk_col(int c) {
	int cnt[101] = { 0 };
	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		if (cnt[M[i][c]]++) return 1;
		if (mx < M[i][c]) mx = M[i][c];
	}
	return mx != N;
}
int main() {
	int tc, T;
	for (scanf("%d", &T), tc = 1; tc <= T; ++tc) {
		int i, j;
		int k = 0,r=0,c=0;
		for (scanf("%d", &N), i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j) {
				scanf("%d", M[i] + j);
				if (i == j) k += M[i][j];
			}			
		}
		for ( i = 1; i <= N; ++i)
			r += chk_row(i);
		for (i = 1; i <= N; ++i)
			c += chk_col(i);
		printf("Case #%d: %d %d %d\n",tc,k,r,c);
		
	}
	return 0;
}