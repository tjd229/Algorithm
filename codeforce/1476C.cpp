//line sweeping
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
int a[100001], b[100001],c[100001];
ll l[100001], r[100001];
ll lst[100001], red[100001];
ll local_cyc(int st,int ed) {
	for (int i = st; i <= ed; ++i) {
		lst[i] = b[i] - a[i];
		red[i] = c[i] - 1;
	}
	red[st] = 0, lst[ed] = 0;
	l[st] = b[st] - a[st];
	for (int i = st+1; i <= ed; ++i) {
		l[i] = max(lst[i - 1] + 2, l[i - 1] + 2 + a[i] - 1 + c[i ] - b[i]);
	}
	r[ed] = 0;
	for (int i = ed - 1; i >= st; --i) {
		r[i] = max(red[i + 1] + 2, r[i + 1] + 2 + a[i + 1] - 1 + c[i + 1] - b[i + 1]);
	}
	ll cyc = 0;
	for (int i = st; i <= ed; ++i) {
		ll len = l[i] + r[i];
		len = max(len, lst[i] + r[i]);
		if(i>st)
			len = max(len, red[i] + l[i-1]+2);
		cyc = max(cyc, len);
	}
	return cyc;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> c[i];
		for (i = 1; i <= n; ++i) cin >> a[i-1];
		for (i = 1; i <= n; ++i) cin >> b[i-1];
		a[n] = 1, b[n] = c[n];
		ll ans = 0;
		vector<int> seg = { 1 };
		for (i = 1; i < n; ++i) {
			if (a[i] > b[i]) a[i] ^= b[i] ^= a[i] ^= b[i];
			if (a[i] == b[i]) seg.push_back(i);
		}
		seg.push_back(n);
		for (i = 0; i + 1 < seg.size(); ++i) {
			int st = seg[i], ed = seg[i+1];
			if (st == ed) continue;//11
			ll cyc = local_cyc(st, ed);
			if (ans < cyc) ans = cyc;
		}
		cout << ans << "\n";
		
	}
 
	return 0;
}