//math
#include <stdio.h>
#define ll long long
const int mod=1e9 + 7;
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
 
		int i, n, m;
		int X = 0;
		for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
			int l, r, x; scanf("%d%d%d",&l,&r,&x);
			X |= x;
		}
		ll p = 1;
		for (i = 1; i < n; ++i) p = (p + p) % mod;
		printf("%I64d\n",p*X%mod);
		
	}
 
	return 0;
}