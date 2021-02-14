//math
#include <stdio.h>
int a[501][501];
int b[501][501];
int gcd(int a, int b) {//a<b
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main() {
	int i, j, n, m;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) scanf("%d",a[i]+j);
	int lcm = 2;
	for (i = 3; i <= 16; ++i) lcm = lcm * i / gcd(lcm,i);
	
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if ((i + j) & 1) printf("%d ",lcm);
			else printf("%d ", lcm- a[i][j] * a[i][j] * a[i][j] * a[i][j]);
		}
		puts("");
	}

	return 0;
}