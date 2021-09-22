//math
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main() {
	int i, n;
	vector<ll > heros;
	ll cum = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		ll a; scanf("%I64d\n", &a); heros.push_back(a);
		cum += a;
	}
	sort(heros.begin(), heros.end());
	int m;
	for (scanf("%d", &m); m--;) {
		ll x, y; scanf("%I64d%I64d",&x,&y);
		ll ans = -1;
		auto it = lower_bound(heros.begin(), heros.end(), x);
		if (it != heros.end()) {
			cum -= *it;
			if (cum < y) ans = y - cum;
			else ans = 0;
			cum += *it;
		}
		if (it != heros.begin()) {
			--it;
			ll coin = x - *it;
			cum -= *it;
			if (cum < y) coin += y - cum;
			if (ans<0 || ans>coin) ans = coin;
			cum += *it;
		}
		printf("%I64d\n", ans); 
	}
 
	return 0;
}