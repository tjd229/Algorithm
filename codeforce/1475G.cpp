//dp, math
#include <stdio.h>
int d[250001];
int cnt[250001];
int a[250001];
int main() {
	int t;
 
	for (scanf("%d", &t); t--;) {
		int i, n;
		int mx = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i), ++cnt[a[i]];
			if (mx < a[i]) mx = a[i];
		}
		
		int ans = 0;
		for (i = 2; i <= mx; ++i) {
			d[i] += cnt[i];
			if (d[i]) {
				for (int j = 2; i*j <= mx; ++j) {
					if (cnt[i*j] && d[i*j] < d[i]) d[i*j] = d[i];
				}
			}
			if (ans < d[i]) ans = d[i];
		}
		printf("%d\n",n-(ans+cnt[1]));
		for (i = 1; i <= mx; ++i) cnt[i] = d[i] = 0;
	}
 
	return 0;
}
