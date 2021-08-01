//math
#include <stdio.h>
#define ll long long
int a[100001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j,n,k;
		for (scanf("%d%d", &n,&k), i = 1; i <= n; ++i) scanf("%d",a+i);
		i = n - k - k;
		if (i < 1) i = 1;
		ll ans = -n*(ll)n;
		for (; i <= n; ++i) {
			for (j = i + 1; j <= n; ++j) {
				ll val = i * (ll)j;
				val -= k * (a[i] | a[j]);
				if (ans < val) ans = val;
			}
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}