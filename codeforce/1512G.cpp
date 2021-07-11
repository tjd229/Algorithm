//math
#include <stdio.h>
int d[10000001];
int d_inv[10000001];
int main() {
	int i, j;
	for (i = 1; i <= 10000000; ++i) {
		d_inv[i] = -1;
		for (j = i; j <= 10000000; j += i)
			d[j] += i;
	}
	for (i = 10000000; i > 0; --i) {
		if (d[i] <= 10000000)
			d_inv[d[i]] = i;
	}
	int t;
	for (scanf("%d", &t); t--;) {
		int c; scanf("%d",&c);
		printf("%d\n",d_inv[c]);
	}
 
 
	return 0;
}