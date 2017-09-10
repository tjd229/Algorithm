//category : dp
#include <stdio.h>
long long d[501][501];
int a[501];
int main(){
	int i, j, k;
	int n, m, b, mod;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for (i = 1; i <= n; i++)
		scanf("%d",a+i);
	d[0][0] = 1;
	for (i = 1; i <= n; i++){
		for (j = 0; j < m; j++){
			for (k = 0; k <= b; k++){
				if (k + a[i]>b) break;
				d[j + 1][k + a[i]] += d[j][k];
				if (d[j + 1][k + a[i]] >= mod)
					d[j + 1][k + a[i]] -= mod;
			}
		}
	}
	long long ans = 0;
	for (i = 0; i <= b; i++){
		ans += d[m][i];
		if (ans >= mod) ans -= mod;
	}
	printf("%I64d",ans);
	return 0;
}