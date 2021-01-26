//st
#include <stdio.h>
const int LEAF = (1 << 20);
long long st[LEAF + LEAF];
void update(int ix, long long x) {
	st[ix] = x;
	ix >>= 1;
	while (ix) {
		st[ix] =st[ix+ix]+st[ix+ix+1];
		ix >>= 1;
	}
}
long long rangeSum(int ix, int s, int e, int from, int to) {
	if (from > e || to < s) return 0;
	if (from <= s && to >= e) return st[ix];
	return rangeSum(ix + ix, s, (s + e) / 2, from, to) + rangeSum(ix + ix + 1, (s + e) / 2 + 1, e, from, to);
}
int main() {
	int N, M, K;
	int i;
	long long a, b, c;
	scanf("%d%d%d", &N, &M, &K);
	M += K;
	for (i = 1; i <= N; i++) scanf("%d", &K), update(LEAF + i, K);
	while(M--) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) update(LEAF + b, c);
		else if (a == 2) printf("%lld\n", rangeSum(1, 0, LEAF - 1, b, c));
	}


	return 0;
}
