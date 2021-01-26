//greedy
#include <stdio.h>
int a[1001][1001];
int b[1001][1001];
int n;
void vxor(int j) {
	for (int i = 1; i <= n; ++i) a[i][j] = 1 - a[i][j];
}
void hxor(int i) {
	for (int j = 1; j <= n; ++j) a[i][j] = 1 - a[i][j];
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) scanf("%1d",a[i]+j);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) scanf("%1d", b[i] + j);
		}
		for (i = 1; i <= n; ++i) {
			if (a[i][1] != b[i][1]) hxor(i);
		}
		for (j = 1; j<= n; ++j) {
			if (a[1][j] != b[1][j]) vxor(j);
		}
		bool same = 1;
		for (i = 1; i <= n && same; ++i) {
			for (j = 1; j <= n && same; ++j) {
				if (a[i][j] != b[i][j]) same = 0;
			}
		}
		printf("%s\n",same? "YES":"NO");
	}
 
	return 0;
}