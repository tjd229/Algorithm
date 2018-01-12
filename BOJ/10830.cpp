//category : math, d&c

#include <stdio.h>
#define ll long long
const int mod = 1000;
int N;
void mat_mul(ll m1[][5], ll m2[][5]){
	int i, j, k;
	ll tmp[5][5] = { 0 };
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			for (k = 0; k < N; k++){
				tmp[i][j] += m1[i][k] * m2[k][j];
				if (tmp[i][j] >= mod) tmp[i][j] %= mod;
			}
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			m1[i][j] = tmp[i][j];
}
void mat_pow(ll m[][5],ll e){
	if (e == 1) return;
	int i, j;
	ll tmp[5][5] = { 0 };
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			tmp[i][j] = m[i][j];
	if (e & 1){
		mat_pow(m, e - 1);
		mat_mul(m,tmp);
	}
	else{
		mat_pow(m, e >> 1);
		mat_mul(m, m);
	}
}
int main(){
	int i, j;
	ll mat[5][5];
	ll B;
	for (scanf("%d%lld", &N, &B), i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%lld",&mat[i][j]), mat[i][j]%=mod;
	mat_pow(mat,B);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			printf("%lld ",mat[i][j]);
		printf("\n");
	}
	return 0;
}
