//st
#include <stdio.h>
const int LEAF = 1 << 17;
int minima[LEAF + LEAF], maxima[LEAF + LEAF];
int max(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return a < b ? b : a;
}
void upd(int ix, int val,int *st) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int mx(int ix, int s, int e, int from, int to,int *st) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return max(mx(ix + ix, s, (s + e) >> 1, from, to, st), mx(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to, st));
}
int main() {
	int N, M;
	int i;
	for (scanf("%d%d", &N, &M), i = 1; i <= N; ++i) {
		int val; scanf("%d",&val);
		upd(LEAF + i, val, maxima);
		upd(LEAF + i, -val, minima);
	}
	while (M--) {
		int a, b; scanf("%d%d",&a,&b);
		printf("%d %d\n",-mx(1,0,LEAF-1,a,b,minima),mx(1,0,LEAF-1,a,b,maxima));
	}
}