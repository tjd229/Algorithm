//math, greedy, line sweeping
#include <stdio.h>
#define ll long long
int p[1000001], q[1000001];
int main() {
	int i, n; ll k;
	ll s = 0;
	ll mx = 0;
	for (scanf("%d%I64d", &n, &k), i = 1; i <= n; ++i) {
		p[i] = q[i] = i;
		s += i;
	}
	if (s > k) {
		printf("-1");
		return 0;
	}
	int h = n >> 1;
	for (i = 1; i <= h; ++i) mx += p[n - i + 1] - p[i];
	if (s + mx <= k) {
		for (printf("%I64d\n", s + mx), i = 1; i <= n; ++i) printf("%d ",i);
		for (printf("\n"), i = n; i > 0; --i) printf("%d ",i);
		return 0;
	}
	ll remain = k - s;
	int l = 1, r = n;
	while (remain) {
		while (remain < q[r] - q[l]) ++l;
		remain -= q[r] - q[l];
		q[r] ^= q[l] ^= q[r] ^= q[l];
		--r; ++l;
	}
	for (printf("%I64d\n", k), i = 1; i <= n; ++i) printf("%d ", p[i]);
	for (printf("\n"), i = 1; i <= n; ++i) printf("%d ", q[i]);
 
	
	return 0;
}