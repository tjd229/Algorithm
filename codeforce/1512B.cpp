//implementation
#include <stdio.h>
char mp[401][401];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) scanf(" %c",mp[i]+j);
		}
		int x[2], y[2];
		int ix = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (mp[i][j] == '*') {
					x[ix] = j; y[ix] = i;
					++ix;
				}
			}
		}
		if (x[0] == x[1]) {
			if (x[0] == n) x[0] = 1;
			else x[0] = n;
		}
		if (y[0] == y[1]) {
			if (y[0] == n) y[0] = 1;
			else y[0] = n;
		}
		for (i = 0; i < 2; ++i) {
			for (j = 0; j < 2; ++j) {
				int xx = x[j];
				int yy = y[i];
				mp[yy][xx] = '*';
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) printf("%c",mp[i][j]);
			puts("");
		}
		puts("");
	}
 
	return 0;
}