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
int ans[100000];
int u[100000], v[100000];
vector<int> edge[100001];//ix
int cnt;
void dfs(int x,int eix) {
	
	if (edge[x].size() > 2) {
		for (auto ix : edge[x]) {
			if (ans[ix] == 0) ans[ix] = ++cnt;
		}
	}
	for (auto ix : edge[x]) {
		if (ix == eix) continue;
		int nxt = x == u[ix] ? v[ix] : u[ix];
		dfs(nxt, ix);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		cin >> u[i] >> v[i];
		edge[u[i]].push_back(i);
		edge[v[i]].push_back(i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n - 1; ++i) {
		if (ans[i] == 0) ans[i] = ++cnt;
		cout << ans[i] - 1 << "\n";
	}
 
	return 0;
}