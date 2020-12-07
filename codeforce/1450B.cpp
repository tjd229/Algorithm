//implementation
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
int x[101], y[101];
 
int sz[101];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k;
		cin >> n >> k;
		for (i = 1; i <= n; ++i) {
			cin >> x[i] >> y[i];
			sz[i] = 0;
		}
		for (i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int dx = x[i] - x[j];
				int dy = y[i] - y[j];
				if (dx < 0) dx = -dx;
				if (dy < 0) dy = -dy;
				if (dx + dy <= k) {
					++sz[i];
				}
			}
		}
		bool flag = 0;
		for (i = 1; i <= n ; ++i) if (sz[i] == n) flag = 1;
		if (flag) cout << "1\n";
		else cout << "-1\n";
	}
 
	return 0;
}