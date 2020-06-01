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
 
void digit(ll x, int &mx, int &mn) {
	mx = -1, mn = 10;
	while (x) {
		int mod = x % 10;
		if (mx < mod) mx = mod;
		if (mn > mod) mn = mod;
		x /= 10;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll K,a;
		ll ans = 0;
		cin >> a>> K;
		ans = a;
		for (ll i = 2; i <= K; ++i) {
			int mx, mn;
			digit(a, mx, mn);
			ans = a + mx * mn;
			if (mn == 0) break;
			a = ans;
		}
		cout << ans << "\n";
	}
 
	return 0;
}