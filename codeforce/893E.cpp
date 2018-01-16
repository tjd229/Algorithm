//category : math
//reference : http://codeforces.com/contest/893/submission/32619382
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;

ll facto[(int)2e6+1];
ll pow2[(int)1e6 + 1];
int divisor[(int)1e6 + 1];
int filter[(int)1e6 + 1];
ll pow(ll n, int e){
	ll res = 1;
	while (e != 0){
		if (e & 1){
			res = res*n%mod;
		}
		n = n*n%mod;
		e >>= 1;
	}
	return res;
}
ll nCk(int n,int k){
	ll nu = facto[n];
	ll de = pow(facto[k], mod - 2)*pow(facto[n - k], mod - 2) % mod;
	return nu*de%mod;
}
ll cnt_arr(int x,int y){
	int e,d;
	ll res = 1;
	while (x != 1){
		e = 0;
		d = divisor[x];
		while (x%d == 0){
			e++;
			x /= d;
		}
		res = res*nCk(e+y-1,e)%mod;
	}
	return res*pow2[y-1]%mod;
}
int main(){
	int i, j;
	int q;
	int x, y;
	for (i = 1, facto[0] = 1; i <= 2e6; i++)
		facto[i] = facto[i - 1] * i%mod;
	
	for (i = 1, pow2[0] = 1; i <= 1e6; i++,divisor[i]=i)
		pow2[i] = (pow2[i - 1] << 1)%mod;
	
	for (i = 2; i*i <= 1e6; i++){
		if (filter[i]) continue;
		for (j = i*i; j <= 1e6; j += i){
			if (!filter[j]){
				filter[j] = 1;
				divisor[j] = i;
			}
		}
	}
	for (scanf("%d", &q); q--;){
		scanf("%d%d",&x,&y);
		printf("%I64d\n",cnt_arr(x,y));
	}


	return 0;
}
