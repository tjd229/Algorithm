//dp, st, lazy propagation
#include <stdio.h>
#include <memory.h>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 19;
ll st[LEAF + LEAF], lazy[LEAF + LEAF];
ll froml[500001], fromr[500002];
int cover[LEAF + LEAF];
int m[500001];
int ans[500001];
void propagate(int ix) {
	st[ix] += lazy[ix] * cover[ix];
	if (ix < LEAF) {
		lazy[ix + ix] += lazy[ix];
		lazy[ix + ix + 1] += lazy[ix];
	}
	lazy[ix] = 0;
}
void upd(int ix, int s, int e, int from, int to, int d) {
	propagate(ix);
	if (e < from || to < s) return;
	if (from <= s && e <= to) {
		lazy[ix] += d;
		propagate(ix);
		return;
	}
	if (ix < LEAF) {
		upd(ix + ix, s, (s + e) >> 1, from, to, d);
		upd(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to, d);
		st[ix] = st[ix + ix] + st[ix + ix + 1];
	}
}
int main() {
	int i, n;
	for (scanf("%d", &n), i = 1; i <= n; ++i) {
		scanf("%d", m + i);
		int ix = i + LEAF;
		while (ix) {
			++cover[ix];
			ix >>= 1;
		}
	}
	deque<pii > dq; dq.push_back({ 0,0 });//val,ix
	for (i = 1; i <= n; ++i) {
		int r = i;
		while (dq.back().first > m[i]) {
			int l = dq.back().second;
			int h = dq.back().first;
			dq.pop_back();
			upd(1, 0, LEAF - 1, l, r - 1, m[i] - h);
			r = l;
		}
	
		dq.push_back({ m[i],r });
		upd(1, 0, LEAF - 1, i, i, m[i]);
		propagate(1);
		froml[i] = st[1];
	}
	memset(st, 0, sizeof(st)); memset(lazy, 0, sizeof(lazy));
	dq.clear();
	dq.push_back({ 0,n + 1 });
	for (i = n; i >= 1; --i) {
		int l = i;
		while (dq.front().first > m[i]) {
			int r = dq.front().second;
			int h = dq.front().first;
			dq.pop_front();
			upd(1, 0, LEAF - 1, l + 1, r, m[i] - h);
			l = r;
		}
		dq.push_front({ m[i],l });
		upd(1, 0, LEAF - 1, i, i, m[i]);
		propagate(1);
		fromr[i] = st[1];
	}
	ll mx = fromr[1];
	int pick = 0;
	for (i = 1; i <= n; ++i) {
		if (mx < froml[i] + fromr[i + 1]) {
			mx = froml[i] + fromr[i + 1];
			pick = i;
		}
	}
	dq.clear(); dq.push_back({ 0,0 });
	for (i = 1; i <= pick; ++i) {
		while (dq.back().first > m[i]) dq.pop_back();
		dq.push_back({ m[i],i });
	}
	int h = dq.back().first;
	for (i = pick; i >= 1; --i) {
		if (dq.back().second == i) {
			h = dq.back().first;
			dq.pop_back();
		}
		ans[i] = h;
	}
	dq.clear(); dq.push_back({ 0,n + 1 });
	for (i = n; i > pick; --i) {
		while (dq.front().first > m[i]) dq.pop_front();
		dq.push_front({ m[i],i });
	}
	h = dq.front().first;
	for (i = pick + 1; i <= n; ++i) {
		if (dq.front().second == i) {
			h = dq.front().first;
			dq.pop_front();
		}
		ans[i] = h;
	}
	
	for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}