//category : ft



#include <stdio.h>
#define BI (1<<20)
long long ft[BI + 1];
void update(int ix,long long diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(int ix){
	long long s = 0;
	while (ix != 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int N, M, K;
	long long a, b, c;
	scanf("%d%d%d",&N,&M,&K);
	M += K;
	int i;
	for (i = 1; i <= N; i++) scanf("%lld",&c),update(i,c);
	do{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) update(b,c-(sum(b)-sum(b-1)));
		else if (a == 2) printf("%lld\n",sum(c)-sum(b-1));
	} while (--M);
	return 0;
}
