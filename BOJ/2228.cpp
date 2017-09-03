//category : dp



#include <stdio.h>
#define MINVAL -4000000
int a[101];
int s[101];
int d[101][51];
int c[101][51];
int max(int a, int b){ return a<b ? b : a; }
int split(int n,int m){
	if (m == 0) return 0;
	if (n<=0) return MINVAL;
	if (c[n][m] == 1) return d[n][m];
	int k;
	d[n][m] = split(n - 1, m);
	for (k = 0; k <= n; k++)
		d[n][m] = max(d[n][m], split(k - 2, m - 1) + s[n] - s[k - 1]);
	c[n][m] = 1;
	return d[n][m];
}
int main(){
	int N, M;
	int i, j, k;
	scanf("%d%d", &N, &M);

	for (i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	
	printf("%d", split(N,M));


	return 0;
}