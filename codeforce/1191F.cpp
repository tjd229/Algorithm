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
const int LEAF = 1 << 18;
int st[LEAF + LEAF];
pii xy[200001];
vector<int> comp;
void upd(int ix) {
	st[ix] = 1;
	ix >>= 1;
	while (ix) {
		st[ix] = st[ix + ix] + st[ix + ix + 1];
		ix >>= 1;
	}
}
int sum(int ix,int s,int e,int from,int to) {
	if (from > to) return 0;
	if (e < from || to < s) return 0;
	if (from <= s && e <= to) return st[ix];
	int m = (s + e) >> 1;
	return sum(ix + ix, s, m, from, to) + sum(ix + ix + 1, m + 1, e, from, to);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int i,n;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		xy[i] = {-y,x};
		comp.push_back(x);
	}
	sort(xy + 1, xy + 1 + n);
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end())-comp.begin());
	i = 1;
	ll ans = 0;
	while (i <= n) {
		int y = xy[i].first;
		int minx = xy[i].second;
		int maxx = xy[i].second;
		vector<int> v;
		while (i <= n && xy[i].first == y) {
			maxx = xy[i].second;
			int compx = lower_bound(comp.begin(), comp.end(),maxx)- comp.begin();
			v.push_back(compx);
			upd(LEAF+compx);
			++i;
		}
		int last = -1;
		for (auto x : v) {
			//printf(" %d~%d~%d\n",last+1,x,LEAF-1);
			ll l = sum(1,0,LEAF-1,last+1,x);
			ll r = sum(1, 0, LEAF - 1, x, LEAF - 1);
			//printf("%lld,%lld\n",l,r);
			ans += l * r;
			last = x;
		}
	}
	cout << ans;
	return 0;
}