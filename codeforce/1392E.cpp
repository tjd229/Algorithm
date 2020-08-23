//math
#include <stdio.h>
#define ll long long
ll a[26][26];
int main() {
	int i, j, n;
	scanf("%d",&n);
	ll base = 1;
	for (i = 2; i <= n; ++i) {
		int y = i, x = 1;
		while (y > 0) {
			//printf("%d,%d\n",y,x);
			a[y][x] = base;
			x += 2; y -= 2;
		}
		base += base;
	}
	
	for (i = 2; i < n; ++i) {
		int y = n, x = i;
		while (x<=n) {
			a[y][x] = base;
			x += 2, y -= 2;
		}
		base += base;
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) printf("%I64d ",a[i][j]);
		printf("\n");
	}fflush(stdout);
	
	int q;
	for (scanf("%d", &q); q--;) {
		ll k; scanf("%I64d",&k);
		int x = 1, y = 1;
		while (x != n || y != n) {
			printf("%d %d\n", y, x);
			if (x == n) ++y;
			else if (y == n) ++x;
			else {
				ll r = a[y][x + 1];
				ll d = a[y + 1][x];
				if (r) k&r ? ++x : ++y;
				else k&d ? ++y : ++x;
			}
		}
		printf("%d %d\n", y, x); fflush(stdout);
	}
	return 0;
}
