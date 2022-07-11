//bs
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
int cap[200001];
int n, m;
int sim(int mx) {
	int rem = 0;
	for (int i = 1; i <= m; ++i) {
		if (cap[a[i]] + 1 <= mx) cap[a[i]]++;
		else ++rem;
	}
	int worker = 1;
	while (worker <= n && rem) {
		while (worker <= n && cap[worker] + 2 > mx)++worker;
		while (worker <= n && cap[worker] + 2 <= mx && rem) {
			cap[worker] += 2;
			--rem;
		}
	}
	for (int i = 1; i <= n; ++i) cap[i] = 0;
	return rem == 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; 
		cin >> n >> m;
		for (i = 1; i <= m; ++i) cin >> a[i];
		int l = 1, r = m;
		int ans = r;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (sim(m)) {
				r = m - 1;
				ans = min(ans, m);
			}
			else l = m + 1;
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}