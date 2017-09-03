//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int time = 0;
	int indegree = 0;
	int outdegree = 0;
	vector<pair<int,int> > edges,reverse;
	void propagate(int t){
		if (time < t) time = t;
	}
	
};
Node cities[10001];
int main(){
	int n, m;
	int i;
	int u, v, c;
	queue<int> q;
	pair<int, int> p;
	scanf("%d%d",&n,&m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d",&u,&v,&c);
		cities[u].edges.push_back(make_pair(v, c));
		cities[v].reverse.push_back(make_pair(u, c));
		cities[u].outdegree++;
		cities[v].indegree++;
	}
	scanf("%d%d",&u,&c);
	q.push(u);
	while (!q.empty()){
		u = q.front();
		q.pop();
		for (i = 0; i < cities[u].edges.size(); i++){
			p = cities[u].edges[i];
			v = p.first;
			cities[v].propagate(p.second+cities[u].time);
			cities[v].indegree--;
			if (cities[v].indegree == 0) q.push(v);
		}
	}
	printf("%d\n",cities[c].time);
	q.push(c);
	cities[c].indegree = 1;
	c = 0;
	while (!q.empty()){
		u = q.front();
		q.pop();
		for (i = 0; i < cities[u].reverse.size(); i++){
			p = cities[u].reverse[i];
			v = p.first;
			if (cities[u].indegree != 0 && cities[v].time + p.second == cities[u].time){
				c++;
				cities[v].indegree = 1;	
			}
			else if (cities[v].indegree != 1) cities[v].indegree = 0;
			cities[v].outdegree--;
			if (cities[v].outdegree == 0) q.push(v);
		}
	}
	printf("%d",c);
	return 0;
}
