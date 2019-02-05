//bs
#include <stdio.h>
#define ll long long
ll min(ll a, ll b) { return a < b ? a : b; }
int main() {
	int N, k;
	scanf("%d%d",&N,&k);
	ll l = 1;
	ll r = (ll)N * N;
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll cnt = 0;
		for (int i = 1; i <= N; ++i) 
			cnt += min(N, m / i);
		if (cnt < k) l = m + 1;
		else r = m - 1;
	}
	printf("%lld",r+1);
	return 0;
}