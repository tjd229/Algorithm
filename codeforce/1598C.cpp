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
		int i, n; cin >> n;
		ll sum = 0;
		for (i = 1; i <= n; ++i) cin >> a[i],sum+=a[i];
		int r = sum % n;
		if (r + r == n || r == 0) {
			ll dst = (sum+sum) / n;
			map<int, int> mp;
			ll ans = 0;
			for (i = 1; i <= n; ++i) {
				int need = dst - a[i];
				ans += mp[need];
				++mp[a[i]];
			}
			cout << ans << "\n";
		}
		else
			cout << "0\n";
		
		
	}
 
	return 0;
}