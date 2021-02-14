//math, bs
#include <stdio.h>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int mod = 998244353;

ll sq2(ll x) {
	ll l = 1, r = 15e8;
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll mm = m * m;
		if (mm == x) return m;
		else if (mm > x) r = m - 1;
		else l = m + 1;		
	}
	return 0;
}
ll sq3(ll x) {
	ll l = 1, r = 13e5;
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll mm =m* m * m;
		if (mm == x) return m;
		else if (mm > x) r = m - 1;
		else l = m + 1;
	}
	return 0;
}
ll sq4(ll x) {
	ll l = 1, r = 38e3;
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll mm = m * m * m*m;
		if (mm == x) return m;
		else if (mm > x) r = m - 1;
		else l = m + 1;
	}
	return 0;
}
ll gcd(ll a, ll b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main() {
	map<ll, int> mp,pq;
	set<ll> st;
	int i, n;
	for (scanf("%d", &n), i = 0; i < n; ++i) {
		ll a; scanf("%I64d",&a);
		ll d = sq4(a);
		if (d) {
			mp[d] += 4;
			continue;
		}
		d = sq3(a);
		if (d) {
			mp[d] += 3;
			continue;
		}
		d = sq2(a);
		if (d) {
			mp[d] += 2;
			continue;
		}
		pq[a] += 1;
	}
	for (auto it : mp) st.insert(it.first);
	for (auto it1 = pq.begin(); it1 != pq.end(); ++it1) {
		for (auto it2 = next(it1); it2 != pq.end(); ++it2) {
			ll d = gcd(it1->first, it2->first);
			if (d > 1) {
				st.insert(d);
				st.insert(it1->first / d);
				st.insert(it2->first / d);
			}
		}
	}
	for (auto& x : pq) {
		for (auto div : st) {
			if (x.second == 0) break;
			if (div > x.first) break;
			if (x.first%div==0) {
				mp[div] += x.second;
				mp[x.first/div] += x.second;
				x.second = 0;
			}
		}
	}
	ll ans = 1;
	for (auto x : pq) {
		if (x.second) {
			int e = x.second+1;
			ans = ans * e*e%mod;
		}
	}
	for (auto it : mp) {
		int e = it.second;
		ans = ans * (e + 1) % mod;
	}
	printf("%I64d", ans); fflush(stdout);

	return 0;
}