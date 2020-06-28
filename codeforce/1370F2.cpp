//bs, graph
#include <stdio.h>
#include <numeric>
#include <vector>
using namespace std;
int n;
int depth[1001],from[1001];
char res[100];
pair<int,int> qry(vector<int> &v) {
	printf("? %d",v.size());
	for (auto x : v) printf(" %d",x);
	printf("\n"); fflush(stdout);
	int x, d; scanf("%d%d",&x,&d);
	return { x,d };
}
pair<int, int> dqry(int tgt = -1,int ban=-1) {
	if (tgt == -1) {
		vector<int> v(n);
		iota(v.begin(), v.end(), 1);
		return qry(v);
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (ban == i) continue;
		if (tgt == depth[i]) v.push_back(i);
	}
	return qry(v);
}
void dfs(int x,vector<int> edge[1001]) {
	for (auto nxt : edge[x]) {
		if (nxt == from[x]) continue;
		depth[nxt] = depth[x] + 1;
		from[nxt] = x;
		dfs(nxt, edge);
	}
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		vector<int> edge[1001];
		for (scanf("%d", &n), i = 1; i < n; ++i) {
			int u, v; scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		pair<int,int> p = dqry();
		int root = p.first, len = p.second;
		depth[root] = 0; from[root] = 0;
		dfs(root,edge);
		
		int l = len >> 1, r = -1;
		for (i = 1; i <= n; ++i) if (r < depth[i]) r = depth[i];
		if (r > len) r = len;
		
		int s = -1, f = -1;
		while (l <= r) {
			int m = (l + r) >> 1;
			p = dqry(m);
			if (p.second > len) r = m - 1;
			else l = m + 1,s=p.first;
		}
		int tgt = len - depth[s];
		int ban = s;
		while (depth[ban] > tgt && tgt > 0) ban = from[ban];
		f = dqry(tgt, ban).first;
		printf("! %d %d\n", s, f); fflush(stdout);
		scanf("%s",res);
	}
	return 0;
}
