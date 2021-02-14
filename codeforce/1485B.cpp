//math
#include <stdio.h>
int a[100001];
int d[100001];
int s[100001];
int main() {
	int i, n, q, k;
	for (scanf("%d%d%d", &n, &q, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
	for (i = 1; i + 1 <= n; ++i) d[i] = a[i + 1] - a[i]-1;
	for (i = 1; i <= n; ++i) s[i] = s[i - 1] + d[i];
	while (q--) {
		int l, r; scanf("%d%d",&l,&r);
		int cnt = 0;
		if (l <= r - 1) {
			cnt = s[r - 1] - s[l-1];
			cnt += cnt;
		}
		cnt += a[l] - 1;
		cnt += k - a[r];
		printf("%d\n",cnt);
	}
	return 0;
}