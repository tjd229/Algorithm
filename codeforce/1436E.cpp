//st
#include <stdio.h>
const int LEAF = 1 << 17;
int a[100001];
int last[100011];
int mex[100011];
int st[LEAF + LEAF];
inline int _min(int a, int b) {
	return a < b ? a : b;
}
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = _min(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
int mn(int ix,int s,int e,int from,int to) {
	if (from > to) return 1e9;
	if (e < from || to < s) return 1e9;
	if (s >= from && to >= e) return st[ix];
	return _min(mn(ix + ix, s, (s + e) >> 1, from, to), mn(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] > 1) mex[1] = 1;
		if (a[i] ==1) mex[2] = 1;
		int pos = mn(1, 0, LEAF - 1, 1, a[i] - 1);
		if (a[i]>1 && last[a[i]] < pos)
			mex[a[i]] = 1;
		last[a[i]] = i;
		upd(LEAF + a[i], i);
	}
	for (i = 1; i <= n+1 ; ++i) {
		int pos = mn(1, 0, LEAF - 1, 1, i - 1);		
		if (i>1&& last[i] < pos) mex[i] = 1;
		if (mex[i] == 0) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d",n+2);

	return 0;
}