//category : tdp, graph

#include <stdio.h>
#include <vector>
#define ll long long
#define pb push_back
#define MIN(a,b) a<b? a:b
using namespace std;
int n, m;
int k, x;
vector<int> edge[(int)1e5 + 1];
int family[(int)1e5 + 1];
ll d[(int)1e5 + 1][11][3];
const int mod = 1e9 + 7;
void dfs(int ix,int from){
	int i, j, l;
	int to;
	d[ix][0][0] = k-1;
	d[ix][1][1] = 1;
	d[ix][0][2] = m-k;
	family[ix] = 1;

	for (i = 0; i < edge[ix].size(); i++){
		to = edge[ix][i];
		if (to == from) continue;
		dfs(to, ix);
		ll tmp[11][3] = { 0 };
		for (j = 0; j <= family[ix]; j++){
			for (l = 0; l <= family[to]; l++){
				if (j + l > x) break;
				tmp[j + l][0] += d[ix][j][0] * ((d[to][l][0] + d[to][l][2] + d[to][l][1])%mod);
				tmp[j + l][1] += d[ix][j][1] * (d[to][l][0]);
				tmp[j + l][2] += d[ix][j][2] * ((d[to][l][0] + d[to][l][2])%mod);
				if (tmp[j + l][0] >= mod)tmp[j + l][0] %= mod;
				if (tmp[j + l][1] >= mod)tmp[j + l][1] %= mod;
				if (tmp[j + l][2] >= mod)tmp[j + l][2] %= mod;
			}
		}
		family[ix] += family[to];
		family[ix] = MIN(family[ix], x);
		for (j = 0; j <= family[ix]; j++){
			d[ix][j][0] = tmp[j][0];
			d[ix][j][1] = tmp[j][1];
			d[ix][j][2] = tmp[j][2];
		}
	}
}
int main(){
	int i;
	int u, v;
	scanf("%d%d",&n,&m);
	for (i = 1; i < n; i++){
		scanf("%d%d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	scanf("%d%d",&k,&x);
	dfs(1, 0);
	ll ans = 0;
	for (i = 0; i <= x; i++){
		ans += d[1][i][0];
		if (ans >= mod) ans -= mod;
		ans += d[1][i][1];
		if (ans >= mod) ans -= mod;
		ans += d[1][i][2];
		if (ans >= mod) ans -= mod;
	}
	printf("%I64d",ans);
	return 0;
}