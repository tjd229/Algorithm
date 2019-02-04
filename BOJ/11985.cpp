//dp
#include <stdio.h>
#define ll long long
int A[20001];
ll d[20001];
ll min(ll a, ll b) {
	if (a < 0) return b;
	if (b < 0) return a;
	return a > b ? b : a; 
}
int main() {
	int N, M, K;
	int i,j;
	for (scanf("%d%d%d", &N, &M, &K), i = 1; i <= N; ++i) scanf("%d",A+i);
	d[1] = K;
	for (i = 2; i <= N; ++i) {
		int mx = A[i];
		int mn = A[i];
		d[i] = -1;
		for (j = 1; j <= M; ++j) {
			if (i < j) break;
			d[i] = min(d[i], d[i - j] + K + (mx - mn)*(ll)j);
			if (mx < A[i - j]) mx = A[i - j];
			if (mn > A[i - j]) mn = A[i - j];
		}
	}
	printf("%lld",d[N]);

	return 0;
}
