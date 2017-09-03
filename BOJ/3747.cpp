//category : graph, SCC, 2-SAT

#include <stdio.h>
#include <vector>
#define MAX_N 1000
using namespace std;
int N, M;
int visit[MAX_N+MAX_N+1];
int turn;
void add_edge(int u,int v,vector<int> edge[MAX_N+MAX_N+1]){
	if (u < 0) u = MAX_N - u;
	if (v < 0) v = MAX_N - v;
	edge[u].push_back(v);
}
void dfs(int n, int stamp, vector<int> edge[MAX_N + MAX_N + 1]){
	if (visit[n] == stamp) return;
	visit[n] = stamp;
	for (int i = 0; i < edge[n].size(); i++) dfs(edge[n][i], stamp, edge);
	edge[0].push_back(n);
}
bool check(vector<int> v){
	if (v.size() == 0) return true;
	int tf[MAX_N+1] = { 0 };
	for (int i = 0; i < v.size(); i++){
		if (tf[v[i] % MAX_N] != 0) return false;
		tf[v[i] % MAX_N]++;
	}
	return true;
}
int main(){

	int i, j;
	int k;
	bool flag;
	while (scanf("%d%d", &N, &M) != EOF){
		vector<int> edge[MAX_N + MAX_N + 1];
		vector<int> back[MAX_N + MAX_N + 1];
		turn++;
		flag = true;
		for (k = 0; k < M; k++){
			scanf("%d%d", &i, &j);
			add_edge(-i, j, edge);
			add_edge(-j, i, edge);
			add_edge(j, -i, back);
			add_edge(i, -j, back);
			
		}
		for (k = 1; k <= N; k++) dfs(k, turn, edge);
		for (k = 1; k <= N; k++) dfs(MAX_N+k, turn, edge);
		for (k = edge[0].size()-1; k >= 0; k--){
			dfs(edge[0][k], -turn, back);
			if (!check(back[0])) flag = false;
			back[0].clear();
		}
		printf("%d\n",flag);
	}


}
