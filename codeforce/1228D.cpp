//graph, greedy
#include <stdio.h>
#include <vector>
using namespace std;
int clr[100001];
int sz[3];
vector<int> edge[100001];
int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 0; i < m; ++i) {
		int a, b; scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (auto x : edge[1]) {
		clr[x] = 1;
	}
	if (edge[1].empty()) {
		printf("-1");
		return 0;
	}
	int ans = 1;
	int v2 = edge[1][0];
	for (auto x : edge[v2]) {
		if (clr[x] == 0) continue;
		clr[x] = 2;
	}
	for (int i = 1; i <= n; ++i) ++sz[clr[i]];
	ans = sz[0] > 0 && sz[1] > 0 && sz[2] > 0;
	for (int i = 1; i <= n && ans; ++i) {
		int c = clr[i];
		if (edge[i].size() != n - sz[c]) ans = 0;
		for (auto x : edge[i]) {
			if (clr[x] == c) ans = 0;
		}
	}
	if (ans) {
		for (int i = 1; i <= n; ++i) printf("%d ",clr[i]+1);
	}
	else printf("-1");
	return 0;
}