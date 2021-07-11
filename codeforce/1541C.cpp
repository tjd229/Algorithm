//graph, st
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 17;
ll st[LEAF + LEAF];
int cnt[LEAF + LEAF];
int d[100001];
void init(int ix,int s,int e,int from,int to) {
	if (e < from || to < s) return;
	if (ix > LEAF) st[ix] =cnt[ix]= 0;
	else {
		st[ix] = cnt[ix] = 0;
		int m = (s + e) >> 1;
		init(ix + ix, s, m, from, to);
		init(ix + ix + 1, m + 1, e, from, to);
	}
}
void upd(int ix,int val) {
	while (ix > 0) {
		st[ix] += val;
		cnt[ix] += 1;
		ix >>= 1;
	}
}
ll rsum(int ix, int s, int e, int from, int to) {
	if (from > to) return 0;
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return rsum(ix + ix, s, m, from, to) + rsum(ix + ix + 1, m + 1, e, from, to);
}
int rcnt(int ix, int s, int e, int from, int to) {
	if (from > to) return 0;
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return cnt[ix];
	int m = (s + e) >> 1;
	return rcnt(ix + ix, s, m, from, to) + rcnt(ix + ix + 1, m + 1, e, from, to);
}
int kth(int x, vector<int> &v) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		vector<int> v;
		ll ans = 0;
		for (i = 1; i <= n; ++i) {
			cin >> d[i];
			v.push_back(d[i]);
		}
		sort(v.begin(), v.end());
		sort(d + 1, d + 1 + n);
		v.resize( unique(v.begin(),v.end())-v.begin());
		
 
		int k = kth(d[1], v);
		int lastk = kth(d[2], v);
		upd(LEAF + k, d[1]);
		for (i = 3; i <= n; ++i) {
			int k = kth(d[i], v);
			ll cnt = rcnt(1, 0, LEAF - 1, 0, k - 1);
			ll low = rsum(1, 0, LEAF - 1, 0, k - 1);
			ans -= cnt * d[i] - low;
			upd(LEAF + lastk, d[i - 1]);
			lastk = k;
		}
		cout << ans << "\n";
		//init
		init(1, 0, LEAF - 1, 0, n - 1);
	}
 
	return 0;
}