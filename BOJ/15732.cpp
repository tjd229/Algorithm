//bs
#include <stdio.h>
#define ll long long
int A[10000], B[10000], C[10000];
int N, K, D;
bool sum(int k) {
	ll cnt = 0;
	for (int i = 0; i < K; ++i) {
		if (A[i] <= k) {
			int r = B[i] < k ? B[i] : k;
			cnt += (r - A[i]) / C[i] + 1;
		}
		if (cnt >= D) return 1;
	}
	return 0;
}
int main() {
	int i;
	for (scanf("%d%d%d", &N, &K, &D), i = 0; i < K; ++i) scanf("%d%d%d",A+i,B+i,C+i);
	int l = 1;
	int r = N;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (sum(m)) r=m-1;
		else l=m+1;
	}
	printf("%d",r+1);
	return 0;
}