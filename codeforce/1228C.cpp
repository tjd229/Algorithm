//math
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<int> p;
int seive[100000];
ll pow229(ll base, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * base%mod;
		e >>= 1;
		base = (base*base) % mod;
	}
	return res;
}
int main() {
	int x; ll n;
	ll ans = 1;
	scanf("%d%I64d", &x, &n);
	for (ll i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			p.push_back(i);
			while (x%i == 0) x /= i;
		}
	}
	if (x>1) //x is prime case
		p.push_back(x);
 
	for (auto px : p) {
		//printf("%lld\n", px); continue;
		ll e = 0;
		ll d = n / px;
		while (d) {
			//printf("%lld,%lld\n",d,e);
			e += d;
			d /= px;
		}
 
		ans = ans * pow229(px, e) % mod;
	}
	printf("%I64d", ans);
 
	return 0;
}