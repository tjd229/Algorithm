//dp, st, lazy propagation
#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <vector>
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 20;
pii st[LEAF + LEAF]; //val, seg ix
pii lazy[LEAF + LEAF];
int bk[300001],d[300001];
int draw[300001];
void propagate(int ix) {
	st[ix] = max(lazy[ix], st[ix]);
	if (ix < LEAF) {
		lazy[ix + ix] = max(lazy[ix + ix], lazy[ix]);
		lazy[ix + ix+1] = max(lazy[1+ix + ix], lazy[ix]);
	}
	lazy[ix] = { 0,0 };
}
void upd(int ix, int s, int e, int from, int to, pii val) {
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		lazy[ix] = val;
		propagate(ix);
		return;
	}
	if (ix < LEAF) {
		int m = (s + e) >> 1;
		upd(ix + ix, s, m, from, to, val);
		upd(ix + ix + 1, 1 + m, e, from, to, val);
		st[ix] = max(st[ix + ix], st[ix + ix + 1]);
	}
}
pii rmx(int ix, int s, int e, int from, int to) {
	propagate(ix);
	if (e < from || to < s) return {0,0};
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	auto mx= max(rmx(ix + ix, s, m, from, to), rmx(ix + ix + 1, m + 1, e, from, to));
	st[ix] = max(st[ix + ix], st[ix + ix + 1]);
	return mx;
}
int main() {
	int i, n, m;
	vector<int> c;
	vector<tuple<int, int, int> > seg;
	for (scanf("%d%d", &n, &m), i = 1; i <= m; ++i) {
		int row, l, r; scanf("%d%d%d",&row,&l,&r);
		c.push_back(l); c.push_back(r);
		seg.push_back({row,l,r});
	}
	sort(c.begin(), c.end()); sort(seg.begin(), seg.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	
	for (i = 0; i < seg.size(); ) {
		int l, r, row; tie(row, l, r) = seg[i];
		int piv = row; int j = i;
		while (j < seg.size()) {
			tie(row, l, r) = seg[j];
			if (row != piv) break;
			l = lower_bound(c.begin(), c.end(), l) - c.begin();
			r = lower_bound(c.begin(), c.end(), r) - c.begin();
			seg[j] = { row,l,r };
			pii mx = rmx(1, 0, LEAF - 1, l, r);
			//printf("%d,%d,%d,%d\n",mx.first,mx.second,l,r);
			if (d[row] < mx.first + 1) {
				bk[row] = mx.second;
				d[row] = mx.first + 1;
			}
			++j;
		}
		for (; i < j; ++i) {
			tie(row, l, r) = seg[i];
			upd(1, 0, LEAF - 1, l, r, { d[row],row });
		}
	}
	int mx = 0; int ed = 0;
	for (i = 1; i <= n; ++i) {
		if (d[i] > mx) {
			mx = d[i];
			ed = i;
		}
		//printf("%d\n",d[i]);
	}
	while (ed > 0) {
		draw[ed] = 1;
		ed = bk[ed];
	}
	for (printf("%d\n", n - mx), i = 1; i <= n; ++i) {
		if (draw[i] == 0) printf("%d ",i);
	}
 
	return 0;
}
