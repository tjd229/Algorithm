//category : graph, MST

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Graph{
	bool check[1001];
	vector<pair<int,int> > edges[1001];
	void init(int n){
		do{
			check[n]=false;
		}while(--n);
	}
	void add_edge(int u,int v,int c){
		edges[u].push_back(make_pair(-c,v));
	}
	int prim(int s){
		priority_queue<pair<int,int> >q;
		int i;
		int cost=0;
		pair<int,int> p;
		check[s]=true;
		for(i=0;i<edges[s].size();i++) q.push(edges[s][i]);
		while(!q.empty()){
			p=q.top();
			q.pop();
			if(!check[p.second]){
				for(i=0;i<edges[p.second].size();i++){
					if(!check[edges[p.second][i].second])
						q.push(edges[p.second][i]);
				}
				cost+=(-p.first);
				check[p.second]=true;
			}
		}
		return cost;
	}
};
int main(){

	int N,M;
	int a,b,c;
	Graph g;
	scanf("%d",&N);
	g.init(N);
	for(scanf("%d",&M);M--;){
		scanf("%d%d%d",&a,&b,&c);
		g.add_edge(a,b,c);
		g.add_edge(b,a,c);
	}
	printf("%d",g.prim(1));
	
	return 0;
}
