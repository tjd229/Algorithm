//category : graph, dijkstra

#include <stdio.h>
#include <vector>
#include <queue>
#define MAXVAL 20000
using namespace std;
vector<pair<int,int> > edge[10000];
int stat[10000];
int d[10000];
bool visit[10000];
int N, M;
int NM;
int to1D(int x,int y){
	return x + y*N;
}
void dijkstra(int s){
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0,s));
	d[s] = 0;
	int u, v, w;
	int i;
	while (!q.empty()){
		u = q.top().second;
		q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i].first;
			w = edge[u][i].second;
			if (d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push(make_pair(-d[v],v));
			}
		}
	}
	
}
int main(){
	int i,j;
	int u, v;
	scanf("%d%d",&N,&M);
	NM = N*M;
	for (i = 0; i < NM; i++) scanf("%1d",stat+i),d[i]=MAXVAL;
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			u = to1D(j, i);
			v = to1D(j + 1, i);
			if (j < N - 1) edge[u].push_back(make_pair(v, stat[v]));
			v = to1D(j - 1, i);
			if (j >0) edge[u].push_back(make_pair(v, stat[v]));
			v = to1D(j, i + 1);
			if (i < M - 1) edge[u].push_back(make_pair(v, stat[v]));
			v = to1D(j, i - 1);
			if (i > 0) edge[u].push_back(make_pair(v, stat[v]));
		}
	}
	dijkstra(0);
	printf("%d",d[NM-1]);
	return 0;
}