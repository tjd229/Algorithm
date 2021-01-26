//implementation
#include <stdio.h>
int a[300001];
int h[300001], v[300001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		int cnt = 0;
		int ans = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			h[i] = 0, v[i] = 0;
		}
		for (i = 2; i < n; ++i) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) h[i] = 1;
			if (a[i] < a[i - 1] && a[i] < a[i + 1]) v[i] = 1;
			cnt += h[i] + v[i];
		}
		ans = cnt;
		for (i = 2; i < n; ++i) {
			int bk = a[i];
			int bk_cnt = cnt;
			if (h[i]) {
				a[i] = a[i-1]; --cnt;
				if (v[i - 1]) --cnt;
				cnt -= h[i+1] + v[i+1];
				if (i + 1 < n 
					&& a[i + 1] > a[i] && a[i + 1] > a[i + 2]) ++cnt;
				if (i + 1 < n 
					&& a[i + 1] < a[i] && a[i + 1] < a[i + 2]) ++cnt;
				if (ans > cnt) ans = cnt;
				cnt = bk_cnt;
 
				a[i] = a[i + 1]; --cnt;
				if (v[i + 1]) --cnt;
				cnt -= h[i - 1] + v[i - 1];
				if (i - 1 >1 
					&& a[i - 1] > a[i] && a[i - 1] > a[i - 2]) ++cnt;
				if (i - 1 >1
					&& a[i - 1] < a[i] && a[i - 1] < a[i - 2]) ++cnt;
				if (ans > cnt) ans = cnt;
				a[i] = bk;
				cnt = bk_cnt;
			}
			if (v[i]) {
				a[i] = a[i - 1]; --cnt;
				if (h[i - 1]) --cnt;
				cnt -= h[i + 1] + v[i + 1];
				if (i + 1 < n 
					&& a[i + 1] > a[i] && a[i + 1] > a[i + 2]) ++cnt;
				if (i + 1 < n
					&& a[i + 1] < a[i] && a[i + 1] < a[i + 2]) ++cnt;
				if (ans > cnt) ans = cnt;
				cnt = bk_cnt;
 
				a[i] = a[i + 1]; --cnt;
				if (h[i + 1]) --cnt;
				cnt -= h[i - 1] + v[i - 1];
				if (i - 1 >1 
					&& a[i - 1] > a[i] && a[i - 1] > a[i - 2]) ++cnt;
				if (i - 1 >1 
					&& a[i - 1] < a[i] && a[i - 1] < a[i - 2]) ++cnt;
				if (ans > cnt) ans = cnt;
				a[i] = bk;
				cnt = bk_cnt;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}