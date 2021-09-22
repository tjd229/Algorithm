//dp
#include <stdio.h>
int a[3001];
int d[3001][3001];
int nxt[3001],last[3001];
int min(int a, int b) { return a < b ? a : b; }
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i,j, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i),last[i]=1+n;
		for (i = n; i > 0; --i) {
			nxt[i] = last[a[i]];
			last[a[i]] = i;
		}
		for (i = n; i > 0; --i) {
			d[i][i] = 0;
			for (j = i + 1; j <= n; ++j) {
				d[i][j] = min(d[i + 1][j],d[i][j - 1])+1;
				for (int pos = nxt[i]; pos <= j; pos = nxt[pos])
					d[i][j] = min(d[i][j], d[i][pos - 1] + d[pos][j]);
			}
		}
		printf("%d\n",d[1][n]);
	}
 
	return 0;
}