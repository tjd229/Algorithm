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
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int i, n; cin >> n;
		map<int, int> mp;
		vector<int> v;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			++mp[a[i]];
		}
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			//cout << it->first << endl;
			v.push_back(it->second);
		}
		sort(v.begin(), v.end());
		if (v.size() == 1) cout << 0 << "\n";
		else {
			int mx = v.back(); v.pop_back();
			ll sum = 0;
			for (auto x : v) {
				if (x < mx) sum += x;
				else sum += mx - 1;
			}
			ll ans = sum / (mx - 1);
			cout << ans << "\n";
			
		}
	}
 
	return 0;
}