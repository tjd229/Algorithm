//math, bs
#include <stdio.h>
int res[10];
int a[10][1000];
int sz[10];
int ask(int *a, int s, int e) {
	printf("? %d ", e - s + 1);
	for (int i = s; i <= e; ++i) printf("%d ", a[i]);
	printf("\n"); fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
int main() {
	int n, x, y;
	int i, j, k;
	int p1, p2;
	int target = -1;
	for (scanf("%d%d%d", &n, &x, &y), i = 1, k = 0; i <= n; i <<= 1, ++k) {
		int &size = sz[k];
		for (j = 1; j <= n; ++j) {
			if (j&i) {
				a[k][size++] = j;
			}
		}
	}
	for (i = 0; i < k; ++i) {
		int pred = x * (sz[i] & 1);
		res[i] = ask(a[i], 0, sz[i] - 1);
		if (pred != res[i]) {
			if (target<0 || sz[target] > sz[i]) target = i;
		}
	}
	int l = 0;
	int r = sz[target] - 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		int pred = x * ((m - l + 1) & 1);
		int real = ask(a[target], l, m);
		if (pred == real) l = m + 1;
		else r = m - 1;
	}
	p1 = a[target][l];
	for (p2 = 0, i = 0; i < k; ++i) {
		int pred = x * (sz[i] & 1);
		if ((1 << i) & p1) {
			pred ^= x;
			res[i] ^= y;
		}
		if (pred != res[i]) p2 += (1 << i);
	}
	if (p1 > p2) p1 ^= p2 ^= p1 ^= p2;
	printf("! %d %d", p1, p2); fflush(stdout);
	return 0;
}
