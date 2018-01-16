//category : dp, math

#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll facto[401];
ll inv[401];
ll d[6][201];
ll pow(ll n,int e){
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
	ll de = inv[k]*inv[n-k]%mod;
	return nu*de%mod;
}
int main(){
	int i, j,k;
	int H, W;
	ll ans = 0;
	inv[0]=facto[0] = 1;
	scanf("%d%d", &H, &W);
	if (H == 0) return printf("1");
	for (i = 1,j=W+W; i <= j; i++){
		facto[i] = facto[i - 1] * i%mod;
		inv[i] = pow(facto[i], mod - 2);
	}
	d[0][1] = 1;
	for (i = 1; i <= H; i++){
		for (j = 1; j <= W; j++){
			for (k = 1; k <= W; k++){
				d[i][k] += d[i - 1][j] * nCk(j+k-1,k)%mod;
				if (d[i][k] >= mod) d[i][k] -= mod;
			}
		}
	}
	for (i = 1; i <= W; i++){
		ans += d[H][i];
		if (ans >= mod) ans -= mod;
	}printf("%lld",ans);
	return 0;
}
