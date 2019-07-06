//graph, d&c

#include <stdio.h>
#include <vector>
using namespace std;
int depth[200001],p[200001];
int sz[200001];
int block[200001];
int dx;
vector<int> edge[200001];
int ask(char c, int u) {
	printf("%c %d\n", c, u); fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
void dfs(int x,int from) {
	for (auto to : edge[x]) {
		if (to == from) continue;
		p[to] = x;
		depth[to] = depth[x] + 1;
		dfs(to, x);
	}
}
int get_sz(int x,int from) {
	sz[x] = 1;
	for (auto to : edge[x]) {
		if (block[to] || from == to) continue;
		sz[x] += get_sz(to,x);
	}
	return sz[x];
}
int get_cen(int x,int from,int half) {
	for (auto to : edge[x]) {
		if (block[to] || from == to) continue;
		if (sz[to] > half) return get_cen(to,x,half);
	}
	return x;
}
int cdfs(int x) {
	int half = get_sz(x,0)>>1;
	int cen = get_cen(x, 0, half); block[cen] = 1;
	int d = ask('d',cen);
	if (d == 0) return cen;
	if (depth[cen] + d == dx) return cdfs(ask('s',cen));
	return cdfs(p[cen]);
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	dx = ask('d',1);
	printf("! %d",cdfs(1));
	return 0;
}