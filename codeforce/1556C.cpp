//math
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
int c[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans = 0;
	int i, n; cin >> n;
	vector<pii > v;
	for (i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (i = 1; i + 1 <= n; i += 2) v.push_back({c[i],c[i+1]});
	for (int i = 0; i < v.size(); ++i) {
		ans += min(v[i].first, v[i].second);
	}
	for (int s = 0; s < v.size(); ++s) {
		ll open = v[s].first-v[s].second;
		ll mid = 0;
		for (int e = s + 1; e < v.size(); ++e) {
			if (open<0) break;
			ll close = v[e].second - v[e].first;
			if (close-mid>=0) {
				ans += min(open, close - mid)+1;
			}
			
			mid += v[e].first - v[e].second;
			if (mid < 0) open += mid,mid=0;
		}
	}
	cout << ans;
 
	return 0;
}