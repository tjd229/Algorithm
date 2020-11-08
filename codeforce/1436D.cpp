//graph
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
vector<int> edge[200001];
ll a[200001];
int cnt_leaf[200001];
void dfs(int x) {
	cnt_leaf[x] = edge[x].empty();

	for (auto nxt : edge[x]) {
		dfs(nxt);
		cnt_leaf[x] += cnt_leaf[nxt];
		a[x] += a[nxt];
	}
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 2; i <= n; ++i) {
		int p; scanf("%d",&p);
		edge[p].push_back(i);
	}
	for (i = 1; i <= n; ++i) scanf("%I64d",a+i);
	dfs(1);
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		ll caught = a[i] / cnt_leaf[i] + (a[i] % cnt_leaf[i] > 0);
		if (ans < caught) ans = caught;
	}
	printf("%I64d",ans);
	return 0;
}