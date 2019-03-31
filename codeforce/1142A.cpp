//math, implementation
#include <stdio.h>
#define ll long long
int n, k, a, b;
ll nk;
ll max(ll a, ll b) { return a < b ? b : a; }
ll min(ll a, ll b) { return a < b ? a : b; }
ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a,a);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll step(ll s,ll t) {
	if (s <= 0) s += nk;
	while (t < s) t += nk;
	//printf("%lld,%lld\n",s,t);
	if (s == t || s + nk == t) return 1;
	ll l = t - s;
	
	//if (lcm(l, nk )<0 || l == 0)
		//printf("res:%lld,%lld\n",lcm(l, nk),lcm(l, nk) / l);
	//return lcm(l,nk)/l;
	return nk / gcd(l,nk);
}
int main() {
	scanf("%d%d%d%d",&n,&k,&a,&b);
	nk = n * (ll)k;
	ll x = nk, y = 0;
	ll s = a + 1; 
	ll t1 = 1 + b, t2 = 1 - b;
	for (int i = 0; i < n; ++i) {
		ll z = step(s, t1);
		x = min(z, x); y = max(y, z);
		z = step(s, t2);
		x = min(z, x); y = max(y, z);
		t1 += k, t2 += k;
	}
	s = 1 - a;
	t1 = 1 + b, t2 = 1 - b;
	for (int i = 0; i < n; ++i) {
		ll z = step(s, t1);
		x = min(z, x); y = max(y, z);
		z = step(s, t2);
		x = min(z, x); y = max(y, z);
		t1 += k, t2 += k;
	}
	printf("%I64d %I64d",x,y);
	return 0;
}
