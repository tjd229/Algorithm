//implementation
#include <stdio.h>
#define ll long long
ll f[100002],s[100002];
ll max(ll a, ll b) { return a < b ? b : a; }
ll min(ll a, ll b) { return a > b ? b : a; }
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, j, m;
		for (scanf("%d", &m), i = 1; i <= m; ++i) scanf("%I64d",f+i);
		for (i = 1; i <= m; ++i) scanf("%I64d",s+i);
		for (i = 1; i <= m; ++i) {
			f[i] += f[i - 1];
			s[i] += s[i - 1];
		}
		ll ans = f[m]+s[m];
		f[m + 1] = f[m]; s[m + 1] = s[m];
		for (i = 1; i <= m; ++i) {
			ll r = f[m + 1] - f[i];
			ll l = s[i - 1] - s[0];
			ll Bob = max(r, l);
			ans = min(Bob, ans);
		}
		printf("%I64d\n",ans);
		
	}
 
	return 0;
}