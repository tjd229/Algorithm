//math
#include <stdio.h>
int sieve[1299709+1];
int pre[1299709 + 1], nxt[1299709 + 1];
int main() {
	int i, T,k;
	for (i = 2; i <= 1299709; ++i) {
		if (sieve[i]) continue;
		pre[i] = nxt[i] = i;
		for (long long j = (long long)i * i; j <= 1299709; j += i) sieve[j] = 1;
	}
	for (i = 1299709; i > 1; --i) 
		if (nxt[i] == 0) nxt[i] = nxt[i + 1];
	for (i = 2; i <= 1299709; ++i) {
		if (pre[i] == 0) pre[i] = pre[i - 1];
		sieve[i] += sieve[i - 1];
	}
	for (scanf("%d", &T); T--;) {
		scanf("%d",&k);
		int ans = sieve[nxt[k]] - sieve[pre[k]];
		if (ans) ++ans;
		printf("%d\n",ans);
	}
	
	return 0;
}