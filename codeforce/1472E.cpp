//line sweeping
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int h[200001],w[200001];
int ans[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		vector<pii > v;
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d%d", h + i, w + i);
			v.push_back({ w[i],i }); v.push_back({h[i],i});
			ans[i] = -1;
		}
		sort(v.begin(), v.end());
		int mn = 2e9; int fr = -1; i = 0;
		for (auto p : v) {
			int piv = p.first;
			vector<int> vv;
			while (i < v.size() && v[i].first == piv) {
				int x = v[i].second;
				int y = h[x] == piv ? w[x] : h[x];
				if (y > mn) ans[x] = fr;
				vv.push_back(x);
				++i;
			}
			for (auto x : vv) {
				int y = h[x] == piv ? w[x] : h[x];
				if (mn > y) {
					mn = y; fr = x;
				}
			}
		}
		for (i = 1; i <= n; ++i) printf("%d ",ans[i]);
		puts("");
	}
 
	return 0;
}