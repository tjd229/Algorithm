//math
#include<stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a1, a2, a3;
		scanf("%d%d%d",&a1,&a2,&a3);
		int d = a2 + a2 - a1 - a3;
		if (d < 0) d = -d;
		if (d % 3) printf("1\n");
		else printf("0\n");
	}
	return 0;
}