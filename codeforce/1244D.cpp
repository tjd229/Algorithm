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
ll d[100001];
vector<int> edge[100001];
int deg[100001];
int c[4][100001];
int b[100001];
vector<int> order;
void dfs(int x, int from) {
	order.push_back(x);
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x);
	}
}
int main() {
	int i, n;
	ios::sync_with_stdio(false);
	vector<int> opt, clr = {1,2,3};
	cin.tie(0);
	cin >> n;
	for (int j = 1; j <= 3; ++j){
		for (i = 1; i <= n; ++i) 
		
			cin >> c[j][i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		++deg[u]; ++deg[v];
	}
	int root,ed;
	ll mn = -1;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) root = i;
		else if (deg[i] > 2) {
			cout << "-1";
			return 0;
		}
	}
	dfs(root, 0);
	do {
		ll sum = 0;
		int ix = 0;
		for (auto x : order) {
			sum += c[clr[ix]][x];
			if (++ix > 2) ix = 0;
		}
		if (mn == -1 || mn > sum) {
			mn = sum;
			opt = clr;
		}
	} while (next_permutation(clr.begin(), clr.end()));
	int ix = 0;
	for (auto x : order) {
		b[x] = opt[ix];
		if (++ix > 2) ix = 0;
	}
	cout << mn << "\n";
	for (int i = 1; i <= n; ++i) cout << b[i] << " ";
 
	return 0;
}
