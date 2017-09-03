//category : dp


#include <stdio.h>
int c[101];
int p[101][101];
long long d[101][101][101];
bool visit[101][101][101];
int m;
long long min(long long a, long long b){
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b; 
}
long long color(int n, int k, int last){
	if (k == 0) return -1;
	if (c[n] != 0 && c[n] != last) return -1;
	if (n == 1){
		if (k != 1) return -1;
		if (c[n] == 0) return p[n][last];
		return 0;
	}
	if(visit[n][k][last]) return d[n][k][last];
	visit[n][k][last] = true;
	d[n][k][last] = -1;
	for (int i = 1; i <= m;i++)
		d[n][k][last] = min(d[n][k][last], color(n - 1, k-(i!=last), i));
	if (d[n][k][last] != -1&&c[n]==0) d[n][k][last] += p[n][last];
	return d[n][k][last];

}
int main(){
	int i,j;
	int n, k;
	long long ans = -1;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 1; i <= n; i++) scanf("%d",c+i);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d",&p[i][j]);
		}
	}
	for (i = 1; i <= m; i++){
		ans = min(ans, color(n, k, i));
	}
	printf("%I64d",ans);
	return 0;
}