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
const int mod = 1e9 + 7;
ll base[100];
int pp[100];
vector<int> p = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
ll decomp(int n,vector<pii > &v) {
	ll res = 1;
	for (int i = 0; i < p.size() && p[i] < n; ++i) {
		int base = 1;
 
		int cnt = 0;
		while (base < n) base *= p[i],++cnt;
		base /= p[i]; --cnt;
		res *= base;
		v.push_back({p[i],cnt});
	}
	return res;
}
bool unq(int n, vector<pii > &v) {
	for (int i = 0; i < v.size() && n>1; ++i) {
		int cnt = v[i].second;
		int x = v[i].first;
		while (cnt > 0 && n%x == 0) {
			n /= x;
			--cnt;
		}
	}
	return n > 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	base[4] = 6; base[5] = 12; 
	pp[4] = pp[5] = 1;
	int i,t;
	ll mx = 1e16;
	for (i = 7; i <= 100; ++i) {
		vector<pii > v;
		ll x=decomp(i, v);
		if (mx < x) {
			break;
		}
		if (unq(i, v)) {
			base[i] = x;
			int l = i - 1;
			pp[i] = 1;
			while (base[l] == 0) {
				--l;
				++pp[i];
			}
		}
	}
	
	//cout << base[17];
	cin >> t;
	while (t--) {
		ll n; cin >> n;
		if (n == 1) cout << "2\n";
		else if (n == 2) cout << "5\n";
		else if (n == 3) cout << "7\n";
		else if (n == 4) cout << "10\n";
		else {
			ll odd = (n >> 1)+(n&1);
			ll even = n >> 1;
			ll ans = odd * 2 % mod;
			ans = (ans + even * 3) % mod;
			for (i = 4;i<100 && base[i]<=n; ++i) {
				if (base[i] == 0) continue;
				ll div = n / base[i];
				ans = (ans + div * pp[i] % mod) % mod;
			}
			cout << ans << "\n";
		}
	}
	
	
 
 
	return 0;
}
