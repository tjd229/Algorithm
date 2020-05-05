//implementation
#include <stdio.h>
int p[101], c[101];
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i)
			scanf("%d%d",p+i,c+i);
		bool flag = 1;
		for (i = 1; i <= n && flag; ++i) {
			if (p[i - 1] > p[i]) flag = 0;
			if (c[i - 1] > c[i]) flag = 0;
			if (p[i] < c[i]) flag = 0;
		}
		for (i = 2; i <= n && flag; ++i) {
			int dc = c[i] - c[i - 1];
			int dp = p[i] - p[i - 1];
			if (dp < dc) flag = 0;
		}
		printf("%s\n" ,flag? "YES":"NO");
	}
	return 0;
}