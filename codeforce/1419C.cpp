//math, greedy
#include <stdio.h>
int a[1001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, x;
		int same = 0,s=0;
		for (scanf("%d%d", &n, &x), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			same += a[i] == x;
			s += a[i];
		}
		if (same == n) {
			printf("0\n");
			continue;
		}
		else if (same) {
			printf("1\n");
			continue;
		}
		
		int diff = 0;
		for (i = 1; i <= n; ++i) 
			diff += a[i] - x;
		printf("%d\n",diff==0? 1:2);
	}

	return 0;
}
