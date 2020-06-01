//game, graph
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
int dfs(int x, int from, int root,vector<int> edge[1001]) {
	int sz = 0;
	if (x != root) sz = 1;
	for (auto nxt : edge[x]) {
		if (from == nxt) continue;
		int d = dfs(nxt, x, root, edge);
		if (x == root) {
			if (d & 1) d = 1;
			else d = 2;
			sz += d;
		}
		else sz += d;
	}
	return sz;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> edge[1001];
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int sz = dfs(x, 0, x, edge);
		if (edge[x].size()<=1) cout << "Ayush\n";
		else if (sz & 1) cout << "Ayush\n";
		else cout << "Ashish\n";
	}
 
	return 0;
}