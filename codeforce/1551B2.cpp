//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001],c[200001];
vector<int> pos[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		vector<pii > v;
		vector<pii > clr;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) pos[i].clear();
		for (i = 1; i <= n; ++i) {
			pos[a[i]].push_back(i);
			c[i] = 0;
		}
		for (i = 1; i <= n; ++i) {
			if (pos[i].empty()) continue;
			v.push_back({pos[i].size(),i});
		}
		sort(v.begin(), v.end());
		int color = 0;
		while (v.size()) {
			int cnt = v.back().first;
			int e = v.back().second;
			//printf("%d,%d\n",cnt,e);
			v.pop_back();
			if (cnt >= k) {
				cnt = k;
			}
			
			while (cnt--) {
				clr.push_back({ pos[e].back(),color + 1 });
				pos[e].pop_back();
				color = (color + 1) % k;
			}
			//printf("%d\n",clr.size());
		}
		for (i = 0; i + k <= clr.size(); i+=k) {
			for (int j = 0; j < k; ++j) {
				int pos = clr[i+j].first;
				int color = clr[i+j].second;
				//printf("%d::%d(%d)\n",pos,color,i+j);
				c[pos] = color;
			}
		}
		for (i = 1; i <= n; ++i) cout << c[i] << " ";
		cout << "\n";
	}
 
 
	return 0;
}