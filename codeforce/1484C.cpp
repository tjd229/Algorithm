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
vector<int> f[100001];
int c[100001];
int h[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, m; cin >> n >> m;
		for (i = 1; i <= n; ++i) h[i] = 0;
		for (i = 1; i <= m; ++i) {
			int k; cin >> k;
			f[i].clear();
			while (k--) {
				int fr; cin >> fr;
				f[i].push_back(fr);
			}
			c[i] = f[i][0];
			++h[f[i][0]];
		}
		int d = (m>>1) + (m&1);
		if (m == 1) {
			cout << "YES\n" << c[1] << "\n";
			continue;
		}
		for (i = 1; i <= m; ++i) {
			if (h[c[i]]>d) {
				vector<pii> v;
				for (auto x : f[i]) {
					if (x == c[i]) continue;
					v.push_back({h[x],x});
				}
				if (v.empty()) continue;
				sort(v.begin(), v.end());
				int x = c[i], y = v[0].second;
				--h[x]; ++h[y];
				c[i] = y;
			}
		}
		bool flag = 1;
		for (i = 1; i <= n; ++i) {
			if (h[i] >d) flag = 0;
		}
 
 
		if (flag==0)
			cout << "NO\n";
		else {
			cout << "YES\n";
			for (i = 1; i <= m; ++i) cout << c[i]<<" ";
			cout << "\n";
		}
	}
 
	return 0;
}