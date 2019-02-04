//implementation
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll a[100001];
int n, k, A, B;
ll destroy(ll l, ll r) {
	int cnt = upper_bound(a, a + k, r) - lower_bound(a, a + k, l);
	if (cnt == 0) return A;
	ll res= (ll)cnt * (r - l + 1) * B;
	if (r - l + 1 > 1) {
		ll m = (l + r) >> 1;
		ll left = destroy(l, m);
		ll right = destroy(m + 1, r);
		if (res > left + right) res = left + right;
	}
	return res;
}
int main() {
	int i;
	for (scanf("%d%d%d%d", &n, &k, &A, &B), i = 0; i < k; ++i) scanf("%I64d", a + i);
	
	sort(a, a + k);
	a[i] = a[i - 1] + 1;
	printf("%I64d",destroy(1,1LL<<n));
	
	return 0;
}
