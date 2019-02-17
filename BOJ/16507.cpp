//implementation
#include <stdio.h>
int s[1001][1001];
int main() {
	int R, C, Q;
	int i, j;
	for (scanf("%d%d%d", &R, &C, &Q), i = 1; i <= R; ++i) {
		for (j = 1; j <= C; ++j) {
			scanf("%d",s[i]+j);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	while (Q--) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int deno = (c2 - c1 + 1)*(r2 - r1 + 1);
		int nume = s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1];
		printf("%d\n",nume/deno);
	}
	return 0;
}