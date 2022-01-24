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
int a[300001];
int b[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) cin >> b[i];
		vector<pii > v;
		for (i = 1; i <= n; ++i) v.push_back({a[i],b[i]});
		sort(v.begin(), v.end());
		for (i = 0; i < n; ++i) {
			if (k >= v[i].first) k += v[i].second;
			else break;
		}
		cout << k << "\n";
	}
 
 
	return 0;
}