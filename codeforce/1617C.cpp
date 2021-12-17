//greedy, math
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		set<int> st;
		vector<int> r;
		for (i = 1; i <= n; ++i) st.insert(i);
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (st.find(a[i]) == st.end()) {
				r.push_back(a[i]);
			}
			else {
				st.erase(a[i]);
			}
		}
		int ans = 0;
		sort(r.begin(), r.end());
		for (i = 0; i < r.size() && ans>=0; ++i) {
			auto it = st.begin();
			int x = *it;
			if (x+x+1 > r[i]) ans = -1;
			else ++ans;
			st.erase(it);
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}