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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
vector<int> edge[400001],rev[400001];
int vis[400001];
int n, m;
bool dfs(int x, int from,int stamp) {
	if (vis[x] == stamp) return 1;
	if (vis[x] == -stamp) return 0;//cont
	vis[x] = stamp;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (dfs(nxt, x, stamp) == 0) return 0;
	}
	for (auto nxt : rev[x]) {
		if (nxt == from) continue;
		if (dfs(nxt, x, stamp) == 0) return 0;
	}
	return 1;
}
int dfs2(int x, int from,int stamp) {
	vis[x] = stamp;
	int cnt = x > n;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (vis[nxt] == stamp) continue;
		cnt += dfs2(nxt, x, stamp);
	}
	for (auto nxt : rev[x]) {
		if (nxt == from) continue;
		if (vis[nxt] == stamp) continue;
		cnt += dfs2(nxt, x, stamp);
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; cin >> n >> m;
		int nn = n + n;
		for (i = 1; i <= nn; ++i) {
			edge[i].clear(), vis[i] = 0;
			rev[i].clear();
		}
		for (i = 0; i < m; ++i) {
			string cmt; int u, v; cin >> u >> v >> cmt;
			if (cmt[0] == 'i') {
				edge[u].push_back(v + n);
				rev[v + n].push_back(u);
				edge[u + n].push_back(v);
				rev[v].push_back(u + n);
			}
			else {
				edge[u].push_back(v);
				rev[v].push_back(u);
				edge[u + n].push_back(v + n);
				rev[v + n].push_back(u + n);
			}
		}
		int stamp = 1; int cont = 0;
		for (i = 1; i <= n && cont==0; ++i) {
			if (vis[i] != 0) continue;
			dfs(i, 0, stamp);
			if (dfs(i + n, 0, -stamp) == 0) cont = 1;
			++stamp;
		}
		if (cont) {
			cout << "-1\n"; 
			continue;
		}
		stamp = 1e9;
		int ans = 0;
		for (i = 1; i <= n; ++i) {
			if (vis[i] == stamp) continue;
			int c1 = dfs2(i, 0, stamp);
			int c2 = dfs2(i + n, 0, stamp);
			//printf("%d,%d\n",c1,c2);
			ans += max(c1, c2);
		}
		cout << ans << "\n";
 
	}
 
	return 0;
}