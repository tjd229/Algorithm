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
int a[300001];
const int mod = 998244353;
ll f[300001], invf[300001];
ll _pow(ll n, ll e = mod - 2) {
	ll res = 1;
	while (e) {
		if (e & 1)
			res = res * n%mod;
		e >>= 1;
		n = n * n%mod;
	}
	return res;
}
ll nck(int n, int k) {
	ll nume = f[n];
	ll deno = invf[k] * invf[n - k] % mod;
	return nume * deno%mod;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, nn; cin >> n;
	nn = n + n;
	for (i = 1; i <= nn; ++i) cin >> a[i];
	sort(a + 1, a + 1 + nn);
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		ll d = (a[i + n] - a[i]) % mod;;
		ans = (ans + d) % mod;
	}
	f[0] = f[1] = 1;
	invf[0] = invf[1] = 1;
	for (i = 2; i <= nn; ++i) {
		f[i] = f[i - 1] * i%mod;
		invf[i] = _pow(f[i], mod - 2);
	}
	ll cnt = nck(nn, n);
 
	cout << ans * cnt%mod;
 
	return 0;
}