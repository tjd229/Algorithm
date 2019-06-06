//math, greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	int t;
	ll n, k;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll ans = 0;
		while (n) {
			ll r = n % k;
			n -= r; ans += r;
			if (n) {
				n /= k; ++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}