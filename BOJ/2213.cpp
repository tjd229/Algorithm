//graph, dp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edge[10001],S;
vector<int> st[10001];//stat=0 case
int d[10001][2];
bool mark[10001];
void dfs(int x,int from) {
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		dfs(nxt, x);
		if (d[nxt][1] > d[nxt][0]) {
			st[x].push_back(nxt);
			d[x][0] += d[nxt][1];
		}
		else {
			d[x][0] += d[nxt][0];
		}
		d[x][1] += d[nxt][0];
	}
}
void crawl(int x,int from) {
	if (mark[x]) S.push_back(x);
	else {
		for (auto nxt : st[x]) mark[nxt] = 1;
	}
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		crawl(nxt, x);
	}
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",d[i]+1);
	for (i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0);
	int sz=d[1][0];
	if (d[1][0] < d[1][1]) sz = d[1][1], mark[1] = 1;
	crawl(1, 0);
	sort(S.begin(), S.end());
	printf("%d\n",sz);
	for (auto x : S) printf("%d ",x);
	return 0;
}