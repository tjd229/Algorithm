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
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		bool zero = 1;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i]) zero = 0;
		}
		if (zero) {
			cout << "0\n";
			continue;
		}
		sort(a + 1, a + 1 + n);
		ll ans = a[n];
		for (i = n - 1; i > 0 && k; --k, --i) ans += a[i];
		cout << ans << "\n";
	}
 
 
	return 0;
}