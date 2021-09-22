//graph, greedy
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
vector<int> edge[200001];
int leaf[200001];
int bud[200001];
int numc[200001],nl[200001];
int p[200001];
void dfs(int ix, int from) {
	int c = 0;
	for (auto nxt : edge[ix]) {
		if (nxt == from) continue;
		++c;
		dfs(nxt, ix);
		p[nxt] = ix;
	}
	numc[ix] = c;
	if (c == 0 ) leaf[ix] = 1;
	else {
		bool bud_flag = ix > 1;
		if (c == 0) bud_flag = 0;
		for (auto nxt : edge[ix]) {
			if (nxt == from) continue;
			if(leaf[nxt]) ++nl[ix];
		}
		if (nl[ix] != numc[ix]) bud_flag = 0;
		bud[ix] = bud_flag;
	}
	//printf("%d,%d,%d\n",ix,nl[ix],numc[ix]);
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) edge[i].clear(),bud[i]=leaf[i]= numc[i]=nl[i]=p[i]=0;
		for (i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, 0);
		int tot_leaf = 0;
		int mv = 0;
		queue<int> q;
		for (i = 1; i <= n; ++i) {
			tot_leaf += leaf[i];
			if (bud[i]) q.push(i);
		}
		
		while (q.size()) {
			int x = q.front(); q.pop();
			tot_leaf -= nl[x];
			if (mv == 0) mv += nl[x];
			else mv += nl[x] - 1;
			int par = p[x];
			numc[par]--;
			if (numc[par] == 0) {
				tot_leaf++;
				if (par > 1) {
					par = p[par]; ++nl[par];
					if (par > 1 && numc[par] == nl[par]) q.push(par);//numc>0
				}
			}
			else if (par > 1&& numc[par] == nl[par]) q.push(par);//numc>0
			//printf("%d,%d,%d\n", x,tot_leaf,mv);
		}
		int ans=tot_leaf;
		if (mv > 0) ans = tot_leaf + mv - 1;
		
		cout << ans << "\n";
	}
 
 
	return 0;
}