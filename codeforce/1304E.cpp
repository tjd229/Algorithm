//graph, LCA

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
const int lg =17;
vector<int> edge[100001];
int p[100001][lg + 1];
int depth[100001];
void dfs(int x,int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		p[nxt][0] = x;
		depth[nxt] = depth[x] + 1;
		dfs(nxt, x);
	}
}
int climb(int ix, int d) {
	int k = 0;
	while (d != 0) {
		if (d & 1) ix = p[ix][k];
		d >>= 1;
		k++;
	}
	return ix;
}
int get_lca(int a, int b) {
	if (a == b) return a;
	int k = lg;
	while (k >= 0) {
		if (p[a][k] != p[b][k]) {
			a = p[a][k];
			b = p[b][k];
		}
		k--;
	}
	return p[a][0];
}
int dist(int a, int b) {
	int dd = depth[a] + depth[b];
	if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
	if (depth[b] > depth[a]) b = climb(b, depth[b] - depth[a]);
	int lca = get_lca(a, b);
	return dd - depth[lca] - depth[lca];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int i,j;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	for (j = 1; j <= lg; j++) {
		for (i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	int q; cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		//add(x->y)
		//find a->b
		int dab = dist(a, b);
		
		int dax = dist(a, x);
		int day = dist(a, y);
		int dbx = dist(b, x);
		int dby = dist(b, y);
		int d = dab;
		if (d <= k && ((k - d) & 1) == 0) {
			cout << "YES\n";
			continue;
		}
		d = dax + dby + 1;
		if (d <= k && ((k - d) & 1) == 0) {
			cout << "YES\n";
			continue;
		}
		d = day + dbx + 1;
		if (d <= k && ((k - d) & 1) == 0) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
 
	return 0;
}
