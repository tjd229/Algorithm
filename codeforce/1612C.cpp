//math, bs
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; ll k; ll x; cin >> k >> x;
		ll m = ((k - 1)*k) >> 1;
		
		ll ans = 0;
		//printf("%lld,%lld\n",x,m);
		if (x <= m+k) {
			ll s = 1, e = k;
			int add = 1;
			while (s <= e) {
				ll m = (s + e) >> 1;
				ll ex = (m * (m + 1)) >> 1;
				if (ex <= x) {
					s = 1 + m;
					add = m;
					if (x - ex && add < 1 + m) add = 1 + m;
				}
				else e = m - 1;
			}
			ans += add;
		}
		else {
			if (m + m + k <= x) ans = k + k - 1;
			else {
				x -= m + k; ans+=k;
				ll c = m;
				ll s = 1, e = k - 1;
				int add = 1;
				while (s <= e) {
					ll m = (s + e) >> 1;
					ll rm = k - 1 - m;
					ll ex = c - ((rm*(rm+1)) >> 1);
					if (ex <= x) {
						s = 1 + m;
						add = m;
						if (x - ex && add < 1 + m) add = 1 + m;
					}
					else e = m - 1;
				}
				ans += add;
			}
		}
		cout << ans<< "\n";
		
	}
 
	return 0;
}