//dp
#include <stdio.h>
#define ll long long
int a[200001];
ll d[200001];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d",a+i);
			d[i] = 0;
		}
		for (i = n; i > 0; --i) {
			int ix = i + a[i];
			if (ix <= n) {
				d[i] = d[ix] + a[i];
			}
			else d[i] = a[i];
		}
		ll ans = 0;
		for (i = 1; i <= n; ++i) if (ans < d[i]) ans = d[i];
		printf("%I64d\n",ans);
	}
 
	return 0;
}