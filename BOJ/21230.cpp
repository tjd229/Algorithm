//dp
#include <stdio.h>
int c[301];
int nxt[301],last[301];
int d[301][301];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	int i,j, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%d",c+i),last[i]=1+N;
	for (i = N; i > 0; --i) {
		nxt[i] = last[c[i]];
		last[c[i]] = i;
	}
	for (i = N; i > 0; --i) {
		d[i][i] = 1;
		for (j = i + 1; j <= N; ++j) {
			d[i][j] = min(d[i + 1][j], d[i][j - 1]) + 1;
			for (int pos = nxt[i]; pos <= j; pos = nxt[pos]) {
				d[i][j] = min(d[i][j], d[i][pos - 1] + d[pos][j] - 1);
			}
		}
	}
	printf("%d",d[1][N]);

	return 0;
}
