//graph, djs

#include <stdio.h>
#include <vector>
using namespace std;
int p[50000001];
int mat[5001][5001];
int deg[5001];
int vis[5001];
vector<int> edge[5001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool un(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	p[b] = a;
	return 1;
}
void dfs(int x, vector<int> &c, int stamp = 1) {
	if (vis[x] == stamp) return;
	vis[x] = stamp;
	c.push_back(x);
	for (auto nxt : edge[x]) dfs(nxt, c);
}
bool Euler(vector<int> &c) {
	int n = c.size();
	if (n < 5) return 1;
	int f = 0; int m = 0;
	for (auto x : c) {
		if (deg[x] > 1) {
			for (int i = 1; i < deg[x]; ++i)
				f -= un(mat[edge[x][i - 1]][x], mat[x][edge[x][i]]);
			
		}
		f -= un(mat[edge[x].back()][x], mat[x][edge[x][0]]);
		m += deg[x];
	}
	f += m; m >>= 1;
	return n - m + f == 2;
}
bool K5(vector<int> &c) {
	if (c.size() != 5) return 0;
	for (auto x : c) {
		if (deg[x] != 4) return 0;
	}
	return 1;
}
bool K33(vector<int> &c) {
	if (c.size() != 6) return 0;
	p[c[0]] = 1;
	vector<int> q = { c[0] };
	for (int i = 0; i < q.size(); ++i) {
		int x = q[i];
		if (deg[x] != 3) return 0;
		for (auto nxt : edge[x]) {
			if (p[nxt] == 0) {
				p[nxt] = 3 - p[x];
				q.push_back(nxt);
			}
			if (p[nxt] != 3 - p[x]) return 0;
		}
	}
	return 1;
}
int main() {
	int i, j;
	int mod, n; scanf("%d%d", &mod, &n);
	int ans = 1;
	if (mod == 1) {
		//mat,vec
		int cnt = 1;
		for (i = 1; i <= n; ++i) {
			//self-edge chk?
			for (scanf("%d", deg + i), j = 0; j < deg[i]; ++j) {
				int x; scanf("%d", &x);
				edge[i].push_back(x);
				if (mat[i][x] == 0) {
					mat[i][x] = cnt;
					mat[x][i] = cnt + 1;
					p[cnt] = cnt; ++cnt;
					p[cnt] = cnt; ++cnt;
				}
			}
			//cc...			
		}
		vector<int> c;
		for (i = 1; i <= n && ans > 0; ++i) {
			dfs(i, c);
			if (!Euler(c)) ans = -1;
			c.clear();
		}
	}
	else {
		//deg,sub
		int _n, m; scanf("%d%d", &_n, &m);
		for (i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			mat[u][v] = mat[v][u] = 1;
			++deg[u]; ++deg[v];
		}
		for (i = 1; i <= n; ++i) {
			if (deg[i] == 2) {//comp
				int u = -1, v = -1;
				for (int j = 1; j <= n; ++j) {
					if (mat[i][j]) {
						if (u == -1) u = j;
						else v = j;
					}
				}
				deg[i] = 0;
				mat[i][u] = mat[u][i] = 0;
				mat[i][v] = mat[v][i] = 0;
				deg[u] -= mat[u][v];//if mat[u][v]: --deg
				deg[v] -= mat[v][u];
				mat[u][v] = mat[v][u] = 1;
			}
		}
		int src = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (mat[i][j]) edge[i].push_back(j), src = j;
			}
		}
		vector<int> c; //only sub? no expand?
		dfs(src, c);
		if (K5(c) == 0 && K33(c) == 0) ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
