//category : graph, tdp

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[151];
int dp[151][151];
int family[151];
int n, m;
int min(int a, int b){
	return a < b ? a : b;
}
void dfs(int ix,int from){
	family[ix] = 1;
	int to;
	int i, j, k;
	dp[ix][1] = 0;
	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to== from) continue;
		dfs(to, ix);
		int tmp[151];
		for (j = 1; j <= family[to] + family[ix]; j++) tmp[j] = n;
		for (j = 1; j <= family[ix]; j++){
			tmp[j] = min(tmp[j], dp[ix][j] + 1);//k=0
			for (k = 1; k <= family[to]; k++){
				tmp[j + k] = min(tmp[j+k],dp[ix][j] + dp[to][k]);
			}
		}
		family[ix] += family[to];
		for (j = 1; j <= family[ix]; j++){
			//dp[ix][j] = min(tmp[j],dp[ix][j]);
			dp[ix][j] = tmp[j];
		}
	}
}
int main(){
	int i,j;
	int A, B;
	scanf("%d%d",&n,&m);
	for (i = 0; i < n-1; i++){
		scanf("%d%d",&A,&B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++)
			dp[i][j] = n;
	}

	dfs(1, 0);
	int ans = n;
	for (i = 1; i <= n; i++){
		ans = min(ans, dp[i][m] + (i>1));
	}
	if (ans == n) ans = -1;
	printf("%d",ans);

	return 0;
}
