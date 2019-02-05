//dp, math
#include <stdio.h>
const int mod = 10007;
long long c[1001][1001];
int main() {
	int N, K;
	int i, j;
	c[1][0] = c[1][1] = 1;
	for (scanf("%d%d", &N, &K), i = 2; i <= N; ++i) {
		c[i][0] = 1;
		for (j = 1; j <= K; ++j) 
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		
	}
	printf("%lld",c[N][K]);
	return 0;
}
