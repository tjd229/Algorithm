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
const int mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (k == 1) cout << "1\n";
		else {
			ll cur = 1; ll base = 2;
			int b = 1;
			while (base + cur<k) {
				cur += base; base<<=1;
				++b;
			}
			int kk = k - cur-1;
			ll ans = 0;
			ll p = 1;
			//printf("%lld,%lld,%d,%d\n",cur,base,kk,b);
			for (int i = 0; i < b; ++i) {
				if (kk & 1) ans += p;
				p = p * n%mod;
				ans %= mod;
				kk >>= 1;
			}
			cout << (ans + p) % mod << "\n";
 
 
		}
 
	}
 
	return 0;
}