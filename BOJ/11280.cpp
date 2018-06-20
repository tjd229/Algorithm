//category : graph, SCC, 2-SAT

#include <stdio.h>
#include <vector>
#define MAXVAL 10000
using namespace std;
bool visit[MAXVAL + MAXVAL + 1];
void add_edge(int u, int v, vector<int> edges[MAXVAL + MAXVAL + 1]){
	if (u < 0) u = -u + MAXVAL;
	if (v < 0) v = -v + MAXVAL;
	edges[u].push_back(v);
}
void dfs(int n, bool stamp, vector<int> edges[MAXVAL + MAXVAL + 1]){
	int i;
	if (visit[n] == stamp) return;
	visit[n] = stamp;
	for (i = 0; i < edges[n].size(); i++) dfs(edges[n][i], stamp, edges);
	edges[0].push_back(n);
}
bool check(vector<int> v){
	if (v.size() == 0) return true;
	int check[MAXVAL + 1] = { 0 };

	int i;
	for (i = 0; i < v.size(); i++){
		if (check[v[i] % MAXVAL] != 0) return false;
		check[v[i] % MAXVAL]++;
	}
	return true;
}
int main(){
	int N, M;
	int i;
	int u, v;
	vector<int> edges[MAXVAL + MAXVAL + 1];
	vector<int> back[MAXVAL + MAXVAL + 1];
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d%d", &u, &v);
		add_edge(-u, v, edges);
		add_edge(-v, u, edges);
		add_edge(v, -u, back);
		add_edge(u, -v, back);
	}
	for (i = 1; i <= N; i++) dfs(i, true, edges);
	for (i = 1 + MAXVAL; i <= N + MAXVAL; i++) dfs(i, true, edges);


	for (i = edges[0].size() - 1; i >= 0; i--){
		dfs(edges[0][i], false, back);
		if (!check(back[0])){
            printf("0");
          return 0;  
        } 
		back[0].clear();
	}
	printf("1");

	return 0;
}
