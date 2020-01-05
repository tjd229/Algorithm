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
const int LEAF = 1 << 20;
int mn[100000];
int mx[100000];
bool self[100000];
int mnst[LEAF + LEAF], mxst[LEAF + LEAF];
void upd(int ix, int val,int *st) {
	while (ix) {
		st[ix] += val;
		ix >>= 1;
	}
}
int sum(int ix, int s, int e, int from, int to,int *st) {
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return sum(ix + ix, s, m, from, to,st) + sum(ix + ix + 1, m + 1, e, from, to,st);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	ll ans = 0;
	ll ns = 0;
	for (i = 0; i < n; ++i) {
		int l; cin >> l;
		mn[i] = 1e9;
		for (int j = 0; j < l; ++j) {
			int e; cin >> e;
			if (e > mn[i]) self[i] = 1;
			if (mx[i] < e) mx[i] = e;
			if (mn[i] > e) mn[i] = e;
		}
		if (self[i] == 0) {
			upd(LEAF + mx[i], 1, mxst);
			upd(LEAF + mn[i], 1, mnst);
		}
		else ++ns;
	}
	
	for (i = 0; i < n; ++i) {
		if (self[i]) continue;
		//upd(LEAF + mx[i], -1, mxst);
		//upd(LEAF + mn[i], -1, mnst);
		//printf("i:%d\n",i);
		ans += sum(1, 0, LEAF - 1, mn[i] + 1, LEAF - 1, mxst);
		//printf("%lld\n",ans);
		//if(mx[i]>0)
			//ans += sum(1, 0, LEAF - 1, 0, mx[i] - 1, mnst);
		//printf("%lld\n", ans);
		//upd(LEAF + mx[i], 1, mxst);
		//upd(LEAF + mn[i], 1, mnst);
 
		//if (mn[i] != mx[i]) ++ans;
		//printf("%lld\n", ans);
	}
	ans += ns * n;
	ans += (n - ns) * ns;
	cout << ans;
 
	return 0;
}