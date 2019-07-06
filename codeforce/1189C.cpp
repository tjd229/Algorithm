//math
#include <stdio.h>
int s[100001];
int main() {
	int i, n,q;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",s+i),s[i]+=s[i-1];
	for (scanf("%d", &q); q--;) {
		int l, r; scanf("%d%d",&l,&r);
		printf("%d\n", (s[r] - s[l - 1])/10);
	}
	return 0;
}