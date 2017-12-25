//category : math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int H, W;
ll mat[200][200];
void mat_mul(ll dest[][200],ll A[][200], ll B[][200]){
	int i, j, k;
	for (i = 0; i < W; i++){
		for (j = 0; j < W; j++){
			for (k = 0; k < W; k++){
				dest[i][j] += (A[i][k] * B[k][j]) % mod;
				if (dest[i][j] >= mod) dest[i][j] %= mod;
			}
		}
	}	
}
void mat_pow(ll dest[][200],ll src[][200], int e){
	//printf("%d\n",e);
	int i, j;
	if (e <= 1){
		for (i = 0; i < W; i++){
			for (j = 0; j < W; j++)
				dest[i][j] = e? src[i][j]:(i==j? 1:0);
		}
	}
	else if (e & 1){
		ll mat[200][200] = { 0 };
		mat_pow(mat,src,e-1);
		mat_mul(dest,mat,src);
	}
	else{
		ll mat1[200][200] = { 0 };
		ll mat2[200][200] = { 0 };
		
		mat_pow(mat1, src, e>>1);
		for (i = 0; i < W; i++){
			for (j = 0; j < W; j++){
				mat2[i][j] = mat1[i][j];
			}
		}
		mat_mul(dest,mat1,mat2);
	}
}
int main(){
	int i, j;
	ll ans = 0;
	scanf("%d%d",&H,&W);
	//H = 1e9;
	for (i = 0; i < W; i++) mat[0][i] = 1,mat[i][0]=i+1;
	for (i = 1; i < W; i++){
		for (j = 1; j < W; j++){
			mat[i][j] = mat[i][j - 1] + mat[i - 1][j];
			if (mat[i][j] >= mod) mat[i][j] %= mod;
		}
	}
	ll after[200][200] = { 0 };
	mat_pow(after,mat,H);
	for (i = 0; i < W; i++){
		ans += after[0][i];
		if (ans >= mod) ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}
