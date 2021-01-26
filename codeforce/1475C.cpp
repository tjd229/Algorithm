//greedy
#include <stdio.h>
int A[200001], B[200001];
int cnta[200001], cntb[200001];
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int i, a, b, k; scanf("%d%d%d",&a,&b,&k);
		for (i = 1; i <= k; ++i) scanf("%d", A + i);
		for (i = 1; i <= k; ++i) scanf("%d",B+i);
		for (i = 1; i <= a; ++i) cnta[i] = 0;
		for (i = 1; i <= b; ++i) cntb[i] = 0;
		long long ans = 0;
		for (i = 1; i <= k; ++i) {
			ans += i - 1 - cnta[A[i]] - cntb[B[i]];
			++cnta[A[i]]; ++cntb[B[i]];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}