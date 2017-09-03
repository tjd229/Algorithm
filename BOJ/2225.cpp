//category : dp

#include <stdio.h>

long long d[201][201];

long long term(int n, int k){
	if (k == 1) return 1;
	if (n == 0) return 1;
	if (d[n][k]) return d[n][k];
	int i;
	long long ans = 0;
	for (i = 0; i <= n; i++) ans += term(i, k - 1), ans %= 1000000000;
	d[n][k] = ans;
	return ans;
}
int main(){
	int N, K;
	int i;
	scanf("%d%d",&N,&K);
	printf("%lld",term(N,K));

	return 0;
}

