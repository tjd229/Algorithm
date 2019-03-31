//st
#include <stdio.h>
const int LEAF = 1 << 17;
int maxima[LEAF + LEAF], minima[LEAF + LEAF];
int shelf[100001];
int max(int a, int b) {
	if (!a) return b;
	if (!b) return a;
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
int mx(int ix, int s, int e, int from, int to, int *st) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return max(mx(ix + ix, s, (s + e) >> 1, from, to, st), mx(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to, st));
}
int main() {
	int T;
	for (scanf("%d", &T); T--;) {
		int i, N, K;
		for (scanf("%d%d", &N, &K), i = 1; i <= N; ++i) {
			upd(LEAF + i, i, maxima);
			upd(LEAF + i, -i, minima);
			shelf[i] = i;
		}
		while (K--) {
			int Q, A, B; scanf("%d%d%d",&Q,&A,&B);
			++A; ++B;
			if (Q) {
				int maxval = mx(1, 0, LEAF - 1, A, B, maxima);
				int minval = -mx(1, 0, LEAF - 1, A, B, minima);
				printf("%s\n",maxval==B&& minval==A? "YES":"NO");
			}
			else {
				upd(LEAF + A, shelf[B], maxima); upd(LEAF + A, -shelf[B], minima);
				upd(LEAF + B, shelf[A], maxima); upd(LEAF + B, -shelf[A], minima);
				shelf[A] ^= shelf[B] ^= shelf[A] ^= shelf[B];

			}
		}
	}
	return 0;
}