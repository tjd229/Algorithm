//math, greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[300001];
ll s[300002];
int main() {
	int i,n,k;
	ll ans = 0;
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
	for (i = n; i > 0; --i) s[i] = s[i + 1] + a[i];
	sort(s + 2, s + 1 + n, [](ll a, ll b) {
		return a > b;
	});
	for (i = 1; i <= k; ++i) ans += s[i];
	printf("%I64d",ans);

	return 0;
}