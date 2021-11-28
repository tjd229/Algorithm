//implementation
#include <stdio.h>
int a[2001][2001];
int h[2001][2001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n,q;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a[0]+i),h[0][i]=0;
		for (i = 1; i <= n; ++i) {
			for (int j = 1; j <= 2000; ++j) h[j][i] = 0;
			++h[0][a[0][i]];
		}
		for (int j = 1; j <= 2000; ++j) {
			for (int i = 1; i <= n; ++i) {
				a[j][i] = h[j - 1][a[j-1][i]];
			}
			for (int i = 1; i <= n; ++i) ++h[j][a[j][i]];
			
		}
 
		for (scanf("%d", &q), i = 0; i < q; ++i) {
			int x, k; scanf("%d%d",&x,&k);
			if (k > 2000) k = 2000;
			printf("%d\n",a[k][x]);
		}
 
	}
 
	return 0;
}