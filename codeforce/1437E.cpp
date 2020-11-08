//dp, st
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int LEAF = 1 << 19;
int a[500002];
int st[LEAF + LEAF];
void upd(int ix, int val) {
	st[ix] = val;
	ix >>= 1;
	while (ix) {
		int l = ix + ix, r = l + 1;
		st[ix] = st[l] < st[r] ? st[r] : st[l];
		ix >>= 1;
	}
}
int mx(int ix,int s,int e,int from,int to) {
	if (from > to) return 0;
	if (to < s || e < from) return 0;
	if (from <= s && e <= to) return st[ix];
	int l = mx(ix + ix, s, (s + e) >> 1, from, to);
	int r = mx(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to);
	return l < r ? r : l;
}
int mk(int s,int e) {
	if (a[s] > a[e]) return -1;
	vector<int> v;
	int head = a[s], tail = a[e];
	for (int i = s; i <= e; ++i) v.push_back(a[i]);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for (int i = s; i <= e; ++i)
		a[i] = lower_bound(v.begin(), v.end(),a[i]) - v.begin();
	int longest = 0;
	for (int i = s + 1; i < e; ++i) {
		if (a[i] >= a[s] && a[i] <= a[e]) {
			int range_mx = mx(1, 0, LEAF - 1, 0, a[i]);
			if (range_mx + 1 > longest)
				longest = range_mx + 1;
			upd(LEAF + a[i], range_mx + 1);
		}
	}
	for (int i = 0; i < v.size(); ++i) upd(LEAF + i, 0);
	a[s] = head, a[e] = tail;
	int len = e - s - 1;
	return len - longest;
}
int main() {
	int i, n, k;
	vector<int> fix = { 0 };
	for (scanf("%d%d", &n, &k), i = 1; i <= n; ++i) scanf("%d",a+i);
	while (k--) {
		int b; scanf("%d",&b);
		fix.push_back(b);
	}
	fix.push_back(n + 1); a[n + 1] = 2e9; a[0] = -2e9;
	for (i = 0; i <= n + 1; ++i) a[i] -= i;
	int ans = 0;
	for (i = 1; i < fix.size(); ++i) {
		int cnt = mk(fix[i - 1], fix[i]);
		if (cnt < 0) {
			printf("-1");
			return 0;
		}
		ans += cnt;
	}
	printf("%d",ans);
	return 0;
}