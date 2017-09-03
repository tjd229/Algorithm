//category : graph

#include <stdio.h>
#include <vector>
using namespace std;
#define MIN(a,b) (a)>(b)? (b):(a);
vector<int> edges[10001];
int num[10001], low[10001];
int sum;
int dfs(int ix,int from,int &cnt){
	if (num[ix] != 0) return low[ix];
	num[ix] = low[ix] = cnt++;
	bool flag = false;
	int c = 0;
	for (int i = 0; i < edges[ix].size(); i++){
		if (num[edges[ix][i]] == 0){
			low[ix]=MIN(dfs(edges[ix][i],ix,cnt),low[ix]);
			if (num[ix] <= low[edges[ix][i]]) flag = true;
			c++;
		}
		else if (edges[ix][i] != from){
			low[ix] = MIN(num[edges[ix][i]], low[ix]);
		}
	}
	if (from == 0 && c>1) num[ix] = -num[ix], sum++;
	if (from!=0&&flag) num[ix] = -num[ix],sum++;
	return low[ix];

}
int main(){
	int V, E;
	int A, B;
	int i;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; i++){
		scanf("%d%d", &A, &B);
		edges[B].push_back(A);
		edges[A].push_back(B);
	}
	A = 1;
	for (i = 1; i <= V; i++) dfs(i, 0, A);
	printf("%d\n",sum);
	for (i = 1; i <= V; i++) if (num[i] < 0) printf("%d ",i);
	return 0;
}