//math
#include <stdio.h>
#define ll long long
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		ll p, a, b, c;
		scanf("%I64d%I64d%I64d%I64d",&p,&a,&b,&c);
		ll d = p / a;
		ll aa = a * d;
		if (p%a) aa+=a;
		d = p / b; ll bb = b * d;
		if (p%b) bb+=b;
		d = p / c; ll cc = c * d;
		if (p%c) cc+=c;
		ll ans = aa - p;
		if (ans > bb - p) ans = bb - p;
		if (ans > cc - p) ans = cc - p;
		printf("%I64d\n",ans);
	}
 
	return 0;
}