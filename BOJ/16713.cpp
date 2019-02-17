//implementation
#include <stdio.h>
int ex[1000001];
int main() {
	int i, N, Q;
	int ans = 0;
	for (scanf("%d%d", &N,&Q), i = 1; i <= N; ++i) {
		scanf("%d",ex+i);
		ex[i] ^= ex[i - 1];
	}
	while (Q--) {
		int s, e;
		scanf("%d%d",&s,&e);
		ans ^= ex[e] ^ ex[s-1];
	}
	printf("%d",ans);
	return 0;
}