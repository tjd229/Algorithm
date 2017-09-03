//category : st


#include <stdio.h>
#define LEAF (1<<20)
long long st[LEAF + LEAF];
void update(int ix, int diff){
	st[ix] += diff;
	if (ix != 1) update(ix / 2, diff);
}
long long rangeSum(int ix, int s, int e, int from, int to){
	if (from > e || to < s) return 0;
	if (from <= s&&to >= e) return st[ix];
	return rangeSum(ix + ix, s, (s + e) / 2, from, to) + rangeSum(ix + ix + 1, (s + e) / 2 + 1, e, from, to);
}
int main(){
	int N, M, K;
	int i;
	long long a, b, c;
	scanf("%d%d%d",&N,&M,&K);
	M += K;
	for (i = 0; i < N; i++) scanf("%d", &K), update(LEAF + i, K);
	do{
		scanf("%lld%lld%lld",&a,&b,&c);
		if (a == 1) update(LEAF + b - 1, c - st[LEAF + b - 1]);
		else if (a == 2) printf("%lld\n",rangeSum(1,0,LEAF-1,b-1,c-1));
	} while (--M);


	return 0;
}