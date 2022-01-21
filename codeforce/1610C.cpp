//bs, greedy
#include <stdio.h>
int a[200001], b[200001];
int n;
bool inv(int x) {
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		if (x - a[i] - 1 <= c && c <= b[i]) ++c;
	}
	return c >= x;
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		for (scanf("%d", &n), i = 1; i <= n; ++i)
			scanf("%d%d",a+i,b+i);
 
		int l = 1, r = n;
		int ans = 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (inv(m)) {
				ans = m;
				l = 1 + m;
			}
			else r = m - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}