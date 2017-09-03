//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
int graph[1001][1001];
int degree[1001];
int ix[1001];
int N,M;
vector<int> ans;
int dfs(int n){
	int i;
	int m=0;
	//for(i=1;i<=N;i++){
	for(;ix[n]<=N;){
		i=ix[n];
		if(graph[n][i]==0)
			ix[n]++;
		if(graph[n][i]>0){
			graph[n][i]--;
			graph[i][n]--;
			
			m+=dfs(i)+1;
		}
	}
	ans.push_back(n);
	return m;
}
int main(){

	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf("%d",&graph[i][j]);
			if(graph[i][j]>0){
				degree[i]+=graph[i][j];
				M+=graph[i][j];
			}
		}
		ix[i]=1;
	}
	//M=20;
	M/=2;
	for(i=1;i<=N;i++){
		if(degree[i]%2!=0){
			printf("-1");
			return -1;
		}
	}
	if(dfs(1)!=M){
		printf("-1");
		return -1;
	}
	//dfs(1);
	for(i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	//visit, dfs or bfs

	return 0;

}