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
const int mod = 998244353;
ll f[200001], invf[200001];
int a[200001];
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
	int t; cin >> t;
	int n = 200000;
	f[0] = f[1] = 1;
	invf[0] = invf[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1] * i%mod;
	}
	invf[n] = _pow(f[n], mod - 2);
	for (int i = n - 1; i > 1; --i)
		invf[i] = invf[1 + i] * (1 + i)%mod;
	//for (int i = 1; i <= 10; ++i)
	//	printf("%lld\n",invf[i]);
	while(t--) {
		int i;  cin >> n;
		int mx = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (mx < a[i]) mx = a[i];
		}
		int cnt[2] = { 0 };
		for (i = 1; i <= n; ++i) {
			if (a[i] == mx) ++cnt[1];
			else if(a[i]==mx-1) ++cnt[0];
		}
		if (cnt[1] > 1) {
			cout << f[n] << "\n";
		}
		else if (cnt[0] == 0)
			cout << "0\n";
		else {
			ll ans = 1;
			ans = ans * f[cnt[0]]%mod;
			int r = n - cnt[0] - 1;
			ans = ans * f[r] % mod;
			ans = ans * cnt[0] % mod;
			
			ans = ans * nck(n,1+cnt[0]) % mod;
			//printf("(%d,%d)||%d,%d,%lld\n", n, 1 + cnt[0], cnt[0],r,f[r]);
			cout << ans << "\n";
		}
	}
 
 
	return 0;
}