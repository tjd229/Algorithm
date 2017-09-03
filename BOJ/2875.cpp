//category : greedy



#include <stdio.h>
int min(int a, int b){ return a < b ? a : b; }
int main(){
	int N, M, K;
	int ans = 0;
	scanf("%d%d%d",&N,&M,&K);
	ans = min(N>>1,M);
	int r = M - ans + N - (ans << 1);
	K -= r;
	K = -min(-K, 0);
	ans -= (K / 3 + (K % 3 != 0));

	printf("%d",ans);

	return 0;
}