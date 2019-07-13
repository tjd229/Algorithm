//math
#include <stdio.h>
const int mod = 1e6 + 3;
int a[11];
int mat[11][11];
int *pt[11];
int pow_mod(long long b,int e) {
	long long res = 1;
	while (e) {
		if (e & 1) res = res * b%mod;
		e >>= 1;
		b = b * b%mod;
	}
	return res;
}
inline void pt_swap(int* &p1, int* &p2) {
	int *t = p1;
	p1 = p2;
	p2 = t;
}
int main() {
	int i, j;
	printf("? 0\n"); fflush(stdout);
	scanf("%d",a+0);
	for (i = 1; i <= 10; ++i) {
		printf("? %d\n",i); fflush(stdout);
		scanf("%d",mat[i]+0);
		mat[i][0] -= a[0];
		while (mat[i][0] < 0) mat[i][0] += mod;
		for (int j = 1; j <= 10; ++j) mat[i][j] = pow_mod(i,j);
		pt[i] = mat[i];
	}
	
	for (i = 1; i <= 10; ++i) {
		long long deno = pow_mod(mat[i][i],mod-2);
		for (j = 0; j <= 10; ++j) mat[i][j] = mat[i][j] * deno%mod;
		for (j = 1; j <= 10; ++j) {
			if (i == j) continue;
			long long s = mat[j][i];
			for (int k = 0; k <= 10; ++k) {
				mat[j][k] -= s * mat[i][k] % mod;
				while (mat[j][k] < 0) mat[j][k] += mod;
			}
		}
	}
	for (i = 1; i <= 10; ++i) a[i] = mat[i][0];
	for (int x = 0; x < mod; ++x) {
		long long res = a[0];
		long long xx = x;
		for (i = 1; i <= 10; ++i) {
			res += a[i] * xx%mod;
			if (res >= mod) res -= mod;
			xx = xx * x%mod;
		}
		if (res == 0) {
			printf("! %d\n", x); fflush(stdout);
			return 0;
		}
	}printf("! -1\n"); fflush(stdout);
	return 0;
}