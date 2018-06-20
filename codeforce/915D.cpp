//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[501], back[501];
int visit[501];
int from[501];
bool block[501];
int stamp;
int blocku, blockv;
void dfs(int ix,int stamp,vector<int> *edge,int *from ){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	
	for (int i = 0; i < edge[ix].size(); i++){
		int v = edge[ix][i];
		if (block[v]) continue;
		if (ix == blocku && v == blockv) continue;
		if (from != NULL && from[v] == 0) from[v] = ix;
		dfs(v, stamp, edge,from);
	}
	edge[0].push_back(ix);
}
int main(){
	int i,j,k;
	int n, m;
	int u, v;
	vector<int> scc;
	stamp++;
	for (scanf("%d%d", &n, &m), i = 0; i < m; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		back[v].push_back(u);
	}
	
	for (i = 1; i <= n; i++) dfs(i, stamp, edge,NULL);
	stamp++;
	bool find = false;
	while (edge[0].size()){
		dfs(edge[0].back(), stamp, back,NULL);
		
		if (back[0].size() > 1){
			if (find){
				printf("NO");
				return 0;
			}
			else{
				find = true;
				while (back[0].size()){
					scc.push_back(back[0].back());					
					back[0].pop_back();
				}
			}
		}
		back[0].clear();
		edge[0].pop_back();
	}
	if (scc.size() == 0){
		printf("YES");
		return 0;
	}
	for (i = 1; i <= n; i++) block[i] = true;
	for (i = 0; i < scc.size(); i++) block[scc[i]] = false;
	dfs(scc[0], ++stamp, edge, from);
	blockv = scc[0];
	do{
		blocku = from[blockv];
		stamp++;
		edge[0].clear();
		for (i = 0; i < scc.size(); i++) dfs(scc[i], stamp, edge,NULL);
		stamp++;
		blocku ^= blockv ^= blocku ^= blockv;
		int cnt = 0;
		while (edge[0].size() && cnt==0){
			back[0].clear();
			dfs(edge[0].back(), stamp, back,NULL);
			cnt += (back[0].size()>1);
			edge[0].pop_back();
		}
		if (cnt == 0){
			printf("YES");
			return 0;
		}
		blocku ^= blockv ^= blocku ^= blockv;
		blockv = blocku;
	} while (blockv != scc[0]);

	printf("NO");
	return 0;
}
