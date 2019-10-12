//bs, math
#include <stdio.h>
#include <time.h>
#include <random>
#define ll long long
ll bnd = 1e18;
bool ask(ll l,ll r) {
	char ans[4];
	printf("%I64d %I64d\n", l, r); fflush(stdout);
	scanf("%s",ans);
	return ans[0] == 'Y';
}
int main() {
	int k;
	ll n,l, r, m;
	srand(time(0));
	scanf("%I64d%d", &n, &k); 
	if (bnd > n) bnd = n;
	l = 1, r = bnd;
 
	while (1) {
		if (r - l <= (k<<2)+1) {
		    int d=r-l+1;
		    int pad=rand()%d;
			if (ask(l+pad, l+pad))
				return 0;
			l -= k;
			r+=k;
		}
		else {
			ll m = (l + r) >> 1;
			if (ask(l, m)) {
				l = l - k;
				r = m + k;
			}
			else {
				l = m + 1 - k;
				r = r + k;
			}
		}
		if (l < 1) l = 1;
		if (r > bnd) r = bnd;
	}
	
	return 0;
}