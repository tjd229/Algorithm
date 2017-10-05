//category : graph
//idea rference : http://codeforces.com/contest/700/submission/30766662

#include <stdio.h>
#include <vector>
#define pb push_back
using namespace std;
int s, t;
struct Edge{
	int u, v, w;
	bool close;
	int to(int from){
		if (from == v) return u;
		return v;
	}
}edge[30001];
vector<int> edge_ix[1001];
int mat[1001][1001];
int from[1001];
bool visit[1001];
int ans[2];
int cnt;
int al;
int min(int a, int b){ return a < b ? a : b; }
bool dfs(int ix){
	if (ix == t) return true;
	if (visit[ix]) return false;
	visit[ix] = true;
	int to;
	for (int i = 0; i < edge_ix[ix].size(); i++){
		to = edge[edge_ix[ix][i]].to(ix);
		if (visit[to]) continue;
		from[to] = edge_ix[ix][i];
		if (dfs(to)) return true;
		from[to] = 0;
	}
	return false;
}
bool dfs(int ix, int from, int num[1001], int low[1001]){
	num[ix] = low[ix] = ++cnt;
	//if (ix == t) return true;
	int to;
	bool a = (ix == t);
	for (int i = 0; i < edge_ix[ix].size(); i++){
		if (edge[edge_ix[ix][i]].close) continue;
		to = edge[edge_ix[ix][i]].to(ix);
		if (low[to] == 0){
			bool res = dfs(to, ix, num, low);
			a |= res;
			low[ix] = min(low[to], low[ix]);
			if (res&&num[ix]<low[to] && mat[ix][to] == 1){
				if (al == 0 || edge[al].w > edge[edge_ix[ix][i]].w)
					al = edge_ix[ix][i];
				//return true;
			}
		}
		else if (to != from)  //->not AL, back edge
			low[ix] = min(num[to], low[ix]);
	}
	return a;
}
int main(){
	int i;
	int n, m;
	int town, road;
	int cost = 1e9 + 1e9 + 1;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		edge_ix[edge[i].u].pb(i);
		edge_ix[edge[i].v].pb(i);
		mat[edge[i].u][edge[i].v]++;
		mat[edge[i].v][edge[i].u]++;
	}
	if (!dfs(s)){
		printf("0\n0\n");
		return 0;
	}

	town = t;
	while (town != s){
		
		road = from[town];
		edge[road].close = true;
		mat[edge[road].u][edge[road].v]--;
		mat[edge[road].v][edge[road].u]--;

		int num[1001] = { 0 };
		int low[1001] = { 0 };
		cnt = 0;
		al = 0;
		dfs(s, 0, num, low);
		if (low[t] == 0){
			if (cost > edge[road].w){
				cost = edge[road].w;
				ans[0] = road;
				ans[1] = 0;
			}
		}
		else if (al != 0){
			if (cost > edge[road].w + edge[al].w){
				cost = edge[road].w + edge[al].w;
				ans[0] = road;
				ans[1] = al;
			}
		}

		edge[road].close = false;
		mat[edge[road].u][edge[road].v]++;
		mat[edge[road].v][edge[road].u]++;
		town = edge[road].to(town);

	}
	if (ans[0] == 0) printf("-1");
	else{
		m = 1 + (ans[1] != 0);
		printf("%d\n%d\n", cost, m);
		for (i = 0; i < m; i++) printf("%d ", ans[i]);
	}
	return 0;
}