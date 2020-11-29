#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int d[300001];
vector<int> to[300001];
int main() {
	int i, n;
	vector<pii > v[2];
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		int h; scanf("%d",&h);
		v[0].push_back({ h,i });v[1].push_back({-h,i});
		to[i].push_back(1 + i);
		d[i] = -1;
	}
	to[n].clear(); d[1] = 0;
	sort(v[0].begin(), v[0].end()); sort(v[1].begin(), v[1].end());
	for (int d = 0; d < 2; ++d) {
		set<int> fw, bk;
		for (auto p : v[d]) {
			auto it = fw.lower_bound(p.second);
			if (it != fw.begin())
				to[*prev(it)].push_back(p.second);
			fw.insert(p.second);
		}
		for (i = v[d].size() - 1; i >= 0; --i) {
			auto it = bk.lower_bound(v[d][i].second);
			if (it != bk.end())
				to[v[d][i].second].push_back(*it);
			bk.insert(v[d][i].second);
		}
	}
	for (i = 1; i <= n; ++i) {
		for (auto nxt : to[i]) {
			
			if (d[nxt] < 0 || d[nxt] > d[i] + 1)
				d[nxt] = d[i] + 1;
		}
	}
	printf("%d",d[n]);
 
 
	return 0;
}