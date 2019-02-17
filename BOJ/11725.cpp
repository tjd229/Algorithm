//graph
#include <stdio.h>
#include <vector>
using namespace std;
int p[100001];
vector<int> edge[100001];
void dfs(int x) {
	for (auto v : edge[x]) {
		if (p[v] == 0) {
			p[v] = x;
			dfs(v);
		}
	}
}
int main() {
	int i, N;
	for (scanf("%d", &N), i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	p[1] = 1;
	dfs(1);
	for (i = 2; i <= N; ++i) printf("%d\n",p[i]);
	return 0;
}