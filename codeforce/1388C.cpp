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
vector<int> edge[100001];
ll p[100001]; ll op[100001];
ll h[100001];
ll tbad[100001],bad[100001], good[100001];
void dfs(int x, int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x);
		p[x] += p[nxt];
	}
}
 
bool dfs2(int x, int from) {
	tbad[x] = 0; bad[x] = 0;
	ll ac_bad = 0;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (dfs2(nxt, x) == 0) return 0;
		//bad[x] += bad[nxt];
		//p[x] -= bad[nxt];
		//h[x] += bad[nxt];//tgt
		ac_bad += tbad[nxt];
	}
	//printf("vis:%d\n",x);
	ll abs_h = h[x] > 0 ? h[x] : -h[x];
	if (abs_h > p[x]) return 0;
	ll r = p[x] - abs_h;
 
	if (r & 1) return 0;
	tbad[x] += (r >> 1);
	if (h[x] < 0) tbad[x] += abs_h;
	//printf("%d:%lld,sigma:%lld\n",x,bad[x],ac_bad);
	if (tbad[x] > ac_bad) bad[x] = tbad[x] - ac_bad;
	return 1;
}
bool dfs3(int x, int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (dfs3(nxt, x) == 0) return 0;
	}
	//if (bad[x] < 0) {
		if (op[x] < bad[x]) return 0;
	//}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, m; cin >> n >> m;
		for (i = 1; i <= n; ++i) cin >> p[i], edge[i].clear(),op[i]=p[i];
		for (i = 1; i <= n; ++i) cin >> h[i];
		for (i = 1; i < n; ++i) {
			int x, y; cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		dfs(1, 0);
 
		bool flag = dfs2(1, 0);
		if (flag) flag = dfs3(1, 0);
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		/*for (i = 1; i <= n; ++i) {
			printf("%d:p:%lld,h:%lld,bad:%lld\n",i,p[i],h[i],bad[i]);
		}*/
	}
 
	return 0;
}