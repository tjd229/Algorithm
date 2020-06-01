//implementation
#include <stdio.h>
int a[8001];
int s[8001];
int m[8001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j,n;
		int stamp = 1 + t;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			s[i] = s[i - 1] + a[i];
		}
		for (i = 1; i <= n; ++i) {
			for (j = i + 1; j <= n; ++j) {
				int val = s[j] - s[i - 1];
				if (val <= 8000) m[val] = stamp;
			}
		}
		int ans = 0;
		for (i = 1; i <= n; ++i) ans += (m[a[i]] == stamp);
		printf("%d\n",ans);
	}
	return 0;
}