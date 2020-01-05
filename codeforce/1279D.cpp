//math
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
const int mod = 998244353;
vector<int> a[1000001];
int k[1000001];
int cnt[1000001];
ll inv[1000001];
int p(ll b,int e) {
	ll res = 1;
	while (e) {
		if (e & 1) 
			res = res * b%mod;		
		e >>= 1;
		b = b * b%mod;
	}
	return res;
}
int main() {
	int i, j,n;
	ll ans = 0;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		for (scanf("%d", k + i), j = 0; j < k[i]; ++j) {
			int wanna; scanf("%d",&wanna);
			++cnt[wanna];
			a[i].push_back(wanna);
		}
	}
	for (i = 1; i <=1000000; ++i) inv[i] = p(i, mod - 2);
	for (i = 1; i <= n; ++i) {
		ll x = inv[n];
		ll y = inv[k[i]];
		for (auto w : a[i]) {
			ll z = cnt[w] * inv[n] % mod;
			ll prob = x * y%mod;
			prob = prob * z%mod;
			ans = (ans + prob) % mod;
		}
	}
	printf("%I64d",ans);
	return 0;
}