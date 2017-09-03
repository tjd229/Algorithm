//category : graph, MST

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > edges[10001];
bool c[10001];
int main(){
	int V,E;
	int A,B,C;
	int i,j;
	int cost=0;
	priority_queue<pair<int,int> > q;
	scanf("%d%d",&V,&E);
	for(i=0;i<E;i++){
		scanf("%d%d%d",&A,&B,&C);
		edges[A].push_back(make_pair(-C,B));
		edges[B].push_back(make_pair(-C,A));
	}
	for(i=0;i<edges[1].size();i++){
			q.push(edges[1][i]);
	}
	c[1]=true;
	E=0;
	while(V>E+1){
		B=q.top().second;
		C=-q.top().first;
		q.pop();
		if(c[B]) continue;
		c[B]=true;
		E++;
		cost+=C;
		for(i=0;i<edges[B].size();i++){
			q.push(edges[B][i]);
		}
	}
	printf("%d",cost);


	return 0;

}