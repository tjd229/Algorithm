//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
int cnt[100001];
int f[100001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			cnt[i] = 0; f[i] = 0;
			scanf("%d",a+i);
		}
		int k = 0;
		for (i = 1; i <= n; ++i) {
			++cnt[a[i]];
			if (i > 1 && a[i - 1] == a[i]) f[a[i]] += 2,++k;
		}
		++f[a[1]]; ++f[a[n]];
		int mx = *max_element(cnt + 1, cnt + n + 1);
		if (mx > (n + 1) >> 1) {
			printf("-1\n");
			continue;
		}
		mx= *max_element(f + 1, f + n + 1);
		int ans = k;
		if (mx - (k + 2) > 0) ans += mx - (k + 2);
		printf("%d\n",ans);
	}

	return 0;
}