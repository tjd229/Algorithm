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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int ix = 1;
		ll ans = 0;
		for (i = 1; i <= n; ++i) {
			if (a[i] > ix) {
				int d = a[i] - ix;
				ix += d;
				ans += d;
			}
			++ix;
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}