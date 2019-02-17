//implementation
#include <stdio.h>
int s[100001];
int main() {
	int i, N,M;
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d",s+i);
		s[i] += s[i - 1];
	}
	for (scanf("%d", &M); M--;) {
		int j;
		scanf("%d%d",&i,&j);
		printf("%d\n",s[j]-s[i-1]);
	}
	return 0;
}