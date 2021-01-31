//math, greedy
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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int p[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> p[i];
		ll s = 0;
		ll ans = 0;
		for (i = 1; i < n; ++i) {
			s += p[i];
			ll l = k * s;
			ll r = 100LL * p[i + 1];
			if (l<r) {
				ll diff = r - l;
				ll div = diff / k;
				if (diff%k) ++div;
				ans += div;
				s += div;
			}
		}
		cout << ans << "\n";
	}
 
	return 0;
}