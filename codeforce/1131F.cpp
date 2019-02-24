//graph, djs
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
vector<int> edge[150001];
int vis[150001];
int p[150001], l[150001], r[150001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void un(int a, int b) {
	a = find(a); b = find(b);
	//
	p[b] = a;
	r[a] = r[b];
}
void dfs(int x) {
	cout << x << " ";
	vis[x] = 1;
	for (auto v : edge[x]) {
		if (vis[v]) continue;
		dfs(v);
	}
}
int main() {
	int i, n;
	cin >> n;
	for (i = 1; i <= n; ++i) p[i] = r[i] = l[i] = i;
	for (i = 1; i < n; ++i) {
		int x, y; cin >> x >> y;
		int rx = r[find(x)];
		int ly = l[find(y)];
		un(x, y);
		edge[rx].push_back(ly);
		edge[ly].push_back(rx);
	}
	for (i = 1; i <= n; ++i) {
		if (edge[i].size() == 1) {
			dfs(i);
			break;
		}
	}
	return 0;
}
