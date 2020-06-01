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
int a[200001], b[200001], c[200001];
vector<int> edge[200001];
ll cost;
void propagation(int x,int from,int mn) {
	if (mn > a[x]) mn = a[x];
	a[x] = mn;
	for (auto nxt : edge[x]) {
		if (from == nxt) continue;
		propagation(nxt, x, mn);
	}
}
pii dfs(int x,int from) {//#b,#c
	pii cnt = { 0,0 };
	if (b[x] != c[x]) {
		if (b[x]) cnt.first += 1;
		else cnt.second += 1;
	}
	for (auto nxt : edge[x]) {
		if (from == nxt) continue;
		pii nxtcnt = dfs(nxt, x);
		cnt.first += nxtcnt.first;
		cnt.second += nxtcnt.second;
	}
	ll mn = cnt.first < cnt.second ? cnt.first : cnt.second;
	cost += mn * a[x]*2;
	cnt.first -= mn;
	cnt.second -= mn;
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i]>>b[i]>>c[i];
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	propagation(1, 0, a[1]);
	pii cnt=dfs(1, 0);
	if (cnt.first + cnt.second)
		cout << "-1";
	else cout << cost;
	return 0;
}