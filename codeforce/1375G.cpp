//graph
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[200001];
int clr[200001];
void color(int x,int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		clr[nxt] = 1 - clr[x];
		color(nxt, x);
	}
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int nc[2] = { 0 };
	color(1,0);
	for (i = 1; i <= n; ++i) ++nc[clr[i]];
	int op = nc[0] < nc[1] ? nc[0] : nc[1];
	printf("%d",--op);
	return 0;
}