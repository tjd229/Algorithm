//category : graph, SCC, dp

#include <stdio.h>
#include <vector>
using namespace std;
bool rest[500001];
bool scc_rest[500001];
bool visit[500001];
int atm[500001];
int total[500001];
int d[500001];
vector<int> edge[500001];
vector<int> back[500001];
vector<int> scc[500001];
bool dfs(int x, bool stamp, vector<int> v[500001]){
	if (stamp == visit[x]) return false;
	visit[x] = stamp;
	for (int i = 0; i < v[x].size(); i++) dfs(v[x][i], stamp, v);
	v[0].push_back(x);
	return true;
}
int dfs(int x,int id[500001]){
	if (visit[x]) return d[x];
	visit[x] = true;
	int max = 0;
	int t;
	for (int i = 0; i < scc[x].size(); i++){
		t = dfs(id[scc[x][i]], id);
		if (max < t) max = t;
	}
	if (max == 0 && !scc_rest[x]) d[x] = 0;
	else d[x] = max + total[x];
	return d[x];
}
int main(){
	int i, j, k;
	int N, M;
	int S, P;
	int u, v;
	scanf("%d%d",&N,&M);
	for (i = 0; i < M; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		back[v].push_back(u);
	}
	for (i = 1; i <= N; i++) scanf("%d", &atm[i]);
	scanf("%d%d", &S, &P);
	for (i = 0; i < P; i++){
		scanf("%d", &u);
		rest[u] = true;
	}
	u = 1;
	for (i = 1; i <= N; i++) dfs(i,true,edge);
	for (i = edge[0].size() - 1; i >= 0; i--){
		back[0].clear();
		if (dfs(edge[0][i], false, back)){
			for (j = 0; j < back[0].size(); j++){
				total[u] += atm[back[0][j]];
				for (k = 0; k < edge[back[0][j]].size(); k++)
					scc[u].push_back(edge[back[0][j]][k]);
				atm[back[0][j]] = u;	//atm=id
				if (back[0][j] == S) v = u;
				if (rest[back[0][j]]) scc_rest[u] = true;
			}
			u++;
		}
	}
	printf("%d",dfs(v,atm));
	return 0;
}