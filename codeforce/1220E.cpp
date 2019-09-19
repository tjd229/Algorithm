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
int deg[200001];
int w[200001];
int vis[200001];
int needle[200001];
vector<int> edge[200001];
int s;
ll body;
ll nmx;
bool bodypaint(int x,int from) {
	if (vis[x]) return 1;
	vis[x] = 1;
	int c = 0;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;		
		bool n = bodypaint(nxt, x);
		if(!n) needle[nxt] = 1;
		else c = 1;
	}
	//if(c)
		//body += w[x];
	return c;
}
ll dfs(int x,int from) {//stamp 2
	
	ll mx = 0;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		ll res=dfs(nxt,x);
		if (res > mx) mx = res;
	}
	return mx + w[x];;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> body_v;
	int i, n, m; cin >> n >> m;
	int s;
	for (i = 1; i <= n; ++i) cin >> w[i];
	for (i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		++deg[u]; ++deg[v];
	}
	cin >> s; 
	
	while (deg[s] == 1) {
		int nxt = edge[s][0];
		if (vis[nxt]) nxt = edge[s][1];		
		//body += w[s];
		vis[s] = 1;
		--deg[nxt];
		s = nxt;
	}
	bodypaint(s, 0);
	
	for (i = 1; i <= n; ++i) {
		if (needle[i] == 0) {
			body_v.push_back(i);
			body += w[i];
		}
	}	
	for (auto x : body_v) {
		for (auto v : edge[x]) {
			ll wsum = 0;
			if (needle[v]) wsum = dfs(v, x);
			if (nmx < wsum) nmx = wsum;
		}
	}
	//cout << body << endl;
	cout << body+nmx;
 
	return 0;
}