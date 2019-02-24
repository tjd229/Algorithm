//math
#include <stdio.h>
int a[100001];
int main() {
	int i, n;
	int mx = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (mx < a[i]) mx = a[i];
	}
	int len = 0;
	int ans = 0;
	for (i = 1; i <= n; ++i) {
		if (a[i] == mx) ++len;
		else len = 0;
		if (len > ans) ans = len;
	}
	printf("%d",ans);
	return 0;
}
