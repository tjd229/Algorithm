//graph
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
const int mod = 1e9 + 7;
vector<int> edge[100001];
ll sz[100001];
void dfs(int x, int from) {
	sz[x] = 1;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x);
		sz[x] += sz[nxt];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n,m;
		cin >> n;
		vector<ll> factor;
		vector<ll> num;
		for (i = 1; i <= n; ++i) edge[i].clear();
		for (i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cin >> m;
		for (i = 0; i < m; ++i) {
			int p; cin >> p;
			factor.push_back(p);
		}
		dfs(1, 0);
		for (i = 2; i <= n; ++i) {
			ll num_path = sz[i] * (n - sz[i]);
			num.push_back(-num_path);
		}
		sort(num.begin(), num.end());
		sort(factor.begin(), factor.end());
		while (factor.size() > num.size()) {
			ll x = factor.back(); factor.pop_back();
			ll y = factor.back(); factor.pop_back();
			factor.push_back(x*y%mod);
		}
		ll ans = 0;
		for (auto x : num) {
			ll num_path = -x;
			//printf("%lld\n",num_path);
			if (factor.size()) {
				ans = (ans + num_path * factor.back())%mod;
				factor.pop_back();
			}
			else ans = (ans + num_path) % mod;
		}
		cout << ans << "\n";
	}
 
	return 0;
}