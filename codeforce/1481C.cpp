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
int a[100001], b[100001], c[100001];
set<int> tgt[100001],same[100001];
int ans[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, m; cin >> n >> m;
		vector<int> hist;
		for (i = 1; i <= n; ++i) {
			same[i].clear();
			tgt[i].clear();
		}
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) cin >> b[i];
		for (i = 1; i <= m; ++i) cin >> c[i];
		for (i = 1; i <= n; ++i) {
			if (a[i] != b[i]) tgt[b[i]].insert(i);
			else same[b[i]].insert(i);
		}
		bool flag = 1;
		for (i = m; i > 0 && flag; --i) {
			if (tgt[c[i]].size()) {
				auto it = tgt[c[i]].begin();
				ans[i]= *it;
				hist.push_back(*it);
				tgt[c[i]].erase(it);
			}
			else {
				if (hist.size()) 
					ans[i] = hist.back();				
				else if (same[c[i]].size()) {
					auto it = same[c[i]].begin();
					ans[i] = *it;
					hist.push_back(*it);
				}
				else flag = 0;
			}
		}
		for (i = 1; i <= m && flag; ++i) 
			a[ans[i]] = c[i];
		for (i = 1; i <= n && flag; ++i) if (a[i] != b[i]) flag = 0;
		if (flag) {
			cout << "YES\n";
			for (i = 1; i <= m; ++i) cout << ans[i] << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}
 
	return 0;
}