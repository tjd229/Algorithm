//math, greedy
#include <stdio.h>
#include <algorithm>
#define ull unsigned long long
using namespace std;
int a[200001];
int main() {
	int i, n, m, k;
	for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i)
		scanf("%d",a+i);
	sort(a + 1, a + 1 + n);
	if (a[n] == a[n - 1])
		printf("%I64d",(ull)a[n]*m);
	else {
		ull ans = 0;
		if (m >= k + 1) {
			ull d = m / (k + 1);
			ull r = m % (k + 1);
			ans = d * (ull)a[n] * (ull)(k );
			ans += a[n - 1] * (ull)d;
			ans += r * a[n];
			//printf("%I64d\n", m);
		}
		else ans = a[n] * (ull)m;
		printf("%I64d",ans);
	}
	return 0;
}
