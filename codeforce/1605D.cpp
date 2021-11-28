//graph, math, game
#include<stdio.h>
#include <vector>
using namespace std;
vector<int> edge[200001];
vector<int> odd, even;
int p[200001];
void dfs(int x, int from, int o) {
	if (o) odd.push_back(x);
	else even.push_back(x);
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x, 1 - o);
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		vector<int> f[21],g, unroll[2];
		int i, n;
		int b = 0; int base = 2;
		odd.clear(); even.clear();
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			if (base == i) {
				base += base;
				++b;
			}
			f[b].push_back(i);
			edge[i].clear();
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		for (i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, 0, 1);
		int x = odd.size(); int odd_ix = 0;
		if (x > even.size()) x = even.size(), odd_ix =1;
		for (i = 0; i < 21 ; ++i) {
			if (x&(1<<i)) {
				x -= (1 << i);
				for (auto y : f[i])
					unroll[0].push_back(y);
			}
			else {
				for (auto y : f[i])
					unroll[1].push_back(y);
			}
		}
		for (auto x : odd) {
			p[x] = unroll[odd_ix].back();
			unroll[odd_ix].pop_back();
		}
		odd_ix = 1 - odd_ix;
		for (auto x : even) {
			p[x] = unroll[odd_ix].back();
			unroll[odd_ix].pop_back();
		}
		for (i = 1; i <= n; ++i) printf("%d ",p[i]);
		puts("");
	}
	return 0;
}