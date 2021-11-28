//graph, math, dp

#include <iostream>
#include <string>
#include <map>
#include <set>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int dict[26];
ll node;
map<ll, int> d[6];
set<pair<ll, ll> > edge;
set<pair<ll, int> > clr;
ll _pow(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		x = x * x%mod;
		e >>= 1;
	}
	return res;
}
void dfs(ll x) {
	--node;
	ll c[2] = { 0 };
	pair<ll,ll> e = { x,0 };
	auto it = edge.lower_bound(e);
	if (it != edge.end() && it->first==x) {
		c[0] = it->second;
		edge.erase(it);
		dfs(c[0]);
	}
	it = edge.lower_bound(e);
	if (it != edge.end() && it->first == x) {
		c[1] = it->second;
		edge.erase(it);
		dfs(c[1]);
	}
	if (c[0] == 0) {
		for (int i = 0; i < 6; ++i) d[i][x] = 1;
	}
	else {
		for (int i = 0; i < 6; ++i) {
			ll cnt = 0;
			ll cc2=0;
			if (c[1] == 0) cc2 = 1;
			else {
				for (int j = 0; j < 6; ++j) {
					if (i % 3 == j % 3) continue;
					cc2 = (cc2 + d[j][c[1]]) % mod;
				}
			}
			for (int j = 0; j < 6; ++j) {
				if (i % 3 == j % 3) continue;
				ll cc1 = d[j][c[0]];
				cnt = cnt+cc1 * cc2%mod;
				cnt %= mod;
			}
			d[i][x] = cnt;
		}
	}
	pair<ll, int> det = {x,0};
	auto clr_it = clr.lower_bound(det);
	while (clr_it!=clr.end() && clr_it->first==x) {
		int c = clr_it->second;
		for (int i = 0; i < 6; ++i) {
			if (i != c) d[i][x] = 0;
		}
		clr.erase(clr_it);
		clr_it = clr.lower_bound(det);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, k; ll n;
	dict['w' - 'a'] = 0; dict['g' - 'a'] = 1; dict['r' - 'a'] = 2;
	dict['y' - 'a'] = 3; dict['b' - 'a'] = 4; dict['o' - 'a'] = 5;
	cin >> k >> n;
	node = (1LL << k) - 1;
	while (n--) {
		ll v; string s; cin >> v >> s;
		clr.insert({v,dict[s[0]-'a']});
		ll p = v >> 1;
		while (p > 0) {
			edge.insert({p,v});
			v = p; p >>= 1;
		}
	}
	if (clr.empty()) {
		ll ans = 6 * _pow(4, node - 1)%mod;
		cout << ans;
	}
	else {
		dfs(1);
		
		ll ans = 0;
		for (i = 0; i < 6; ++i) ans = (ans + d[i][1]) % mod;
		ans = ans * _pow(4, node) % mod;
		cout << ans;
	}



	return 0;
}