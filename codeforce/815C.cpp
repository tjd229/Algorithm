//category : graph, tdp

#include <stdio.h>
#include <memory.h>
#include <vector>
#define ll long long
using namespace std;
ll dp[5001][5001][2];
ll tmp[5001][2];
int family[5001];
vector<int> edge[5001];
ll min(ll a, ll b){
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? a : b;
}
void dfs(int ix){
	int i, j, k;
	int to;
	family[ix] = 1;
	//dp[ix][1][0] = cost[ix];
	//dp[ix][1][1] = cost[ix] - dc[ix];
	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		dfs(to);
		memset(tmp,0,sizeof(tmp));
		for (j = 0; j <= family[ix]; j++){
			for (k = 1; k <= family[to]; k++){
				if (j == 0){
					tmp[k][0] = min(dp[to][k][0], tmp[k][0]);
					continue;
				}
				//tmp[j + k][0] = min(tmp[j + k][0], dp[ix][j][0] + dp[to][k][1]);
				tmp[j + k][0] = min(tmp[j + k][0], dp[ix][j][0] + dp[to][k][0]);
				tmp[j + k][1] = min(tmp[j + k][1], dp[ix][j][1] + dp[to][k][1]);
				tmp[j + k][1] = min(tmp[j + k][1], dp[ix][j][1] + dp[to][k][0]);
			}
		}
		family[ix] += family[to];
		for (j = 1; j <= family[ix]; j++){
			dp[ix][j][0] = min(dp[ix][j][0], tmp[j][0]);
			dp[ix][j][1] = min(dp[ix][j][1], tmp[j][1]);
		}
	}
}
int main(){
	int n, b;
	int x;
	int i;
	scanf("%d%d",&n,&b);	
	scanf("%I64d%I64d", &dp[1][1][0], &dp[1][1][1]);
	dp[1][1][1] = dp[1][1][0] - dp[1][1][1];
	for (i = 2; i <= n; i++){
		scanf("%I64d%I64d%d", &dp[i][1][0], &dp[i][1][1], &x);
		edge[x].push_back(i);
		dp[i][1][1] = dp[i][1][0] - dp[i][1][1];
	}
	dfs(1);
	x = 0;
	for (i = 0; i <= family[1]; i++){
		if (min(dp[1][i][0], dp[1][i][1]) <= b) x = i;
	}
	printf("%d",x);
	return 0;
}