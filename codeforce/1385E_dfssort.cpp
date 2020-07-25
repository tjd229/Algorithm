//graph, tp sort
#include <stdio.h>
#include <vector>
using namespace std;
int tp[200001];
int vis[200001];
int t[200001], x[200001], y[200001];
int cnt;
vector<int> edge[200001];
void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	for (auto nxt : edge[x]) dfs(nxt);
	tp[x] = ++cnt;
}
int main() {
	int i, tc;
	for (scanf("%d", &tc); tc--;) {
		int n, m; cnt = 0;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			edge[i].clear();
			tp[i] = 0;
			vis[i] = 0;
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d",t+i,x+i,y+i);
			if (t[i]) edge[x[i]].push_back(y[i]);
		}
		for (i = 1; i <= n; ++i) dfs(i);
		bool flag = 1;
		for (i = 1; i <= m && flag; ++i) {
			if (tp[x[i]] < tp[y[i]]) {
				if (t[i]) flag = 0;
				else x[i] ^= y[i] ^= x[i] ^= y[i];
			}
		}
		for (printf("%s\n", flag ? "YES" : "NO"), i = 1; i <= m && flag; ++i)
			printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}