//graph, LCA, dp, math
#include <stdio.h>
#include <memory.h>
#include <vector>
#define ll long long
using namespace std;
const int lg = 8;
const int mod = 1e9 + 7;
vector<int> edge[201];
ll e[201][201];
int p[201][lg+1];
int vis[201], depth[201];
int stamp;
int n;
int inv2, invn;
int _pow(ll x, int e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * x%mod;
		x = x * x%mod;
		e >>= 1;
	}
	return res;
}
int dp(int x,int y) {
	if (e[x][y] != -1) return e[x][y];
	ll &d = e[x][y];
	d = dp(x - 1, y) + dp(x, y - 1);
	d = d * inv2%mod;
	return d;
}
void dfs(int x, int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		depth[nxt] = depth[x] + 1;
		p[nxt][0] = x;
		dfs(nxt, x);
	}
}
void build_lca() {
	for (int j = 1; j <= lg; ++j) {
		for (int i = 1; i <= n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}
int climb(int x,int d) {
	int k = 0;
	while (d != 0) {
		if (d & 1) x = p[x][k];
		d >>= 1; ++k;
	}
	return x;
}
int get_lca(int a, int b) {
	if (depth[a] < depth[b]) b = climb(b, depth[b] - depth[a]);
	if (depth[a] > depth[b]) a = climb(a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int k = lg; k >= 0; --k) {
		if (p[a][k] != p[b][k]) {
			a = p[a][k];
			b = p[b][k];
		}
	}
	return p[a][0];
}
int main() {
	int i; ll ans = 0;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int x, y; scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(e, -1, sizeof(e));
	for (i = 1; i <= n; ++i) {
		e[0][i] = 0;
		e[i][0] = 1;
	}
	inv2 = _pow(2); invn = _pow(n);


	for (i = 1; i <= n; ++i) {
		memset(p, 0, sizeof(p));
		depth[i] = 0;
		dfs(i, 0);
		build_lca();
		ll _exp = 0;
		for (int j = 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				int lca = get_lca(j, k);
				_exp = (_exp + dp(depth[j] - depth[lca], depth[k] - depth[lca])) % mod;
			}
		}
		ans += _exp * invn%mod;
		ans %= mod;
	}
	
	printf("%I64d",ans);

	return 0;
}