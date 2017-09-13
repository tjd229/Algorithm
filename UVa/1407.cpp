//Caves
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4153
//category : tdp, graph
#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
int family[500];
int dp[500][501][2] = { 0 };
int min(int a,int b){
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? a : b;
}
void dfs(int ix,vector<pair<int,int> > edge[500]){
	int i, j, k;
	int to,d;
	family[ix] = 1;
	for (i = 0; i < edge[ix].size(); i++){		
		to = edge[ix][i].first;
		d = edge[ix][i].second;
		dfs(to, edge);
		int tmp[501][2] = { 0 };
		for (j = 1; j <= family[ix]; j++){
			for (k = 1; k <= family[to]; k++){
				//tmp[j + k] = dp[ix][j] + dp[to][k] + edge[ix][i].second;
				tmp[j + k][0] = min(tmp[j+k][0],dp[ix][j][1] + dp[to][k][0] + d);
				tmp[j + k][0] = min(tmp[j+k][0],dp[ix][j][0] + dp[to][k][1] + d+d);
				tmp[j + k][1] = min(tmp[j+k][1],dp[ix][j][1] + dp[to][k][1] + d + d);
			}
		}
		family[ix] += family[to];
		for (j = 2; j <= family[ix]; j++){
			dp[ix][j][0] = min(dp[ix][j][0], tmp[j][0]);
			dp[ix][j][1] = min(dp[ix][j][1], tmp[j][1]);
		}

	}
}
int main(){
	int n;
	int i,j,k;
	int d;
	int q;
	int x;
	int tc = 1;
	int ans;
	while (scanf("%d", &n)){
		if (n == 0) break;
		vector<pair<int, int> > edge[500];
		memset(dp,0,sizeof(dp));
		for (k = 0; k< n - 1; k++){
			scanf("%d%d%d",&i,&j,&d);
			edge[j].push_back(make_pair(i, d));
		}
		dfs(0,edge);
		printf("Case %d:\n",tc++);
		scanf("%d",&q);
		while (q--){
			scanf("%d",&x);
			ans = 0;
			for (i = 1; i <= n; i++){
				if (dp[0][i][0]>x) break;
				ans = i;
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}