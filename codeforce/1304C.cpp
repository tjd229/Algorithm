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
int t[101], l[101], h[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, m; cin >> n >> m;
		int now = 0;
		int lb = m, rb = m;
		bool flag = 1;
		for (int i = 1; i <= n; ++i)
			cin >> t[i] >> l[i] >> h[i];
		for (int i = 1; i <= n && flag; ++i) {
			int d = t[i] - now;
			lb -= d; rb += d;
			if (rb < l[i] || h[i] < lb) flag = 0;
			else {
				lb = max(lb, l[i]);
				rb = min(rb, h[i]);
			}
			now = t[i];
			//cout << flag << endl;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}