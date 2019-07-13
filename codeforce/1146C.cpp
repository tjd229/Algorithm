//graph
#include <stdio.h>
int qry(int piv,int s,int e,int *b) {
	printf("1 %d %d",e-s+1,piv);
	for (int i = s; i <= e; ++i) printf(" %d",b[i]);
	printf("\n"); fflush(stdout);
	int d; scanf("%d",&d);
	return d;
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		int b[101] = { 0 };
		int piv = 1;
		for (i = 2; i <= n; ++i) b[i] = i;
		int l = 2, r = n;
		int mxd = qry(piv,l,r,b);
		while (l <= r) {
			int m = (l + r) >> 1;
			if (qry(piv, l, m, b) == mxd) r = m - 1;
			else l = m + 1;
		}
		piv = b[r+1];
		b[r + 1] = 1;
		printf("-1 %d\n",qry(piv,2,n,b));
		fflush(stdout);	
 
	}
	return 0;
}