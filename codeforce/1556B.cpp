//st
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
int st[2][LEAF + LEAF];
int a[100001];
void init(int ix, int s, int e, int from, int to,int *st) {
	if (e < from || to < s) return;
	if (ix > LEAF) st[ix]  = 0;
	else {
		st[ix] = 0;
		int m = (s + e) >> 1;
		init(ix + ix, s, m, from, to,st);
		init(ix + ix + 1, m + 1, e, from, to,st);
	}
}
void upd(int ix, int val, int *st) {
	while (ix > 0) {
		st[ix] += val;
		ix >>= 1;
	}
}
int rsum(int ix, int s, int e, int from, int to,int *st) {
	if (from > to) return 0;
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return rsum(ix + ix, s, m, from, to,st) + rsum(ix + ix + 1, m + 1, e, from, to,st);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int o = 0, e = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] & 1) ++o;
			else ++e;
		}
		if (abs(o - e) > 1)
			cout << "-1\n";
		else if (n == 1)
			cout << "0\n";
		else {
			int ans = -1;
			if (o >= e) {
				int op = 0;
				vector<int> o, e;
				for (i = 1; i <= n; ++i) {
					if (a[i] & 1) {
						upd(LEAF + i, 1, st[1]);
						o.push_back(i);
					}
					else {
						upd(LEAF + i, 1, st[0]);
						e.push_back(i);
					}
				}
				reverse(o.begin(), o.end()); reverse(e.begin(), e.end());
				for (i = 1; i+1 <= n; i += 2) {
					int pos = o.back(); o.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos,st[0]);
					upd(LEAF + pos, -1, st[1]);
					pos = e.back(); e.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos, st[1]);
					upd(LEAF + pos, -1, st[0]);
				}
				if (n & 1) {
					int pos = o.back(); o.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos, st[0]);
					upd(LEAF + pos, -1, st[1]);
				}
				ans = op;
				//init(1, 0, LEAF - 1, 1, n, st[0]);
				//init(1, 0, LEAF - 1, 1, n, st[1]);
			}
			if (o <= e) {
				int op = 0;
				vector<int> o, e;
				for (i = 1; i <= n; ++i) {
					if (a[i] & 1) {
						upd(LEAF + i, 1, st[1]);
						o.push_back(i);
					}
					else {
						upd(LEAF + i, 1, st[0]);
						e.push_back(i);
					}
				}
				reverse(o.begin(), o.end()); reverse(e.begin(), e.end());
				for (i = 1; i + 1 <= n; i += 2) {
					int pos = e.back(); e.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos, st[1]);
					upd(LEAF + pos, -1, st[0]);
					pos = o.back(); o.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos, st[0]);
					upd(LEAF + pos, -1, st[1]);
				}
				if (n & 1) {
					int pos = e.back(); e.pop_back();
					op += rsum(1, 0, LEAF - 1, 1, pos, st[1]);
					upd(LEAF + pos, -1, st[0]);
				}
				if(ans<0 || ans>op)
					ans = op;
				//init(1, 0, LEAF - 1, 1, n, st[0]);
				//init(1, 0, LEAF - 1, 1, n, st[1]);
			}
			cout << ans << "\n";
		}
	}
 
	return 0;
}
