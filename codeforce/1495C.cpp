//graph
#include <stdio.h>
char garden[501][501];
int n, m;
void rm(int l1,int l2) {
	for (int i = 1; i <= m; ++i) {
		if (garden[l1][i - 1] != 'X' &&garden[l2][i - 1] != 'X'
			&&garden[l1][i + 1] != 'X' &&garden[l2][i + 1] != 'X') {
			garden[l1][i] = garden[l2][i] = 'X';
			return;
		}
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i)
			for (j = 1; j <= m; ++j) scanf(" %c",garden[i]+j);
		if (n == 1 || m == 1) {
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= m; ++j) printf("X"),garden[i][j]=0;
				puts("");
			}
		}
		else {
			for (i = 1; i <= n; i += 3)
				for (j = 1; j <= m; ++j) garden[i][j] = 'X';
			for (i = 4; i <= n; i += 3) rm(i - 2, i - 1);
			if (n % 3 == 0) {
				for (j = 1; j <= m; ++j) {
					if (garden[n][j] == 'X')
						garden[n-1][j] = 'X';
				}
			}
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= m; ++j) printf("%c", garden[i][j]), garden[i][j] = 0;
				puts("");
			}
		}
		
	}
 
	return 0;
}