//category : math
#include <stdio.h>
#define ll long long
int N, D, C;
int memo[51];
ll c[51][11];
double e[11][11][11];
bool visit[11][11][11];
ll pt(int n,int k){
	if (n < k) return 0;
	if (c[n][k]) return c[n][k];
	if (n == k || k == 0) c[n][k] = 1;
	else c[n][k] = pt(n - 1, k) + pt(n - 1, k - 1);
	return c[n][k];
}
double expected(int g1,int g2,int gc){
	if (g1 + gc == 0 || g2 + gc == 0) return 0.f;
	if (visit[g1][g2][gc]) return e[g1][g2][gc];
	visit[g1][g2][gc] = true;
	int r = N - g1 - g2 - gc;
	if (r < 0) r = 0;
	double deno = 1.f-(double)pt(r,D)/pt(N,D);
	int i, j, k;
	e[g1][g2][gc] = 1.f;
	for (i = 0; i <= g1; i++){
		for (j = 0; j <= g2; j++){
			for (k = 0; k <= gc; k++){
				if (i + j + k == 0) continue;
				if (i + j + k >D) continue;
				e[g1][g2][gc] += expected(g1 - i, g2 - j, gc - k)*(pt(g1, i) *pt(g2, j) *pt(gc, k)*pt(r,D-i-j-k) / (double)pt(N, D));
			}
		}
	}
	e[g1][g2][gc] /= deno;
	return e[g1][g2][gc];
}
int main(){
	int i;
	int draw;
	int g[4] = { 0 };
	for (scanf("%d%d%d", &N, &D, &C), i = 0; i < C; i++){
		scanf("%d",&draw);
		memo[draw]++;
	}
	while (i--){
		scanf("%d", &draw);
		memo[draw]+=2;
	}
	for (i = 1; i <= N; i++) g[memo[i]]++;
	printf("%f",expected(g[1],g[2],g[3]));
	return 0;
}
