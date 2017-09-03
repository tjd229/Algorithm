//category : ft

#include <stdio.h>
#define BI (1<<18)
long long dist[BI + 1];
long long cnt[BI + 1];
void update(long long *ft, int ix, long long diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(long long *ft, int ix){
	long long s = 0;
	while (ix != 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int N;
	int buff;
	long long cost;
	long long ans = 1;
	scanf("%d", &N);
	scanf("%d", &buff);
	buff++;
	update(cnt, buff, 1);
	update(dist, buff, buff);
	while (--N){
		scanf("%d", &buff);
		buff++;
		
		cost = sum(cnt, buff - 1)*buff - sum(dist, buff - 1);
		cost += sum(dist, BI) - sum(dist, buff) - buff*(sum(cnt, BI) - sum(cnt, buff));
		cost %= 1000000007LL;
		ans *= cost;
		ans %= 1000000007LL;
		update(cnt, buff, 1);
		update(dist, buff, buff);
	}
	printf("%lld", ans);
	return 0;
}
