//bs
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll a[200000], b[200000];
int main() {
	int i, n, m, ta, tb, k;
	ll ans = -1;
	for (scanf("%d%d%d%d%d", &n, &m,&ta, &tb, &k), i = 0; i < n; ++i)
		scanf("%I64d",a+i);
	for (i = 0; i < m; ++i) scanf("%I64d",b+i);
	if (n <= k) {
		printf("-1");
		return 0;
	}
	for (i = 0; i < n && i <= k; ++i)
	{
		auto it = lower_bound(b,b+m,a[i]+ta);
		int ix = it - b + k - i;
		if (ix >= m) {
			ans = -1;
			break;
		}
		else if (ans < b[ix] + tb)
			ans = b[ix] + tb;
	}
	printf("%I64d",ans);
	return 0;
}