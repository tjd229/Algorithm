//dp
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
int a[100001];
ll s[100001];
ll d[500][100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			d[1][i] = a[i];
		}
		int k = 1; int ans = 1;
		int cum = 1;
		for (++k; k < 500; ++k) {
			int upd = 0;
			cum += k;
			int l = n - cum + 1;
			int r = l + k;
			int mx = -1;
			while (l > 0) {				
				if (r<=n &&(mx<d[k - 1][r]))
					mx = d[k - 1][r];
				if (mx < 0) d[k][l] = -1;
				else {
					ll lsum = s[l + k - 1] - s[l - 1];
					if (lsum < mx) {
						d[k][l] = lsum;
						upd = 1;
						ans = k;
					}
					else d[k][l] = -1;
				}
				--l; --r;
			}
			if (upd == 0) break;
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}