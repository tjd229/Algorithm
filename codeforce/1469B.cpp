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
int r[101], b[101];
int rs[101], bs[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, m; cin >> n ;
		for (i = 1; i <= n; ++i) cin >> r[i];
		cin >> m;
		for (i = 1; i <= m; ++i) cin >> b[i];
		for (i = 1; i <= n; ++i) {
			rs[i] = rs[i - 1] + r[i];
		}
		for (i = 1; i <= m; ++i) bs[i] = bs[i - 1] + b[i];
		int mx = 0;
		for (i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				//if (i + j == 0) continue;
				int f = rs[i] + bs[j];
				if (mx < f) mx = f;
			}
		}
		cout << mx << "\n";
	}
 
	return 0;
}