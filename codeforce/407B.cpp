//category : dp

#include <stdio.h>
#define MOD 1000000007
long long p[1002];
long long d[1002];
int n;
void warp(int ix){
	if (d[ix] < 0) d[ix] += MOD;
	if (d[ix] >= MOD) d[ix] %= MOD;
	if (ix > n) return;
	if (d[p[ix]] < 0){
		d[p[ix]] = d[ix] + 1;
		warp(p[ix]);
	}
	else{
		d[ix + 1] = d[ix] + (d[ix] - d[p[ix]]) + 2;
		warp(ix + 1);
	}
}
int main(){
	int i;
	
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%I64d", p + i);
		d[i] = -1;
	}
	d[i] = -1;
	d[1] = 0;
	warp(1);
	printf("%I64d",d[n+1]);
	return 0;
}