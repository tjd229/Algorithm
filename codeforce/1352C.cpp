//math
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n, k; scanf("%d%d",&n,&k);
		int d = k / (n - 1);
		ll base = (ll)d * n;
		ll r = k % (n - 1);
		if (r == 0) printf("%I64d\n",base-1);
		else printf("%I64d\n",base+r);
	}
	return 0;
}