//graph, SCC, tp sort
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
int p[200001];
int q[200001];
int n, k;
vector<int> edge[200001], back[200001];
 
int vis[200001];
int g[200001];
 
vector<int> meta[200001];
int ind[200001]; int lev[200001];
void dfs(int x, int stamp, vector<int> *edge) {
	if (vis[x] == stamp) return;
	vis[x] = stamp;
	for (auto nxt : edge[x]) dfs(nxt,stamp,edge);
	edge[0].push_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	set<pii > st;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) cin >> q[i];
	for (int i = 1; i < n; ++i) {
		edge[p[i]].push_back(p[i+1]);
		edge[q[i]].push_back(q[i + 1]);
		back[p[i + 1]].push_back(p[i]);
		back[q[i + 1]].push_back(q[i]);
	}
	for (int i = 1; i <= n; ++i) dfs(i, 1, edge);
	int gc = 0;
	while (edge[0].size()) {
		int x = edge[0].back(); edge[0].pop_back();
		dfs(x, 2, back);
		if (back[0].size()) {
			++gc;
			for (auto y : back[0]) {
				g[y] = gc;
				//cout << y << endl;
			}
			back[0].clear();
		}
	}
	if (gc == 1 && k == 1) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) cout << 'a';
	}
	else if (gc<k) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			int u = g[i];
			for (auto x : edge[i]) {
				int v = g[x];
				pii par = { u,v };
				if (u == v) continue;
				if (st.find(par) == st.end()) {
					st.insert(par);
					meta[u].push_back(v);
					ind[v]++;
				}
			}
		}
		queue<int> q;
		for (int i = 1; i <= gc; ++i) {
			if (ind[i] == 0) q.push(i),lev[i]=0;
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			
			for (auto nxt : meta[x]) {
				lev[nxt] = max(lev[nxt], lev[x] + 1);
				if (--ind[nxt] == 0) q.push(nxt);
			}
		}
		for (int i = 1; i <= n; ++i) {
			int lv = min(lev[g[i]], 25);
			
			char c = 'a' + lv;
			//cout << lv << endl;
			cout << (char)c;
		}
	}
 
	return 0;
}