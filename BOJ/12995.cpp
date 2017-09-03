//category : graph, tdp

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> edge[51];
int family[51];
long long d[51][51];
const int mod = 1000000007;
void dfs(int ix,int from,int root){
	int i,j,k;
	int to;
	family[ix] = 1;
	d[ix][1] = 1;
	
	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to == from) continue;
		dfs(to, ix, root);
		long long tmp[51] = { 0 };
		for (j = 1; j <= family[ix]; j++){
			for (k = 1; k <= family[to]; k++){
				tmp[j + k] += d[ix][j] * d[to][k];
				if (tmp[j + k] >= mod) tmp[j + k] %= mod;
			}
		}
		family[ix] += family[to];
		for (j = 2; j <= family[ix]; j++){
			d[ix][j] += tmp[j];
			if (d[ix][j] >= mod) d[ix][j] %= mod;
		}
	}
}
int main(){
	int i;
	int N, K;
	int u, v;
	long long ans = 0;
	scanf("%d%d",&N,&K);
	for (i = 0; i < N-1; i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1, 0, 1);

	for (i = 1; i <= N; i++){
		ans += d[i][K];
		if (ans >= mod) ans %= mod;		
	}
	
	printf("%lld",ans);
	return 0;
}