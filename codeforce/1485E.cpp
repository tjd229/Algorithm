//graph, dp
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#define pii pair<int,int>
#define ll long long
using namespace std;
vector<int> edge[200001];
vector<pii > pt[200001];
int depth[200001];
ll d[200001];
int a[200001],v[200001];
void dfs(int x) {
	for (auto nxt : edge[x]) {
		depth[nxt] = depth[x] + 1;
		dfs(nxt);
	}
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			edge[i].clear();
			pt[i].clear();
			d[i] = 0;
		}
		for (i = 2; i <= n; ++i) {
			scanf("%d",v+i);
			edge[v[i]].push_back(i);
		}
		depth[1] = 1;
		dfs(1);
		for (i = 2; i <= n; ++i) {
			scanf("%d",a+i);
			pt[depth[i]].push_back({a[i],i});
		}
		pt[1].push_back({0,1});
		for (i = 1; i <= n; ++i)
			sort(pt[i].begin(), pt[i].end());
		int lev = 2;
		while (pt[lev].size()) {
			multiset < ll > l, r;
			for (auto p : pt[lev]) {
				int x = p.second;
				r.insert(d[v[x]]+a[x]);
			}
			for (auto p : pt[lev]) {
				int x = p.second;
				auto it = r.lower_bound(d[v[x]]+a[x]);
				r.erase(it);

				if (r.size()) {
					auto mx = prev(r.end());
					d[x] = max(d[x], *mx - a[x]);
					int rightmost = pt[lev].back().first;
					d[x] = max(d[x], d[v[x]] + rightmost - a[x]);
				}
				if (l.size()) {
					auto mx = prev(l.end());
					d[x] = max(d[x], a[x] + *mx);
					int leftmost = pt[lev][0].first;
					d[x] = max(d[x], d[v[x]] + a[x] - leftmost);
				}
				l.insert({d[v[x]]-a[x]});
			}
			++lev;
		}

		ll ans = 0;
		for (i = 1; i <= n; ++i) {
			if (ans < d[i]) ans = d[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}