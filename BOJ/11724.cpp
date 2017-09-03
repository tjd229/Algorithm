//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edges[1001];
bool c[1001];
bool dfs(int n){
	if (c[n]) return false;
	c[n] = true;
	for (int i = 0; i < edges[n].size(); i++) dfs(edges[n][i]);
	return true;
}
int main(){
	int N, M;
	int i;
	int u, v;
	scanf("%d%d",&N,&M);
	while (M--){
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	v = 0;
	for (i = 1; i <= N; i++){
		if (dfs(i)) v++;
	}
	printf("%d",v);
}