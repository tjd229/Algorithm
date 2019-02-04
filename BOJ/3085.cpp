//implementation

#include <stdio.h>
char grid[51][51];
int N;
int count_row(int y) {
	int cnt = 1;
	int mx = 0;
	for (int j = 1; j <= N; ++j) {
		if (grid[y][j] == grid[y][j - 1]) ++cnt;
		else {
			if (mx < cnt) mx = cnt;
			cnt = 1;
		}
	}
	return mx;
}
int count_col(int x) {
	int cnt = 1;
	int mx = 0;
	for (int i = 1; i <= N; ++i) {
		if (grid[i][x] == grid[i-1][x]) ++cnt;
		else {
			if (mx < cnt) mx = cnt;
			cnt = 1;
		}
	}
	return mx;
}
int main() {
	int i, j;
	int mx = 0;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) scanf(" %c",grid[i]+j);
	}
	for (i = 0; i < N; ++i) {
		int cnt = count_row(i);
		if (mx < cnt) mx = cnt;
		cnt = count_col(i);
		if (mx < cnt) mx = cnt;
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (j + 1 < N) {
				grid[i][j] ^= grid[i][j + 1] ^= grid[i][j] ^= grid[i][j + 1];
				int cnt = count_row(i);
				if (mx < cnt) mx = cnt;
				cnt = count_col(j);
				if (mx < cnt) mx = cnt;
				cnt = count_col(j+1);
				if (mx < cnt) mx = cnt;
				grid[i][j] ^= grid[i][j + 1] ^= grid[i][j] ^= grid[i][j + 1];
			}
			if (i + 1 < N) {
				grid[i][j] ^= grid[i+1][j] ^= grid[i][j] ^= grid[i+1][j];
				int cnt = count_row(i);
				if (mx < cnt) mx = cnt;
				cnt = count_col(j);
				if (mx < cnt) mx = cnt;
				cnt = count_row(i+ 1);
				if (mx < cnt) mx = cnt;
				grid[i][j] ^= grid[i + 1][j] ^= grid[i][j] ^= grid[i + 1][j];
			}
		}
	}
	printf("%d",mx);
	return 0;
}
