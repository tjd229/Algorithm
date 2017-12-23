//category : dp

#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int W, H;
ll cnt[201][201];
ll d[6][201];
int main(){
	int i, j,k;
	scanf("%d%d",&H,&W);
	for (i = 1; i <= W; i++) cnt[i][0] = 1;
	for (i = 1; i <= W; i++){
		for (j = 1; j <= W; j++){
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1];
			if (cnt[i][j] >= mod) cnt[i][j] %= mod;
		}
	}
	d[0][1] = 1;
	for (i = 0; i < H; i++){
		for (j = 1; j <= W; j++){
			for (k = 1; k <= W; k++){
				d[i + 1][k] += (d[i][j]*cnt[j][k])%mod;
				if (d[i + 1][k] >= mod) d[i + 1][k] %= mod;
			}
		}
	}
	ll ans = 0;
	for (i = 1; i <= W; i++){
		ans += d[H][i];
		if (ans >= mod) ans %= mod;
	}
	printf("%lld\n",ans);
	return 0;
}
