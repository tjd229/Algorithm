//graph, greedy
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[300001];
int clr[300001],vis[300001];
int dfs(int x) {
	if (vis[x]) return 0;
	vis[x] = 1;
	int teacher = 0;
	int cnt = 1;
	for (auto nxt : edge[x]) teacher |= clr[nxt];
	if (teacher == 0) clr[x] = 1;
	for (auto nxt : edge[x])
		cnt += dfs(nxt);
	return cnt;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n, m;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
			edge[i].clear();
			clr[i] = 0; vis[i] = 0;
		}
		for (i = 1; i <= m; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if (n != dfs(1))
			printf("NO\n");
		else {
			vector<int> ans;
			for (i = 1; i <= n; ++i) if (clr[i]) ans.push_back(i);
 
			printf("YES\n%d\n",ans.size());
			for (auto x : ans) printf("%d ",x);
			puts("");
		}
	}
 
	return 0;
}