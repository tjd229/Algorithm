//greedy
#include <stdio.h>
#define ll long long
int a[100001];
int main() {
	int i, n, k;
	ll s = 0;
	for (scanf("%d%d", &n, &k), i = 1; i <= k; ++i) {
		a[i] = i;
		s += i;
	}
	if (s > n) {
		printf("NO");
		return 0;
	}
	int r = n - s;
	int d = r / k;
	for (i = 1; i <= k; ++i) a[i] += d;
	r %= k;//[0,k-1]
	for (i = k; i > 1 && r; --i) {
		int aa = a[i - 1] + a[i - 1];
		d = aa - a[i];
		if (d > r) d = r;
		a[i] += d;
		r -= d;
	}
	a[i] += r;
	for (i = 2; i <= k; ++i) {
		if (a[i - 1] >= a[i] || a[i - 1] + a[i - 1] < a[i]) {
			printf("NO");
			return 0;
		}
	}
	for (printf("YES\n"), i = 1; i <= k; ++i) printf("%d ",a[i]);
	return 0;
}