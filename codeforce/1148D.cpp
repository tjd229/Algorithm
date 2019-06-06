//greedy, st
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
const int LEAF = 1 << 20;
int mx[LEAF+LEAF],mn[LEAF+LEAF];
int a[300001], b[300001];
int pos[600001];
int _min(int a,int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return min(a, b);
}
void upd_mx(int ix, int val) {
	mx[ix] = val;
	ix >>= 1;
	while (ix) {
		mx[ix] = max(mx[ix + ix], mx[ix + ix + 1]);
		ix >>= 1;
	}
}
void upd_mn(int ix, int val) {
	mn[ix] = val;
	ix >>= 1;
	while (ix) {
		mn[ix] = _min(mn[ix + ix], mn[ix + ix + 1]);
		ix >>= 1;
	}
}
int rmx(int ix,int s,int e,int from,int to) {
	if (to < s || e < from) return 0;
	if (from <= s && e <= to) return mx[ix];
	return max(rmx(ix+ix,s,(s+e)>>1,from,to),
		rmx(ix+ix+1,1+((s+e)>>1),e,from,to));
}
int rmn(int ix, int s, int e, int from, int to) {
	if (to < s || e < from) return 0;
	if (from <= s && e <= to) return mn[ix];
	return _min(rmn(ix + ix, s, (s + e) >> 1, from, to),
		rmn(ix + ix + 1, 1 + ((s + e) >> 1), e, from, to));
}
int main() {
	int i, n; cin >> n;
	vector<int> inc,dec;
	for (i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		if (a[i] < b[i]) {
			upd_mx(a[i]+LEAF,b[i]);
		}
		else {
			upd_mn(a[i] + LEAF, b[i]);
		}
		pos[b[i]] = i;
	}
	
	int top = mx[1];
	while (top) {
		i = pos[top]; inc.push_back(i);
		upd_mx(a[i] + LEAF, 0);
		top = rmx(1,0,LEAF-1,1,top);
	}
	top = mn[1];
	while (top) {
		i = pos[top]; dec.push_back(i);
		upd_mn(a[i]+LEAF,0);
		top = rmn(1,0,LEAF-1,top,LEAF);
	}
	if (inc.size() < dec.size()) {
		cout << dec.size() << endl;
		for (auto x : dec) cout << x << " ";
	}
	else {
		cout << inc.size() << endl;
		for (auto x : inc) cout << x << " ";
	}
	
	return 0;
}