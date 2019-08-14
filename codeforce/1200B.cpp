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
int h[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i) cin >> h[i];
		bool ans = 1;
		for (int i = 1; i < n && ans; ++i) {
			if (h[i + 1]-k <= h[i]) {
				int tgt = max(0, h[i + 1] - k);
				m += h[i] - tgt;
			}
			else {
				int need = h[i + 1] - k-h[i];
				if (m < need) ans = 0;
				else m -= need;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}