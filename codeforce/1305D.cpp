//graph
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[1001];
int ban[1001];
int coin;
int qry(int u, int v) {
	--coin;
	printf("? %d %d\n", u, v); fflush(stdout);
	int w; scanf("%d",&w);
	return w;
}
bool dfs(int x, int from, int tgt) {
	if (x == tgt) return 1;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		if (dfs(nxt, x, tgt)) return 1;
	}
	return 0;
}
void close(int x, int from) {
	ban[x] = 1;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		close(nxt,x);
	}
}
void discon(int w,int tgt) {
	for (int i = 0; i < edge[w].size(); ++i) {
		if (dfs(edge[w][i], w, tgt)) {
			close(edge[w][i], w);
			edge[w][i] = edge[w].back();
			edge[w].pop_back();
			return;
		}
	}
}
int main() {
	int i, n;
	int u, v;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	u=v = 0;
	for (i = 1; i <= n; ++i) {
		if (edge[i].size() == 1) {
			u = v;
			v = i;
		}
	}
	coin = n >> 1;
	int r = 0;
	while (!r) {
		int w = qry(u, v);
		if (coin == 0) r = w;
		else if (w == u) r = u;
		else if (w == v) r = v;
		else if (edge[w].size() == 2) r = w;
		else {
			discon(w, u);
			discon(w, v);
			u = v = 0;
			for (i = 1; i <= n; ++i) {
				if (ban[i]) continue;
				if (edge[i].size() == 1) {
					u = v;
					v = i;
				}
			}
		}		
	}
	printf("! %d", r); fflush(stdout);
	return 0;
}