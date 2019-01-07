//math
#include <stdio.h>
int a[5001];
int main() {
	int i;
	int n;
	int ab, bc, ac;
	scanf("%d",&n);
	printf("? 1 2\n"); fflush(stdout);
	scanf("%d",&ab);
	printf("? 1 3\n"); fflush(stdout);
	scanf("%d", &ac);
	printf("? 3 2\n"); fflush(stdout);
	scanf("%d", &bc);
	a[1] = (ab + ac - bc) >> 1;
	a[2] = ab - a[1];
	a[3] = ac - a[1];
	for (i = 4; i <= n; ++i) {
		int aij;
		printf("? 1 %d\n",i); fflush(stdout);
		scanf("%d",&aij);
		a[i] = aij - a[1];
	}
	printf("! ");
	for (i = 1; i <= n; ++i) printf("%d ",a[i]);
	return 0;
}
