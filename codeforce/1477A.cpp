//math
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll x[200001];
ll gcd(ll a, ll b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int n; ll k;
		for(scanf("%d%I64d",&n,&k),i=1;i<=n;++i)
			scanf("%I64d",x+i);
		sort(x + 1, x + 1 + n);
		for (i = 2, k -= x[1]; i <= n; ++i)x[i] -= x[1];
		ll d = x[2];
		for (i = 3; i <= n; ++i) d = gcd(d, x[i]);
		printf("%s\n",k%d? "NO":"YES");
	}
	return 0;
}