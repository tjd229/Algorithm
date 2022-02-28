//st
#include <stdio.h>
#include <set>
using namespace std;
const int LEAF = 1 << 18;
const int inf = 1e9;
int st[LEAF + LEAF];
void upd(int ix, int val) {
	while (ix) {
		if (st[ix] < val) break;
		st[ix] = val;
		ix >>= 1;
	}
}
int rmin(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return inf;
	if (from <= s && e <= to) return st[ix];
	int l = rmin(ix + ix, s, (s + e) >> 1, from, to);
	int r = rmin(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to);
	return l < r ? l : r;
}
int main() {
	int i, n, q;
	set<int> c;
	for (scanf("%d%d", &n, &q), i = 1; i <= n; ++i) c.insert(i);
	for (i = 0; i < LEAF + LEAF; ++i) st[i] = inf;

	while (q--) {
		int t; scanf("%d",&t);
		if (t) {
			int j; scanf("%d",&j);
			if (0 == c.count(j)) printf("NO\n");
			else {
				int l = 1, r = n+1;
				auto it = c.lower_bound(j);
				if (it != c.begin()) l = *prev(it) + 1;
				if (++it != c.end()) r = *it;
				if (rmin(1, 0, LEAF - 1, l, n) <r) printf("YES\n");
				else printf("N/A\n");
			}
		}
		else {
			int l, r, x; scanf("%d%d%d",&l,&r,&x);
			if (x) 
				upd(LEAF + l, r);
			else {
				while (1) {
					auto it = c.lower_bound(l);
					if (it == c.end() || *it > r) break;
					c.erase(it);
				}
			}
		}
	}


	return 0;
}