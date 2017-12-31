//category : math
//ref : http://codeforces.com/contest/894/submission/32484547
#include <stdio.h>
#define ull unsigned long long
const int mod = 1e9 + 7;
ull pow(ull base,ull e){
	ull res = 1;
	ull r = base;
	while (e != 0){
		if (e & 1){
			res *= r;
			if (res >= mod) res %= mod;
		}
		e >>= 1;
		r *= r;
		if (r >= mod) r %= mod;
	}
	return res;
}
int main(){
	ull n, m;
	int k;
	ull ans;
	scanf("%I64u%I64u%d",&n,&m,&k);
	if (k < 0 && ((n & 1) ^ (m & 1)))
	{
		printf("0");
		return 0;
	}
	ans = pow(2, n - 1);
	ans = pow(ans,m - 1);
	printf("%I64u", ans);


	return 0;
}
