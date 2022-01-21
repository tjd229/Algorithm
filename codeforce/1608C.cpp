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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
int b[100001];
int ans[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i],ans[i]=0;
		for (i = 1; i <= n; ++i)cin >> b[i];
		if (1 == n) cout << "1\n";
		else {
			vector<pii > v;
			set<pii > st;
			for (i = 1; i <= n; ++i) v.push_back({ a[i],i });
			sort(v.begin(), v.end());
			for (i = 0; i < n-1; ++i) {
				int ix = v[i].second;
				st.insert({b[ix],i});
			}
			int mn = b[v[i].second];
			int l = n - 1,r=n;
			while (st.size()) {
				while (st.lower_bound({ mn,0 }) != st.end()) {
					auto it = st.lower_bound({ mn,0 });
					l = min(l, it->second);
					st.erase(it);
				}
				if (l == r) break;
				for (i = l; i < r; ++i) {
					int ix = v[i].second;
					mn = min(mn, b[ix]);
				}
				r = l;
			}
			for (i = l; i < n; ++i) {
				int ix = v[i].second;
				ans[ix] = 1;
			}
 
			for (i = 1; i <= n; ++i) cout << ans[i];
			cout << "\n";
		}
	}
 
 
	return 0;
}