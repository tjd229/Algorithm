//geometry, math
#include <stdio.h>
int qry(const char *op,int r, int c) {
	printf("%s %d %d\n", op,r, c); fflush(stdout);
	int resp; scanf("%d",&resp);
	return resp;
}
int main() {
	int i, j, t, n, m;
	for (scanf("%d", &t); t--;) {
		scanf("%d%d",&n,&m);
		int a = qry("SCAN",1,1),b=qry("SCAN",1,m);

		int xmid = (a - b + 2 + m + m) / 4;
		int ymid = (a + b - m-m + 6) / 4;
		int c = qry("SCAN",1,xmid), d=qry("SCAN",ymid,1);
		int x1 = ((a - c) + 2) / 2;
		int x2 = (a - b + m + m + 2 - x1 - x1) / 2;
		int y1 = ((a - d) + 2) / 2;
		int y2 = (a + b - m - m + 6 - y1 - y1) / 2;

		if (qry("DIG", y1, x1)) qry("DIG", y2, x2);
		else {
			qry("DIG", y2, x1); qry("DIG", y1, x2);
		}
	}


	return 0;
}
