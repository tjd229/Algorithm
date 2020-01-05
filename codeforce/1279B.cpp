//greedy
#include <stdio.h>
#define ll long long
int a[100001];
 
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n, s;
		ll sum = 0;
		for (scanf("%d%d", &n, &s), i = 1; i <= n; ++i)
			scanf("%d", a + i);
		
		int mx = 0;
		int skip = 0;
		int cnt = 0;
		int ans = 0;
		for (i = 1; i <= n && sum<=s; ++i) {
			sum += a[i];
			if (mx < a[i]) mx = a[i],skip=i;
			++cnt;
			if (sum <= s) ans = cnt;
		}
		if (sum > s) {
			sum -= a[skip]; --cnt;
			int ans2 = cnt;
			for (; i <= n && sum <= s; ++i) {
				sum += a[i];
				++cnt;
				if (sum <= s) ans2 = cnt;
			}
			//printf("%d,%d\n",ans,ans2);
			if (ans2 < ans) skip = 0;
		}
		else skip = 0;
		printf("%d\n",skip);
	}
	return 0;
}
