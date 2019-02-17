//graph, dp
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[1000001];
int d[1000001][2];
int min(int a, int b) { return a < b ? a : b; }
void dfs(int x, int from) {
	d[x][1] = 1;
	for (auto v : edge[x]) {
		if (v == from) continue;
		dfs(v, x);
		d[x][0] += d[v][1];
		d[x][1] += min(d[v][1], d[v][0]);
	}
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i < N; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d",min(d[1][0],d[1][1]));
	return 0;
}