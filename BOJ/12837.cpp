//st
#include <stdio.h>
#define ll long long
const int LEAF = 1 << 20;
ll st[LEAF + LEAF];
void upd(int ix, int val) {
	st[ix] += val;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix + 1] + st[ix + ix];
		ix >>= 1;
	}
}
ll sum(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to);
}
int main() {
	int N, Q;
	for (scanf("%d%d", &N, &Q); Q--;) {
		int t, p, x;
		scanf("%d%d%d",&t,&p,&x);
		if (--t) printf("%lld\n",sum(1,0,LEAF-1,p,x));
		else upd(p + LEAF, x);
	}
	return 0;
}