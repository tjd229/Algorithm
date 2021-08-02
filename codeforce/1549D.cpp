//math, st, line sweeping
#include <stdio.h>
#define ll long long
const int LEAF = 1 << 18;
ll a[200001];
ll diff[200002];
ll st[LEAF + LEAF];
ll gcd(ll a, ll b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
void upd(int ix,ll val) {
	st[ix] = val; ix >>= 1;
	while (ix) {
		st[ix] = gcd(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}
ll rgcd(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return gcd(rgcd(ix + ix, s, m, from, to), rgcd(ix + ix + 1, m + 1, e, from, to));
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		for (scanf("%d", &n), i = 1; i <= n; ++i) scanf("%I64d", a + i);

		int len = 1;
		for (i = 2; i <= n; ++i) {
			diff[i] = a[i] - a[i - 1];
			if (diff[i] < 0) diff[i] = -diff[i];
			upd(i + LEAF, diff[i]);
		}
		int l, r;
		for (r =l=2; r <= n; ++r) {
			if (diff[r] == 1) continue;
			while (l <= r) {
				if (rgcd(1, 0, LEAF - 1, l, r)> 1)break;
				++l;
			}
			if (len < r - l + 2) len = r - l + 2;
		}
		printf("%d\n", len);
	}

	return 0;
}