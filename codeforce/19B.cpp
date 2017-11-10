//category : dp, knapsack

#include <stdio.h>
#define ll long long
const int BND = 4000;
int t[2001];
int c[2001];
ll table[2001][BND+1];
ll min(ll a, ll b){ 
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? a : b; 
}
int main(){
	int i, j, k;
	int n;
	ll ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d%d",t+i,c+i);
		t[i]++;
	}
	k = 0;
	for (i = 1; i <= n; i++){
		j = min(k + t[i], BND);
		k = j;
		for (; j > 0; j--){
			table[i][j] = table[i - 1][j];
			if (j - t[i] >= 0){
				table[i][j] = min(table[i][j], table[i - 1][j - t[i]] + c[i]);
			}
			else table[i][j] = min(table[i][j], table[i][j + 1]);
			if (j >= n) ans = min(ans, table[i][j]);
		}
		k = min(k, n);
		//printf("%d\n",k);
		
	}
	printf("%I64d",ans);
	return 0;
}
