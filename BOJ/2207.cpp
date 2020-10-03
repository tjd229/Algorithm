//graph, SCC, 2-SAT

#include <stdio.h>
#include <vector>
#define MAXN 10000
using namespace std;
int check[MAXN + MAXN + 1];
bool dfs(int x,bool stamp,vector<int> edge[MAXN+MAXN+1]){
	if (check[x] == stamp) return false;
	check[x] = stamp;
	for (int i = 0; i < edge[x].size(); i++) dfs(edge[x][i], stamp, edge);
	edge[0].push_back(x);
	return true;
}
void add_edge(int u,int v,vector<int> edge[MAXN+MAXN+1]){
	if (u < 0) u = MAXN - u;
	if (v < 0) v = MAXN - v;
	edge[u].push_back(v);
}
bool isContradic(vector<int> v){
	if (v.size() == 0) return false;
	int element[MAXN + 1] = { 0 };
	for (int i = 0; i < v.size(); i++){
		if (element[v[i] % MAXN] != 0) return true;
		element[v[i] % MAXN]++;
	}
	return false;
}
int main(){
	int i;
	int N, M;
	int x, y;
	vector<int> edge[MAXN+MAXN+1];
	vector<int> back[MAXN+MAXN+1];
	scanf("%d%d",&N,&M);
	for (i = 0; i < N; i++){
		scanf("%d%d", &x, &y);
		add_edge(-x, y, edge);
		add_edge(-y, x, edge);
		add_edge(y, -x, back);
		add_edge(x, -y, back);
	}
	for (i = 1; i <= M; i++) dfs(i, true, edge);
	for (i = 1; i <= M; i++) dfs(i+MAXN, true, edge);
	for (i = edge[0].size() - 1;i>=0; i--){
		back[0].clear();
		if (dfs(edge[0][i], false, back) && isContradic(back[0])){
            printf("OTL");
            return 0;
        }

	}
	printf("^_^");
	return 0;
}
