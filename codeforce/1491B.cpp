//graph
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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, v, u; cin >> n >> u >> v;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int w = 0;
		for (i = 2; i <= n; ++i) {
			int d = a[i] - a[i - 1];
			if (d < 0) d = -d;
			if (w < d) w = d;
		}
		if (w == 0) {
			int vv = v + v;
			int uv = u + v;
			int ans = min(vv, uv);
			cout << ans << "\n";
		}
		else if (w == 1) {
			cout << min(u, v) << "\n";
		}
		else cout << "0\n";
		
	}
 
	return 0;
}