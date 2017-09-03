//category : graph, dijkstra

#include <stdio.h>
#include <queue>
#include <vector>
#define INF 3000000
using namespace std;
int d[20001];
vector< pair<int,int> > edge[20001];
int main(){
	int V, E, K;
	int u, v, w;
	int i;
	scanf("%d%d",&V,&E);
	for (i = 1; i <= V; i++){
		d[i] = INF;
	}
	scanf("%d",&K);
	d[K] = 0;
	for (i = 0; i < E; i++){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(make_pair(w,v));
	}
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,K));
	while (!q.empty()){
		u = q.top().second;
		q.pop();
		for (i = 0; i < edge[u].size(); i++){
			v = edge[u][i].second;
			w = edge[u][i].first;
			if (d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push(make_pair(-d[v], v));
			}
		}
	}
	for (i = 1; i <= V; i++){
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n",d[i]);
	}
	return 0;
}

