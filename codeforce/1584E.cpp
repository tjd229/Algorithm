//st, greedy, bs
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const ll inf = 1e18;
const int LEAF = 1 << 19;
int a[300001];
ll c[300001];
ll st[2][LEAF + LEAF];
ll fast[LEAF + LEAF];
vector<int> pos[300001];
void upd(int ix, ll val, ll *st) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		st[ix] = min(st[ix + ix], st[ix + ix + 1]);
		ix >>= 1;
	}
}

void path(int ix, int s, int e, int from, int to, ll*st) {
	if (e < from || to < s) fast[ix]=inf;
	else if (from <= s && e <= to) fast[ix] = st[ix];
	else {
		int m = (s + e) >> 1;
		path(ix + ix, s, m, from, to, st);
		path(ix + ix + 1, 1 + m, e, from, to, st);
		fast[ix] = min(fast[ix + ix], fast[ix + ix + 1]);
	}
}
int qry(int ix,int s,int e,int from,int to,ll piv, ll *st) {
	if (ix >= LEAF) return ix-LEAF;
	ll *tree = fast;
	if (from <= s && e <= to) {
		tree = st;
	}
	int left = ix + ix, right = 1 + left;
	int m = (s + e) >> 1;
	if (tree[left] < piv) return qry(ix + ix, s, m, from, to, piv,st);
	return qry(ix + ix + 1, m + 1, e, from, to, piv,st);
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n;
		ll ans = 0;
		int cnt = 1;
		map<ll, int> mp[2];
		for (scanf("%d", &n), i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			c[i] = a[i] - c[i - 1];
			pos[i].clear();

			upd(LEAF + i, c[i], st[i & 1]);
			upd(LEAF + i, inf, st[1 - (i & 1)]);
		}
		if (n == 1) {
			printf("%d\n", a[1] == 0);
			continue;
		}
		for (i = 1; i <= n; ++i) {
			auto &cache = mp[i & 1];
			if (cache[c[i]] == 0) cache[c[i]] = cnt++;
			pos[cache[c[i]]].push_back(i);
		}

		for (int l = 1; l <= n; ++l) {
			ans += a[l] == 0;
			int ed0 = 1 + n, ed1 = 1 + n;
			int i = l & 1;
			int left = l, right = n;
			path(1, 0, LEAF - 1, left, right, st[i]);
			if (fast[1] < -c[l - 1])
				ed0 = qry(1, 0, LEAF - 1, left, right, -c[l - 1], st[i]);
			
			i = 1 - i;
			path(1, 0, LEAF - 1, left, right, st[i]);
			if (fast[1] < c[l - 1])
				ed1 = qry(1, 0, LEAF - 1, left, right, c[l - 1], st[i]);
			
			int ed = min(ed0, ed1);
			int x = mp[i][c[l - 1]];
			if (x) {
				ans += lower_bound(pos[x].begin(), pos[x].end(), ed) - upper_bound(pos[x].begin(), pos[x].end(), l);
			}
			i = 1 - i;
			x = mp[i][-c[l - 1]];
			if (x) {
				ans += lower_bound(pos[x].begin(), pos[x].end(), ed) - upper_bound(pos[x].begin(), pos[x].end(), l);
			}
		}
		printf("%I64d\n", ans);

	}
	return 0;
}