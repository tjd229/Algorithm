//graph
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[200001];
int p[200001], a[200001], l[200001];
int last[200001],vis[200001];
int hist[200001];
int bnd[200001];
int n, m, q;
int max(int a, int b) { return a < b ? b : a; }
void dfs(int x,int d) {
	if (vis[x]) return;
	vis[x] = 1;
	hist[d] = x;
	if (d >= n) bnd[x] = hist[d-n+1];
	for (auto nxt : edge[x]) dfs(nxt, d + 1);
}
int main() {
	int i;
	for (scanf("%d%d%d", &n, &m, &q), i = 1; i <= n; ++i) {
		scanf("%d", p + i);
		l[p[i]] = p[i - 1];
	}
	p[0] = p[n]; l[p[1]] = p[0];
	for (i = 1; i <= m; ++i) {
		scanf("%d",a+i);
		int pre = l[a[i]];
		if (last[pre]) edge[last[pre]].push_back(i);
		last[a[i]] = i;
	}
	for (i = 1; i <= m; ++i) dfs(i, 1);
	for (i = 1; i <= m; ++i) bnd[i] = max(bnd[i], bnd[i - 1]);
	while (q--) {
		int l, r; scanf("%d%d",&l,&r);
		printf("%d",bnd[r]>=l);
	}
	return 0;
}
