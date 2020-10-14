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
const int pad = 1 << 18;
const int LEAF = 1 << 19;
set<int> link[26];
int st[LEAF + LEAF];
char mem[LEAF+1];
void upd(int ix, int val) {
	while (ix >= 1) {
		st[ix] += val;
		ix >>= 1;
	}
}
int sum(int ix, int s, int e, int from, int to) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	return sum(ix + ix, s, (s + e) >> 1, from, to) + sum(ix + ix + 1, ((s + e) >> 1) + 1, e, from, to);
}
int kth(int ix, int k) {
	if (ix >= LEAF) return ix - LEAF;
	int l = ix + ix;
	int r = l + 1;
	if (st[l] >= k) return kth(l, k);
	return kth(r, k - st[l]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i; string s,t; cin >> n >> s;
	t = s;
	reverse(t.begin(), t.end());
	for (i = 0; i < n; ++i) {
		upd(LEAF + (pad + i), 1);
		link[s[i] - 'a'].insert(pad + i);
		mem[pad + i] = s[i];
	}
	ll ans = 0;
	for (i = 0; i < n; ++i) {
		char from = mem[kth(1, 1+i)];//s
		if (from != t[i]) {
			auto st_ix = link[t[i] - 'a'].begin();
			int s_ix = sum(1, 0, LEAF - 1, 0, *st_ix);
			int t_ix = i + 1;
			ans += s_ix-t_ix;
			mem[i] = mem[*st_ix];
			upd(LEAF + *st_ix, -1); upd(LEAF + i, 1);
			link[t[i] - 'a'].erase(st_ix);
		}
		else {
			auto st_ix = link[t[i] - 'a'].begin();
			mem[i] = mem[*st_ix];
			upd(LEAF + *st_ix, -1); upd(LEAF + i, 1);
			link[t[i] - 'a'].erase(st_ix);
		}
	}
	cout << ans;
	
 
	return 0;
}