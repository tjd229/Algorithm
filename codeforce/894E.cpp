//category : graph, SCC

#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MUSHROOM = 14142;
int magic[MUSHROOM];
ll sum[MUSHROOM];
ll g[1000001];
ll d[1000001];
int visit[1000001];
int n, m;
vector<pii > back[1000001];
vector<pii > edge[1000001];
vector<pii > meta[1000001];
void dfs(int ix,int stamp,vector<pii > *edge){
	if (visit[ix] == stamp||visit[ix]>0) return; //visit>0 ->scc assigned, visit==0 -> non-access
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i].first,stamp,edge);
	edge[0].push_back({ix,0});
}
ll collect(int ix, int stamp, vector<pii > *edge){
	if (visit[ix] == stamp) return d[ix];
	visit[ix] = stamp;	
	ll res = 0;
	for (int i = 0; i < edge[ix].size(); i++){
		res = collect(edge[ix][i].first, stamp, edge) + edge[ix][i].second;
		if (d[ix] < res) d[ix] = res;
	}
	d[ix] += g[ix];
	return d[ix];

}
void make_group(int id, const vector<pii > &in,const vector<pii > *edge){
	
	int i, j;
	int curr,to,cost;
	int ix;
	ll tot = 0;
	for (i = 0; i < in.size(); i++){
		curr = in[i].first;
		for (j = 0; j < edge[curr].size(); j++){
			to = edge[curr][j].first;
			if (visit[to] != -2) continue;
			cost = edge[curr][j].second;
			ix = upper_bound(magic, magic + MUSHROOM, cost) - magic;
			tot += ix*(ll)cost-sum[ix-1];
		}
	}

	for (i = 0; i < in.size(); i++) visit[in[i].first] = id;
	g[id] = tot;
}
int main(){
	int i,j;
	int x, y, w;
	int s;
	int stamp = 0;
	for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
		scanf("%d%d%d",&x,&y,&w);
		edge[x].push_back({ y, w });
		back[y].push_back({ x, w });
	}
	scanf("%d",&s);
	
	for (i = 1; i < MUSHROOM; i++){
		magic[i] = magic[i - 1] + i;
		sum[i] = sum[i - 1] + magic[i];
	}
	for (i = 1; i <= n;i++)
		dfs(i, -1, edge);
	for (i = edge[0].size() - 1; i >= 0; i--){
		dfs(edge[0].back().first,-2,back);
		if (!back[0].empty()) make_group(++stamp,back[0],edge);
		back[0].clear();
		edge[0].pop_back();
	}
	for (i = 1; i <= n; i++){
		if (visit[i] < 0) continue;
		for (j = 0; j < edge[i].size(); j++){
			y = edge[i][j].first;
			if (visit[i] != visit[y]){
				meta[visit[i]].push_back({ visit[y], edge[i][j].second });
				
			}
		}
	}
	printf("%I64d",collect(visit[s],++stamp,meta));
	return 0;
}
