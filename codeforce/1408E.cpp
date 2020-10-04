//graph, MST, djs, greedy
#include <stdio.h>
#include <vector>
#include <numeric>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
int p[200001];
int a[100001], b[100001];
int u[200001], v[200001];
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
bool dsu(int a,int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	return 1;
}
int main() {
	int i,j,s, m, n;
	ll ans = 0;
	for (scanf("%d%d", &m, &n), i = 1; i <= m; ++i) scanf("%d",a+i);
	for (i = 1; i <= n; ++i) scanf("%d",b+i);
	int nm = n + m;
	iota(p + 1, p + 1 + nm, 1);
	int ix = 0;
	vector<pii > edge;
	for (i = 1; i <= m; ++i) {
		for (scanf("%d", &s), j = 0; j < s; ++j) {
			int x; scanf("%d",&x);
			u[ix] = i, v[ix] = m + x;
			int coin = a[i] + b[x]; ans += coin;
			edge.push_back({-coin,ix++});
		}
	}

	sort(edge.begin(), edge.end());
	for (auto p : edge) {
		int coin = p.first, ix = p.second;
		if (dsu(u[ix], v[ix])) 
			ans += coin;//ans-=|coin|
		
	}
	printf("%I64d",ans);
	return 0;
}