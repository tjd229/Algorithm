//math
#include <stdio.h>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int a[200001];
ll f[200001], invf[200001];
ll _pow(ll x,ll e=mod-2) {
	ll res = 1;
	ll base = x;
	while (e) {
		if (e & 1) {
			res = res * base%mod;
		}
		e >>= 1;
		base = base * base%mod;
	}
	return res;
}
ll nck(int n, int k) {
	if (n < k) return 0;
	ll nume = f[n];
	ll deno = invf[k] * invf[n - k] % mod;
	return nume * deno%mod;
}
int main() {
	int t;
	f[0] = f[1] = 1;
	invf[0] = invf[1] = 1;
	for (int i = 2; i <= 200000; ++i) {
		f[i] = f[i - 1] * i%mod;
		invf[i] = _pow(f[i]);
	}
	for (scanf("%d", &t); t--;) {
		ll ans = 0;
		int i, n, m, k;
		deque<int> dq;
		for (scanf("%d%d%d", &n, &m, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
		sort(a + 1, a + 1 + n); i = 1;
		
		while (i <= n) {
			int piv = a[i]; int j = i;
			while (j <= n && piv == a[j])
				++j;
			while (dq.size() && piv- dq.front() > k) dq.pop_front();
			for (int l = 1; l <= m; ++l) {
				ll t1 = nck(dq.size(),m-l);
				ll t2 = nck(j - i, l);
				ans = (ans + t1 * t2)%mod;
			}
			while (i < j) dq.push_back(a[i++]);
			//printf("piv:%d,dq.size():%d\n",piv,dq.size());
			//printf("%lld\n", nck(dq.size(), m));
			//ans = (ans + nck(dq.size(), m))%mod;
		}
		printf("%I64d\n",ans);
	}
	
}