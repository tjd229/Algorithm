//math
#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;
int cnt[60];
ll x[500001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (i = 0; i < 60; ++i) cnt[i] = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%I64d", x + i);
			for (int mv = 0; mv < 60; ++mv) {
				if ((1LL << mv)&x[i]) ++cnt[mv];
			}
		}
		ll ans = 0;
		for (i = 1; i <= n; ++i) {
			ll t2 = 0,t1=0;
			for (int mv = 0; mv < 60; ++mv) {
				ll t3 = cnt[mv];
				ll base = 1LL << mv;
				if (base&x[i]) {
					t3 = n;
					base %= mod;
					t1 = (t1 + base * cnt[mv]) % mod;
				}
				base %= mod;
				t2 = (t2 + t3 * base) % mod;
			}	
			ll t = t1 * t2%mod;
			ans = (ans + t) % mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}