//greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[200001];
int order[200001];
int main() {
	ll ans = 0;
	int n, m, k;
	int i;
	for (scanf("%d%d%d", &n, &m, &k), i = 0; i < n; ++i) {
		scanf("%d",a+i);
		ans += a[i];
		order[i] = i;
	}
	sort(order, order + n, [](int i, int j) {
		return a[i] < a[j];
	});
	int d = n - m * k;
	for (i = 0; i < d; ++i) {
		ans -= a[order[i]];
		a[order[i]] = -2e9;
	}
	printf("%I64d\n",ans);
	int cnt = 0;
	int g = 1;
	for (i = 0; i < n; ++i) {
		if (a[i] < -1e9) continue;
		if (++cnt == m) {
			printf("%d ",i+1);
			cnt = 0;
			if (++g == k) break;
		}
	}
	return 0;
}
