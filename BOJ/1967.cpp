//graph
#include <stdio.h>
#include <vector>
#define pii pair<int,int>
using namespace std;
vector<pii > edge[10001];
int d1[10001], d2[10001];
void dfs(int x, int *d) {
	for (auto p : edge[x]) {
		int v = p.first;
		int w = p.second;
		if (d[v] == 0) {
			d[v] = d[x] + w;
			dfs(v, d);
		}
	}
}
int main() {
	int i, n;
	int u, v, w;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back({ v,w });
		edge[v].push_back({ u,w });
	}
	dfs(1, d1); d1[1] = 0;
	w = 0;
	for (i = 1; i <= n; ++i) {
		if (w < d1[i]) {
			w = d1[i];
			u = i;
		}
	}
	dfs(u, d2); d2[u] = 0;
	for (i = 1, w = 0; i <= n; ++i) {
		if (w < d2[i]) w = d2[i];
	}
	printf("%d", w);
	return 0;
}
