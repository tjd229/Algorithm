//dp
#include <stdio.h>
#define ll long long 
const int mod = 15746;
ll d[1000001];
int main() {
	int i, N;
	d[0]=d[1] = 1;
	for (scanf("%d", &N), i = 2; i <= N; ++i) 
		d[i] = (d[i - 1] + d[i - 2]) % mod;
	printf("%lld",d[N]);
	return 0;
}