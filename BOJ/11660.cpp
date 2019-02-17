//implementation
#include <stdio.h>
#define ll long long
ll s[1025][1025];
int main() {
	int i, j;
	int N, M;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			scanf("%lld",s[i]+j);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	while (M--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		printf("%lld\n",s[y2][x2]-s[y2][x1-1]-s[y1-1][x2]+s[y1-1][x1-1]);
	}
	return 0;
}