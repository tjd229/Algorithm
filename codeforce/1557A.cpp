//math
#include <stdio.h>
 
int a[100001];
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, mx = -2e9;
		double sum = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d",a+i);
			if (mx < a[i]) mx = a[i];
			sum += a[i];
		}
		sum -= mx;
		double ans = mx + sum / (n - 1);
		printf("%lf\n",ans);
	}
 
	return 0;
}