//greedy, math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int r[1111], c[1111];
int cell[1111][1111];//-1:W, 1:B 0:any
int main() {
	int i, j, h, w;
	ll ans = 1;
	for (scanf("%d%d", &h, &w), i = 1; i <= h; ++i) scanf("%d",r+i);
	for (i = 1; i <= w; ++i) scanf("%d",c+i);
	
	for (i = 1; i <= h; ++i) {
		for (j = 0; j < r[i]; ++j) {
			cell[i][j + 1] = 1;
		}
		cell[i][1 + r[i]] = -1;
	}
	for (j = 1; j <= w &&ans; ++j) {
		for (i = 0; i < c[j] && ans; ++i) {
			if (cell[1 + i][j] == -1) ans =0;
			cell[1 + i][j] = 1;
		}
		if (cell[1 + c[j]][j] == 1) ans = 0;
		cell[1 + c[j]][j] = -1;
	}
	if (ans == 0) {
		printf("0");
		return 0;
	}
	int e = 0;
	for (i = 1; i <= h; ++i) {
		for (j = 1; j <= w; ++j) {
			e += (cell[i][j] == 0);
		}
	}
	ll base = 2;
	while (e) {
		if (e & 1) ans = ans * base%mod;
		e >>= 1;
		base = (base * base) % mod;
	}
	printf("%I64d",ans);
	return 0;
}