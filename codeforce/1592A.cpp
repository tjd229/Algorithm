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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, H; cin >> n >> H;
		for (i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + 1 + n); 
		int base = a[n] + a[n - 1];
		int div = H / base;
		int rem = H - div * base;
		if (rem == 0) cout << div + div << "\n";
		else {
			int ans = div + div;
			rem -= a[n]; ++ans;
			if (rem > 0) ++ans;
			cout << ans << "\n";
		}
	}
 
	return 0;
}