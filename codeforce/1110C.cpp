//math
#include <stdio.h>
int ans[1 << 25];
int main() {
	int q;
	for (scanf("%d", &q); q--;) {
		int a; int b = 1;
		scanf("%d",&a);
		while (a >= b)b <<= 1;
		if (a == b - 1) {
			if (ans[a] == 0) {
				ans[a] = 1;
				for (int b = 2; b < a; ++b) {
					if (b*b > a) break;
					if (a%b) continue;
					int d1 = a / b;
					int d2 = a / d1;
					if (ans[a] < d1) ans[a] = d1;
					if (ans[a] < d2) ans[a] = d2;
				}
			}
			printf("%d\n",ans[a]);
		}
		else printf("%d\n",b-1);
	}
	return 0;
}
