//graph, dp
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[10001];
int d[10001][2];
int max(int a, int b) { return a < b ? b : a; }
void dfs(int x,int from) {	
	for (auto v : edge[x]) {
		if (v == from) continue;
		dfs(v,x);
		d[x][1]+= d[v][0];
		d[x][0] += max(d[v][0],d[v][1]);
	}
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%d",&d[i][1]);
	for (i = 1; i < N; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d",max(d[1][0],d[1][1]));
	return 0;
}