//category : graph, Bellman Ford

#include <stdio.h>
#include <vector>
#define MAXVAL 10000000
using namespace std;
int d[501];
struct Edge{
	int u,v,c;
};
Edge e[6000];
int main(){
	int N,M;
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	}
	for(i=2;i<=N;i++){ 
		d[i]=MAXVAL;
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(d[e[j].u]!=MAXVAL&&d[e[j].v]>d[e[j].u]+e[j].c){
				if(i==N-1) return printf("-1");
				d[e[j].v]=d[e[j].u]+e[j].c;
			}
		}
	}
	for(i=2;i<=N;i++){ 
		if(d[i]==MAXVAL) d[i]=-1;
		printf("%d\n",d[i]);
	}

}
