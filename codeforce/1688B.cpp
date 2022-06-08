//math, greedy
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
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		vector<int> e;
		for (i = 1; i <= n; ++i) {
			if ((a[i] & 1) == 0) e.push_back(a[i]);
		}
		if (e.size() != n) {
			cout << e.size() << "\n";
		}
		else {
			int mn = 1e9;
			for (auto x : e) {
				int cnt = 0;
				while ((x&1)==0) {
					++cnt;
					x >>= 1;
				}
				mn = min(cnt, mn);
			}
			int ans = e.size();
			ans = ans - 1 + mn;
			cout << ans << "\n";
		}
	}
 
 
	return 0;
}