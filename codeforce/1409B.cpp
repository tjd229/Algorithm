//math, greedy
#include <stdio.h>
#define ll long long
ll prod(int a,int b,int x,int y,int n) {
	a -= n; n = 0;
	if (a < x) {
		int delta = x - a;
		n += delta;
		a += delta;
	}
	b -= n; n = 0;
	if (b < y) b += y - b;
	return (ll)a*b;
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a, b, x, y, n; scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
		ll ans1 = prod(a, b, x, y, n);
		ll ans2 = prod(b, a, y, x, n);
		printf("%I64d\n",ans1<ans2? ans1:ans2);
	}
	return 0;
}