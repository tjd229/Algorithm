//dp, math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
ll N;
int M;
void mat_mul(ll m1[][100], ll m2[][100]) {
	int i, j, k;
	ll res[100][100];
	for (i = 0; i < M; ++i) for (j = 0; j < M; ++j) res[i][j] = 0;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < M; ++j) {
			for (k = 0; k < M; ++k) {
				res[i][j] += (m1[i][k] * m2[k][j])%mod;
				res[i][j] %= mod;
			}
		}
	}
	for (i = 0; i < M; ++i) for (j = 0; j < M; ++j) m1[i][j]=res[i][j];
}
void mat_pow(ll dst[][100],ll m[][100],ll e) {
	ll src[100][100];
	for (int i = 0; i < M; ++i) for (int j = 0; j < M; ++j) src[i][j] = (i == j);
	while (e) {
		if (e & 1) {
			//src=src*m
			mat_mul(src, m);
		}
		e >>= 1;
		//m=m*m
		mat_mul(m, m);
	}
	for (int i = 0; i < M; ++i) for (int j = 0; j < M; ++j) dst[i][j] = src[i][j];
}
int main() {
	scanf("%I64d%d",&N,&M);
	if (N <= M)
		printf("%d",1+(N==M));
	else {
		ll base[100][100] = { 0 };
		ll res[100][100];
		for (int i = 1; i < M; ++i) base[i][i - 1] = 1;
		base[0][M - 1] = base[M - 1][M - 1] = 1;
		mat_pow(res, base, N-M);
		ll ans = 0;
		for (int i = 0; i < M; ++i) ans = (ans + res[i][M-1]) % mod;
		ans += res[M-1][M - 1];
		printf("%I64d",ans%mod);
		
	}
	return 0;
}
