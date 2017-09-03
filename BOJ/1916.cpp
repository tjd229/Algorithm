//category : graph, dijkstra

#include <stdio.h>
#include <vector>
#include <queue>
#define MAXVAL 200000000
#define MIN(a,b) (a)<(b)? (a):(b)
using namespace std;
int d[1001];
int visit[1001];
vector<pair<int,int> > edges[1001];
int main(){
	int n,m;
	int u,v,c;
	int s,e;
	int i;
	priority_queue<pair<int,int> > q;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&c);
		edges[u].push_back(make_pair(c,v));
		//edges[v].push_back(make_pair(c,u));
		//
	}
	for(i=1;i<=n;i++) d[i]=MAXVAL;
	scanf("%d%d",&s,&e);
	//
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		u=q.top().second;
		q.pop();
		if(visit[u]) continue;
		visit[u]=1;
		for(i=0;i<edges[u].size();i++){
			c=edges[u][i].first;
			v=edges[u][i].second;
			d[v]=MIN(d[v],d[u]+c);
			if(!visit[v]) q.push(make_pair(-d[v],v));
		}
	}
	//
	
		printf("%d ",d[e]);


	return 0;

}
