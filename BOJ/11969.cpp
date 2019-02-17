//implementation
#include <stdio.h>
int s[4][100001];
int main() {
	int i, j, N, Q;
	for (scanf("%d%d", &N, &Q), i = 1; i <= N; ++i) {
		int id;
		scanf("%d",&id);
		++s[id][i];
		for (j = 1; j < 4; ++j) s[j][i] += s[j][i - 1];
	}
	while (Q--) {
		int a, b;
		scanf("%d%d",&a,&b);
		for (i = 1; i < 4; ++i) printf("%d ",s[i][b]-s[i][a-1]);
		puts("");
	}
	return 0;
}