//math
#include <stdio.h>
#define ll long long
 
ll qry(ll a, ll b) {
	printf("? %I64d %I64d\n", a, b); fflush(stdout);
	ll d; scanf("%I64d",&d);
	return d;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll x = qry(2, 4)&1;
		
		for (int i = 1; i < 30; ++i) {
			ll b = 1LL << i;
			ll a = b + b + b;
			ll d = qry(a - x, b - x);
			if (b != d) x += b;
		}
		printf("! %I64d\n", x); fflush(stdout);
	}
	return 0;
}