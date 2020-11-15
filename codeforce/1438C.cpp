//graph, djs
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
vector<int> edge[10001];
int vis[10001];
 
int p[10001],clr[10001];
int a[101][101];
int n, m;
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
void dsu(int a,int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int to1D(int x,int y) {
	return x + (y-1) * m;
}
void dfs(int x,int c) {
	if (vis[x]) return;
	vis[x] = 1;
	clr[x] = c;
	for (auto nxt : edge[x])
		dfs(nxt, 1 - c);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j; cin >> n >> m;
		for (i = 1; i <= n; ++i)for (j = 1; j <= m; ++j) cin >> a[i][j];
		int nm = n * m;
		for (i = 1; i <= nm; ++i) p[i] = i,clr[i]=0,vis[i]=0,edge[i].clear();
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				int d = a[i][j] - a[i - 1][j];
				if (d < 0) d = -d;
				int u = to1D(j, i), v = to1D(j,i-1);
				if (d == 1 && i > 1) dsu(u,v);
				d = a[i][j] - a[i][j-1];
				if (d < 0) d = -d;
				v = to1D(j - 1, i);
				if (d == 1 && j > 1) dsu(u,v);
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if (a[i - 1][j] == a[i][j]) {
					int u = find(to1D(j, i - 1)), v = find(to1D(j, i));
					edge[u].push_back(v);
					edge[v].push_back(u);
				}
				if (a[i][j-1] == a[i][j]) {
					int u = find(to1D(j-1, i)), v = find(to1D(j, i));
					edge[u].push_back(v);
					edge[v].push_back(u);
				}
			}
		}
		for (i = 1; i <= nm; ++i) dfs(i, 0);//meta
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				int p = find(to1D(j, i));
				cout << a[i][j] + clr[p]<<" ";
			}
			cout << "\n";
		}
		
	}
 
 
	return 0;
}