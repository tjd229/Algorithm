//st, lazy propagation, line sweeping
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
const int LEAF = 1 << 20;
int st[LEAF + LEAF], lazy[LEAF + LEAF];
void propagate(int ix) {
	st[ix] += lazy[ix];
	if (ix < LEAF) {
		lazy[ix + ix] += lazy[ix];
		lazy[ix + ix + 1] += lazy[ix];
	}
	lazy[ix] = 0;
}
void upd(int ix, int s, int e, int from, int to, int val) {
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		lazy[ix] += val;
		propagate(ix);
	}
	else {
		int m = (s + e) >> 1;
		upd(ix + ix, s, m, from, to, val);
		upd(ix + ix + 1, 1 + m, e, from, to, val);
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
	}
}
int rmin(int ix, int s, int e, int from, int to) {
	propagate(ix);
	if (e < from || to < s) return 1e9;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	int res = min(rmin(ix + ix, s, m, from, to), rmin(ix + ix + 1, m + 1, e, from, to));
 
	st[ix] = min(st[ix + ix], st[ix + ix + 1]);
	return res;
 
}
int main() {
	int i, n, m;
	vector<tuple<int, int, int> > v;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) {
		int l, r, w; scanf("%d%d%d", &l, &r, &w);
		--r;
		v.push_back({ w,l,r });
	}
	sort(v.begin(), v.end()); --m;
	int s = 0, e = 0;
	int ans = -1;
	int ws, we;
	while (e < n) {
		int l, r;
		do {
			tie(ignore, l, r) = v[e++];
			upd(1, 0, LEAF - 1, l, r, 1);
		} while (e < n && rmin(1, 0, LEAF - 1, 1, m) == 0);
 
		while (s < e-1) {
			tie(ignore, l, r) = v[s];
			upd(1, 0, LEAF - 1, l, r, -1);
			if (rmin(1, 0, LEAF - 1, 1, m) == 0) {
				upd(1, 0, LEAF - 1, l, r, 1);
				break;
			}
			++s;
		}
		tie(ws, ignore, ignore) = v[s];
		tie(we, ignore, ignore) = v[e - 1];
		if (ans<0 || ans > we - ws) ans = we - ws;
	}
 
	printf("%d", ans);
	return 0;
}