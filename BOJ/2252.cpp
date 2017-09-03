//category : graph, tp sort

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Graph{
	vector<int> edges[32001];
	int ins[32001];
	queue<int> q;
	void init(int n){
		for(int i=1;i<=n;i++)ins[i]=0;
	}
	void add_edge(int u,int v){
		edges[u].push_back(v);
		ins[v]++;
	}
	void tsort(int n){
		int i,j;
		for(i=1;i<=n;i++){
			if(ins[i]==0) q.push(i);
		}
		while(!q.empty()){
			i=q.front();
			q.pop();
			printf("%d ",i);
			for(j=0;j<edges[i].size();j++){
				ins[edges[i][j]]--;
				if(ins[edges[i][j]]==0) q.push(edges[i][j]);
			}
		}
	}
};
int main(){

	int N,M;
	int A,B;
	Graph g;
	scanf("%d%d",&N,&M);
	g.init(N);
	do{
		scanf("%d%d",&A,&B);
		g.add_edge(A,B);
	}while(--M);
	g.tsort(N);
	return 0;
}