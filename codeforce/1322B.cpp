//math, bs

#include <stdio.h>
#include <algorithm>
using namespace std;
int a[400001], b[400001];
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
	int ans = 0;
	for (int k = 0; k < 25; ++k) {
		int s = 1 << k;
		int mask = (s << 1) - 1;
		for (i = 1; i <= n; ++i) b[i] = a[i] & mask;
		sort(b + 1, b + 1 + n);
		int cnt = 0;
		for (i = 1; i < n; ++i) {
			auto l = lower_bound(b + 1 + i, b + 1 + n, s-b[i]);
			auto u = upper_bound(b + 1 + i, b + 1 + n, mask - b[i]);
			cnt ^= (u - l) & 1;
 
			l = lower_bound(b + 1 + i, b + 1 + n, s + mask + 1 - b[i]);
			cnt ^= (b + 1 + n - l)&1;
		}
		ans += (cnt << k);
	}
	printf("%d",ans);
 
	return 0;
}