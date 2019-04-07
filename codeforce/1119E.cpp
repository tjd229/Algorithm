//greedy
#include <stdio.h>
#define ll long long
ll a[300001];
int main() {
	int i, n;
	ll r = 0,ans=0,d=0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%I64d", a + i);
		ll b = a[i] - (a[i]&1);
		//printf("%lld,%lld,%lld\n", a[i],b, r);
		if (b >= r) {
			b -= r;
			a[i] -= r;
			r = 0;
		}
		else {
			r -= b;
			a[i] -= b;
			a[i] = a[i]&1;
		}
		if (a[i] > 0) {
			d += a[i] / 3;
			int mod = a[i] % 3;
			ans += mod;
			r += mod + mod;
		}
	}
	if (r>0) {
		ans -= (r >> 1);
	}
	printf("%I64d",ans+d);
	return 0;
}
