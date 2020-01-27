//math
#include <stdio.h>
int n, k;
int qry(int ban) {
	printf("?");
	for (int i = 1; i <= k + 1; ++i) {
		if (i == ban) continue;
		printf(" %d",i);
	}
	printf("\n"); fflush(stdout);
	int pos, a; scanf("%d%d",&pos,&a);
	return a;
}
int main() {
	int mx = -1, m = 0;
	int i;
	for (scanf("%d%d", &n, &k), i = 1; i <= k + 1; ++i) {
		int res = qry(i);
		if (mx < res) mx = res, m = 1;
		else if (mx == res) ++m;
	}
	printf("! %d",m);
	return 0;
}