//category : math, d&c

#include <stdio.h>
#define ll long long
const int mod = 1000;
struct Mat{
	int n;
	ll ele[5][5];
	Mat operator*=(Mat m) {
		ll tmp[5][5] = { 0 };
		int i, j, k;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				for (k = 0; k < n; k++){
					tmp[i][j] += ele[i][k] * m.ele[k][j];
					if (tmp[i][j] >= mod) tmp[i][j] %= mod;
				}
			}
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				ele[i][j] = tmp[i][j];// , printf("%lld ", e[i][j]);
		return *this;
	}
	Mat operator ^=(ll e){
		if (e == 1) return *this;
		Mat m1, m2;
		m1 = m2 = *this;
		int i, j;
		if (e & 1){
			m1 ^= e-1;
			m1 *= m2;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					ele[i][j] = m1.ele[i][j];
			return *this;
		}
		else{
			m1 ^= (e >> 1);
			m1 *= m1;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					ele[i][j] = m1.ele[i][j];
			return *this;
		}

	}
};
int main(){
	int i,j;
	int N;
    ll B;
	Mat m;
	for (scanf("%d%lld",&N,&B),i=0;i<N;i++){
		for (j = 0; j < N; j++)
			scanf("%lld", &m.ele[i][j]),m.ele[i][j]%=mod;
	}
	m.n = N;
	//m *= m;
	m ^= B;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			printf("%lld ", m.ele[i][j]);
		printf("\n");
	}
	return 0;
}
