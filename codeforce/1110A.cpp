//math
#include <stdio.h>
int main() {
	int i, b, k;
	int a;
	int n = 0;
	for (scanf("%d%d", &b, &k), i = 1; i < k; ++i, n&=1) {
		scanf("%d",&a);
		n = n + (a & 1) * (b & 1);
	}
	scanf("%d",&a);
	n += (a & 1);
	printf("%s",n&1? "odd":"even");
	return 0;
}
