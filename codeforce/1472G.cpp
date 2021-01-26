//graph
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[200001];
int d[200001], act[200001];
int inq[200001];
int dfs(int x, int from) {
	if (inq[x] == 2) return act[x];
	inq[x] = 2;
	act[x] = d[x];
	for (auto nxt : edge[x]) {
		if (d[nxt] <= d[x]) {
			if (act[x] > d[nxt]) act[x] = d[nxt];
		}
		else {
			int mn = dfs(nxt, x);
			if (act[x] > mn) act[x] = mn;
		}
	}
	return act[x];
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		queue<int> q;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			d[i] = 0; inq[i] = 0;
			edge[i].clear();
		}
		for (i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			edge[u].push_back(v);
		}
		q.push(1); inq[1] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (auto nxt : edge[x]) {
				if (inq[nxt] == 0) {
					inq[nxt] = 1;
					d[nxt] = d[x] + 1;
					q.push(nxt);
				}
			}
		}
		dfs(1, 0);
		for (i = 1; i <= n; ++i) printf("%d ", d[i] > act[i] ? act[i] : d[i]);
		puts("");
	}
 
	return 0;
}