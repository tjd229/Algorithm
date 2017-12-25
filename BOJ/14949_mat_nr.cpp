//category : math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int H, W;
ll mat[200][200];
void mat_mul(ll A[][200], ll B[][200]){
	int i, j, k;

	ll mat[200][200] = { 0 };
	for (i = 0; i < W; i++){
		for (j = 0; j < W; j++){
			for (k = 0; k < W; k++){
				mat[i][j] += (A[i][k] * B[k][j]) % mod;
				if (mat[i][j] >= mod) mat[i][j] %= mod;
			}
		}
	}
	for (i = 0; i < W; i++){
		for (j = 0; j < W; j++)
			A[i][j] = mat[i][j];
	}
}
void mat_pow(ll dest[][200], ll src[][200], int e){
	int i, j;
	ll mat[200][200] = { 0 };
	for (i = 0; i < W; i++){
		for (j = 0; j < W; j++){
			dest[i][j] = i == j ? 1 : 0;
			mat[i][j] = src[i][j];
		}
	}
	while (e != 0){
		if (e & 1){
			mat_mul(dest,mat);
		}
		mat_mul(mat, mat);
		e >>= 1;
	}
}
int main(){
	int i, j;
	ll ans = 0;
	scanf("%d%d", &H, &W);
	//H = 1e9;
	for (i = 0; i < W; i++) mat[0][i] = 1, mat[i][0] = i + 1;
	for (i = 1; i < W; i++){
		for (j = 1; j < W; j++){
			mat[i][j] = mat[i][j - 1] + mat[i - 1][j];
			if (mat[i][j] >= mod) mat[i][j] %= mod;
		}
	}
	ll after[200][200] = { 0 };
	mat_pow(after, mat, H);
	for (i = 0; i < W; i++){
		ans += after[0][i];
		if (ans >= mod) ans %= mod;
	}
	printf("%lld", ans);
	return 0;
}
