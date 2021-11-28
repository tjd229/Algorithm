//graph, math
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
vector<int> edge[200001];
int a[200001];
int cut = 0;
int dfs(int x, int from,int p) {
	int res = a[x];
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		res ^= dfs(nxt, x, p);
	}
	if (res == p) {
		++cut;
		return 0;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k;
		cin >> n >> k;
		int p = 0; cut = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			edge[i].clear();
			p ^= a[i];
		}
		for (i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if (p == 0) cout << "YES\n";
		else {
			int res=dfs(1, 0, p);
			if (cut >= 5) cut = 3;
			if (cut>1 && cut <= k  && res==0) cout << "YES\n";
			else cout << "NO\n";
		}
		
	}
 
	return 0;
}