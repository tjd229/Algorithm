//dp
#include <stdio.h>
#define ll long long
ll f[90],d[90][2];
int N;
ll p(int n,int b) {
	ll &ref = d[n][b];
	if (n == N) {
		ref = 1;
	}
	else if (ref == 0) {
		ref += p(n + 1, 0);
		if (!b) ref += p(n + 1, 1);
	}
	return ref;
}
int main() {
	ll K; scanf("%lld",&K);
	f[1] = f[2] = 1;
	for (int i = 3; i < 90; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	for (N = 1;K>f[N]; ++N) {
		K -= f[N];
	}
	//printf("%d,%lld", N,p(1, 1));
	p(1, 1);
	printf("1");
	for (int i = 2; i <= N; ++i) {
		if (K <= d[i][0]) printf("0");
		else {
			K -= d[i][0];
			printf("1");
		}
	}
	return 0;
}