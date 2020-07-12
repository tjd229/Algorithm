//math
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n,r; scanf("%d%d",&n,&r);
		int len = r < n-1 ? r : n-1;
		ll ans = ((len + 1LL)*len) >> 1;
		if (n - 1 < r) ++ans;
		printf("%I64d\n",ans);
		
	}
	return 0;
}
