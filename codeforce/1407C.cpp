//math
#include <stdio.h>
int p[10001];
int qry(int x,int y) {
	printf("? %d %d\n", x, y); fflush(stdout);
	int k; scanf("%d",&k);
	return k;
}
int main() {
	int i, n; scanf("%d",&n);
	if (n == 1) {
		printf("! 1"); fflush(stdout);
		return 0;
	}
	int mx=1;	
	for (i = 2; i <= n; ++i) {
		int a = qry(mx, i), b = qry(i, mx);
		if (a < b) {
			p[i] = b;
		}
		else {
			p[mx] = a;
			mx = i;
		}
	}
	p[mx] = n;
	for (printf("!"), i = 1; i <= n; ++i) printf(" %d",p[i]);
	fflush(stdout);

	return 0;
}