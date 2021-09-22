//dp, line sweeping, bs
#include <stdio.h>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define ll long long
using namespace std;
vector<ll> d[200001];
vector<pair<ll, ll> > g[200001];
int a[200001];
ll t1[200001], t2[200001];
int main() {
	int t; a[0] = -2e9;
	for (scanf("%d", &t); t--;) {
		int i, j, n, m;
		vector<pii > seg;
		for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		for (i = 0; i < m; ++i) {
			int l, r; scanf("%d%d", &l, &r);
			auto it = lower_bound(a + 1, a + 1 + n, l);
			if (it==a+1+n || *it > r) seg.push_back({ l,-r });
		}
		sort(seg.begin(), seg.end());
		int mx_ed = 2e9;
		while (seg.size()) {
			int l = seg.back().first, r = -seg.back().second;
			seg.pop_back();
			if (mx_ed > r) {
				mx_ed = r;
				int nei = lower_bound(a, a + 1 + n, l) - a - 1;
				//printf("%d:%d,%d\n", nei, l, r);
				g[nei].push_back({ l,r });
			}
		}
		sort(g[0].begin(), g[0].end());
		for (i = 1; i <= n; ++i) {
			g[i].push_back({ a[i],a[i] });
			sort(g[i].begin(), g[i].end());
			d[i].resize(g[i].size());
		}
		ll left = 0, right;
		if (g[0].size()) left = a[1] - g[0][0].second;
		for (i = 0; i < g[1].size(); ++i) {
			d[1][i] = 2 * min(left, g[1][i].first - a[1]) + max(left, g[1][i].first - a[1]);

		}
		for (i = 2; i <= n; ++i) {
			int sz = g[i - 1].size();
			if (sz == 1) {
				for (j = 0; j < g[i].size(); ++j)
					d[i][j] = d[i - 1][0] + g[i][j].first - a[i];
			}
			else {
				for (j = 0; j < sz; ++j) {
					t1[j] = d[i - 1][j];
					if (j + 1 < sz) t1[j] +=a[i]- g[i - 1][j + 1].second;
					
					if (j > 0) t1[j] = min(t1[j], t1[j - 1]);
				}
				for (j = sz - 1; j >= 0; --j) {
					t2[j] = d[i - 1][j];
					if (j + 1 < sz) t2[j] += 2 *(a[i]- g[i - 1][j + 1].second);
					if (j+1 < sz)
						t2[j] = min(t2[j], t2[j + 1]);
				}
				int k = sz - 1;
				for (j = 0; j < g[i].size(); ++j) {
					right = g[i][j].first - a[i];
					d[i][j] = d[i - 1].back() + right;
					while (k > 0 && a[i] - g[i - 1][k].second <= right) {
						--k;
					}
					d[i][j] = min(d[i][j], t1[k] + right * 2);
					d[i][j] = min(d[i][j], t2[k ]  + right);
				}

			}
		}
		printf("%I64d\n", d[n].back());
		/*for (i = 1; i <= n; ++i) {
			for (auto x : d[i])
				printf("%lld ", x);
			puts("");
		}*/
		for (i = 0; i <= n; ++i) {
			g[i].clear(); d[i].clear();
		}
	}

	return 0;
}