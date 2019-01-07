//math
#include <stdio.h>
#define ll long long
ll max(ll a, ll b) { return a < b ?  b : a; }
ll gcd(ll a, ll b) {
	if (a > b) a ^= b ^= a ^= b;
	if (!a) return b;
	return gcd(b%a,a);
}
ll in(ll la, ll ra, ll lb, ll rb) {
	if (la > lb) lb = la;
	if (ra > rb) ra = rb;
	return ra<lb? 0:ra - lb + 1;
}
int main() {
	ll la, ra, ta;
	ll lb, rb, tb;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&la,&ra,&ta,&lb,&rb,&tb);
	ll d = gcd(ta, tb);
	ll lena = ra - la + 1;
	ll lenb = rb - lb + 1;
	if (d == 1) printf("%I64d",lena<lenb? lena:lenb);
	else {
		ll dist = la - lb;
		if (dist < 0) dist = -dist;
		ll jump = dist / d;
		if (la < lb) {
			la += jump*d;
			ra += jump*d;
		}
		else {
			lb+=jump*d;
			rb += jump*d;
		}
		ll ans = in(la, ra, lb, rb);
		ans=max(ans, in(la + d, ra + d, lb, rb));
		ans=max(ans, in(la, ra, lb+d, rb+d));
		printf("%I64d",ans);
	}
	return 0;
}
