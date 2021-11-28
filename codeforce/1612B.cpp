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
int p[101];
int vis[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, a, b; cin>>n >> a >> b;
		int half = n >> 1;
		set<int> L, R;
		for (i = b + 1; i <= n; ++i) L.insert(i);
		for (i = a - 1; i > 0; --i) R.insert(i);
		L.insert(a); R.insert(b);
		if (L.size() > half || R.size() > half) cout << "-1\n";
		else {
			for (i = 1; i <= n; ++i) vis[i] = 0, p[i] = 0;
			int l = 1, r = n;
			for (auto it = L.begin(); it != L.end(); ++it) {
				int x = *it; vis[x] = 1;
				p[l++] = x;
			}
			for (auto it = R.begin(); it != R.end(); ++it) {
				int x = *it; vis[x] = 1;
				p[r--] = x;
			}
			int ix = 1;
			for (i = 1; i <= n; ++i) {
				if (p[i] == 0) {
					while (ix <= n && vis[ix]) ++ix;
					vis[ix] = 1;
					p[i] = ix;
				}
			}
			for (i = 1; i <= n; ++i) cout << p[i] << " ";
			cout << "\n";
		}
		
	}
 
	return 0;
}