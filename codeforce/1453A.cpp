//implementation
#include<stdio.h>
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, j, n, m;
		int ans = 0;
		int sch[101] = { 0 };
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			int t; scanf("%d", &t);
			sch[t] = 1;
		}
		for (i = 1; i <= m; ++i) {
			int t; scanf("%d",&t);
			if (sch[t]) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}