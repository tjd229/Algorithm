//category : graph

#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ll long long
using namespace std;
vector<pii > edge[100001];
ll dist[100001];
int hist[100001];
int ans[100001];
int e[100001];
void dfs(int ix,int from,int depth, ll tot){
	int bnd = lower_bound(dist, dist + depth+1, tot-e[ix])-dist;
	ans[ix] = hist[bnd];
	for (int i = 0; i < edge[ix].size(); i++){
		if (edge[ix][i].first == from) continue;
		dist[depth + 1] = dist[depth] + edge[ix][i].second;
		hist[depth + 1] = edge[ix][i].first;
		dfs(edge[ix][i].first, ix, depth + 1,tot+edge[ix][i].second);
	}
}
int main(){
	int i;
	int n;
	int a, b, c;
	for (scanf("%d", &n), i = 1; i <= n; i++){
		scanf("%d",e+i);
	}
	for (i = 1; i < n; i++){
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	hist[0] = 1;
	dfs(1, 0, 0,0);
	for (i = 1; i <= n; i++)
		printf("%d\n",ans[i]);
	return 0;
}
