//graph, dp
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int mod = 998244353;
ll f[200001];
vector<int> edge[200001];

ll dfs(int x,int from) {
	ll c = f[edge[x].size()];
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		c=c*dfs(nxt, x)%mod;
	}
	return c;
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i < n; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (f[0] = i = 1; i <= n; ++i) f[i] = f[i - 1] * i%mod;
	
	ll ans=dfs(1, 0)*n%mod;
	printf("%I64d",ans);
	return 0;
}