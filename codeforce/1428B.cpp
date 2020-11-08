//graph, SCC
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
vector<int> edge[300001], back[300001];
int vis[300001];
void add_edge(int u, int v) {
	edge[u].push_back(v);
	back[v].push_back(u);
}
void dfs(int x, int stamp, vector<int> *edge,vector<int> &stk) {
	if (vis[x] == stamp) return;
	vis[x] = stamp;
	for (auto nxt : edge[x]) {
		
		dfs(nxt, stamp, edge,stk);
	}
	stk.push_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int stamp=0;
	while (t--) {
		int i, n; string s;
		cin >> n >> s;
		vector<int> stk;
		int ans = 0;
		for (i = 0; i < n; ++i) edge[i].clear(), back[i].clear();
		for (i = 0; i < n; ++i) {
			if (s[i] == '-') {
				add_edge(i, (i + 1) % n);
				add_edge((i + 1) % n, i);
			}
			else if (s[i] == '>') add_edge(i, (i + 1) % n);
			else add_edge((1 + i) % n, i);
		}
		++stamp;
		for (i = 0; i < n; ++i) dfs(i, stamp, edge,stk);
		++stamp;
		while (stk.size()) {
			vector<int> stk2;
			int x = stk.back(); stk.pop_back();
			dfs(x, stamp, back, stk2);
			/*for (auto x : stk2)
				cout << x << endl;
			cout << endl;*/
			if (stk2.size() > 1)
				ans += stk2.size();
			
 
		}
		cout << ans << "\n";
	}
 
	return 0;
}