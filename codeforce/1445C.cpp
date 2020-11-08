//math
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
map<int,int> decomp(ll X) {
	map<int,int> mp;
	for (ll i = 2; i*i <= X; ++i) {
		if (X%i == 0) {
			while (X%i == 0) {
				X /= i;
				++mp[i];
			}
			
		}
	}
	if (X > 1) ++mp[X];
	return mp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll p, q; cin >> p >> q;
		if (p%q) cout << p << "\n";
		else {
			map<int, int> q_div = decomp(q);
			map<int, int> p_div;
			ll _p = p;
			for (auto it=q_div.begin(); it != q_div.end(); ++it) {
				int val = it->first;
				if (_p%val == 0) {
					while (_p%val == 0) {
						_p /= val;
						++p_div[val];
					}
				}
			}
			ll ans = 1;
			for (auto it = q_div.begin(); it != q_div.end(); ++it) {
				int val = it->first;
				int tgt = it->second;
				int d = p_div[val] - (tgt-1);
				//printf("%d,%d,%d,%d\n",val,tgt,d, p_div[val]);
				ll m = 1;
				for (int i = 0; i < d; ++i) m *= val;
				ll c = p / m;
				if (ans < c) ans = c;
			}
			cout << ans << "\n";
		}
	}
 
	return 0;
}