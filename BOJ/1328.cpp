//category : dp

#include <stdio.h>
#include <memory.h>

long long d[101][101][101];
long long buildings(int n, int l, int r){
	if (n == 0 || r == 0 || l == 0) return 0;
	if (n < r || n < l||l+r>n+n) return 0;
	if (d[n][l][r]!=-1) return d[n][l][r];

	d[n][l][r] = buildings(n - 1, l, r)*(n - 2) + buildings(n-1, l - 1, r) + buildings(n-1, l, r - 1);
	d[n][l][r] %= 1000000007;
	return d[n][l][r];

}

int main(){
	int N, L, R;
	memset(d, -1, sizeof(d));
	d[1][1][1] = 1;

	scanf("%d%d%d",&N,&L,&R);
	printf("%lld",buildings(N,L,R));
	return 0;
}