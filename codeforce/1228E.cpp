//dp, math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll d[251][251];
ll nck[251][251];
ll pk[251];
ll pk1[251];
int main() {
	int i, j,n, k; scanf("%d%d",&n,&k);
	if (k==1) {
		printf("1");
		return 0;
	}
	
	for (i = 1, pk1[0]=pk[0] = 1; i <= n; ++i) {
		pk[i] = pk[i-1] * k%mod;
		pk1[i] = pk1[i-1] * (k-1)%mod;
	}
	nck[0][0]=nck[1][0]=nck[1][1] = 1;
	for (i = 2; i <= n; ++i) {
		nck[i][0] = 1;
		for (j = 1; j <= i; ++j) nck[i][j] = (nck[i - 1][j] + nck[i-1][j - 1]) % mod;
	}
	for (i = 1; i <= n; ++i) {
		d[1][i] = nck[n][i] * pk1[n-i]%mod;
		//printf("%lld\n",d[1][i]);
	}
	for (i = 1; i < n; ++i) {
		for (int src = 1; src <= n; ++src) {//src is num of 1
			for (int dst = src; dst <= n; ++dst) {//dst
				int dist = dst- src;
				ll s = 1;
				if (dist) {
					s = nck[n - src][dist] * pk1[(n - src) - dist] % mod;
					s = s * pk[src] % mod;
				}
				else {
					s = pk[src] - pk1[src];
					while (s < 0) s += mod;
					s = s * pk1[n - src] % mod;
				}
				
				//printf("%d->%d:%lld\n",src,dst,s);
				//printf("(%d)C(%d)*(k-1)^(%d)*k^%d = %lld * %lld *%lld\n",
					//n-src,dist,n-src-dist,src, nck[n-src][dist], pk1[n-src-dist],pk[src]);
				/*if (dist == 0)
					s -= pk1[n];
				while (s < 0) s += mod;*/
				d[i + 1][dst] += d[i][src] * s%mod;
				d[i + 1][dst] %= mod;
			}
		}
	}
	printf("%I64d",d[n][n]);
	
	return 0;
}