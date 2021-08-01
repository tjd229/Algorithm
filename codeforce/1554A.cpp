//greedy
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[100002];
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; 
		ll ans = 0;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%d",a+i);
		a[1 + n] = 0;
		for (i = 1; i <= n; ++i) {
			ll mx = max(a[i], a[i - 1]);
			ll mn = min(a[i], a[i - 1]);
			ll val = mx * mn;
			ans = max(ans, val);
			mx = max(a[i], a[i + 1]);
			mn = min(a[i], a[i + 1]);
			val = mx * mn;
			ans = max(ans, val);
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}