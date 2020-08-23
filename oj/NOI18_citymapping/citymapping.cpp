//graph

#include "citymapping.h"
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
using namespace std;
vector<pii > edge[1001];
int sz[1001], p[1001];
ll d[1001][1001];
int dfs(int x) {
	if (edge[x].empty()) return x;
	int mx = 0;
	int nxt = 0;
	for (auto p : edge[x]) {
		int c = p.first;
		if (mx < sz[c]) {
			nxt = c;
			mx = sz[c];
		}
	}
	return dfs(nxt);
}
int find_par(int root, int x, ll dist) {
	//printf("%d,%d,%lld\n",root,x,dist);
	if (edge[root].empty()) return root;

	int leaf = dfs(root);
	ll x2l = get_distance(x, leaf);
	int lca = leaf;
	while (d[root][leaf] + dist < (d[root][lca] << 1) + x2l)
		lca = p[lca];// , printf("%d", lca);
	if (edge[lca].size() <= 1) return lca;
	//2
	int l = edge[lca][0].first, r = edge[lca][1].first;
	if (sz[l] < sz[r]) return find_par(l, x, dist - d[root][l]);
	else return find_par(r, x, dist - d[root][r]);
}
void find_roads(int N, int Q, int A[], int B[], int W[]) {
	ll mx = 0;
	int root = 0;
	for (int i = 2; i <= N; ++i) {
		d[1][i] = d[i][1] = get_distance(1, i);
		if (d[1][i] > mx) {
			mx = d[1][i];
			root = i;
		}
	}
	vector<pli > v;
	for (int i = 1; i <= N; ++i) {
		if (i == root) continue;
		d[root][i] = d[i][root] = get_distance(root, i);
		v.push_back({ d[root][i],i });
	}
	sort(v.begin(), v.end());
	sz[root] = 1;
	for (auto pr : v) {
		
		int x = pr.second;
		ll dist = pr.first;
		int par = find_par(root, x, dist);
		edge[par].push_back({ x,dist - d[par][root] });
		p[x] = par; sz[x] = 1;
		while (par) {
			++sz[par];
			d[par][x] = d[x][par] = d[root][x] - d[root][par];
			par = p[par];
		}
	}
	int len = 0;
	for (int i = 1; i <= N; ++i) {
		for (auto p : edge[i]) {
			A[len] = i;
			B[len] = p.first;
			W[len] = p.second;
			++len;
		}
	}
}