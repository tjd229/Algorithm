//category : ft

#include <stdio.h>
#define BI (1<<17)
long long ft1[BI + 1], ft2[BI + 1];
void update(long long *ft, int ix, long long diff){
	while (ix <= BI){
		ft[ix] += diff;
		ix += (ix&-ix);
	}
}
long long sum(long long * ft, int ix){
	long long s = 0;
	while (ix != 0){
		s += ft[ix];
		ix -= (ix&-ix);
	}
	return s;
}
int main(){
	int n;
	int buff;
	long long ans = 0;
	long long t;
	for (scanf("%d", &n); n--;){
		scanf("%d", &buff);
		update(ft1, buff, 1);
		t = ft1[BI]-sum(ft1, buff);
		update(ft2, buff, t);
		t=ft2[BI] - sum(ft2, buff);
		ans += t;
	}
	printf("%lld",ans);
		
	
	return 0;
}


