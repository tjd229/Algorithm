//category : graph, tdp

#include <stdio.h>
#include <vector>
using namespace std;
int V, Q, K;
int d[1001 * 3][10];
int c[1001 * 3];
bool visit[1001 * 3];
vector<int> edge[1001*3];
void add_edge(int u,int v){
	u *= 3;
	v *= 3;
	edge[u].push_back(v);
	edge[u].push_back(v+1);
	edge[u + 1].push_back(v);
	edge[u + 1].push_back(v+2);
	edge[u + 2].push_back(v+1);
}
void dfs(int ix,int from){
	if (visit[ix]) return;
	visit[ix] = true;
	int i, j,k;
	int to;
	int tmp[10] = { 0 };
	d[ix][c[ix]%K] = 1;
	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to/3 == from/3) continue;
		dfs(to,ix);
		//printf("%d->%d\n",ix,to);
		for (j = 0; j < K; j++){
			for (k = 0; k < K; k++){
				tmp[(j + k) % K] += d[to][k] * d[ix][j];
				if (tmp[(j + k) % K] >= Q)
					tmp[(j + k) % K] %= Q;
				//printf("%d|%d:%d\n", ix, j + k, tmp[(j + k) % K]);
			}
		}
		if (i == edge[ix].size() - 1 || ((to / 3 != edge[ix][i + 1] / 3))){
			//printf("-!%d->%d\n", ix, to);
			for (j = 0; j < K; j++){
				d[ix][j] = tmp[j];
				tmp[j] = 0;
			}
		}
	}
}
int main(){
	int i;
	int a, b;
	for (scanf("%d%d%d", &V, &Q, &K), i = 1; i < V; i++){
		scanf("%d%d",&a,&b);
		add_edge(a, b);
		add_edge(b, a);
	}
	for (i = 1,a=3; i <= V; i++,a+=3){		
		scanf("%d%d%d",c+a,c+a+1,c+a+2);
	}
	dfs(3,0);
	dfs(4,0);
	dfs(5,0);
	for (i = 3; i < 12; i++){
		for (int j = 0; j < K; j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	printf("%d",(d[3][0]+d[4][0]+d[5][0])%Q);
	return 0;
}
