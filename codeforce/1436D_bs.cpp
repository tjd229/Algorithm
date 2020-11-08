//bs, graph, greedy
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const ll inf = 1e18;
vector<int> edge[200001];
int a[200001];
ll dfs(int x, ll bnd) {
	if (edge[x].empty()) {
		if (bnd < a[x]) return -1;
		return bnd-a[x];
	}
	ll cap = 0;
	for (auto nxt : edge[x]) {
		ll c = dfs(nxt, bnd);
		if (c < 0) return -1;
		if (inf - c < cap) return inf;
		cap += c;
	}
	if (cap < a[x]) return -1;
	return cap-a[x];
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 2; i <= n; ++i) {
		int p; scanf("%d",&p);
		edge[p].push_back(i);
	}
	ll r = 0,l=0;
	for (i = 1; i <= n; ++i) scanf("%d", a + i),r+=a[i];
	while (l <= r) {
		ll m = (l + r) >> 1;
		ll cap = dfs(1, m);
		//printf("%lld,%lld\n",cap,m);
		if (cap < 0) l = m + 1;
		else r = m - 1;
	}
	printf("%I64d",r+1);
	return 0;
}