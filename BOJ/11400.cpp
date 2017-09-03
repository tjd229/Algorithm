//category : graph



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> edges[100001];
vector<pair<int, int> > ans;
int num[100001], low[100001];
int cnt;
int min(int a, int b){ return a < b ? a : b; }
int dfs(int n,int from){
	num[n] = low[n] = ++cnt;
	for (int i = 0; i < edges[n].size(); i++){
		if (low[edges[n][i]] == 0){
			
			low[n] = min(dfs(edges[n][i], n), low[n]);
			if (num[n] < low[edges[n][i]]){
				if (n < edges[n][i]) ans.push_back(make_pair(n, edges[n][i]));
				else ans.push_back(make_pair(edges[n][i],n));
			}			
		}
		else if (edges[n][i] != from)
			low[n] = min(num[edges[n][i]], low[n]);
	}
	return low[n];
}

int main(){
	int V, E;
	int A, B;
	int i;
	scanf("%d%d",&V,&E);
	for (i = 0; i < E; i++){
		scanf("%d%d", &A, &B);
		edges[A].push_back(B);
		edges[B].push_back(A);
	}
	dfs(1, 0);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());

	for (i = 0; i < ans.size(); i++)
		printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}