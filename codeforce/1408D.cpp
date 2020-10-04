//line swepping
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
const int inf = 1e9;
int a[2001], b[2001], c[2001], d[2001];
int bndx[1500010],bndy[1500010];
void init(vector<pii > &order,int *bnd) {
	vector<pii > v;
	v.push_back({-1,inf});
	for (int i = 1; i < order.size(); ++i) {
		while (v.size() && v.back().second <= order[i].second)
			v.pop_back();
		v.push_back(order[i]);
	}
	int x = v.back().first;
	int y = v.back().second;
	v.pop_back();
	while (v.size()) {
		int nxt = v.back().first;
		while (x > nxt) bnd[x--] = y;
		y = v.back().second;
		v.pop_back();
 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(bndy, -1, sizeof(bndy));
	int i, j, n, m; cin >> n >> m;
	for (i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	vector<pii > vx,vy,v;
	vx.push_back({-1,inf});
	for (i = 1; i <= m; ++i) {
		cin >> c[i] >> d[i];
		vx.push_back({ c[i],d[i] });
	}
	sort(vx.begin(), vx.end()); 
	//init
	init(vx, bndy); 
 
 
	int r = vx.back().first;
	int x = r;
	int mxx = x;
	//printf("%d\n",x);
	for (i = vx.size() - 1; i >= 0; --i) {
		int nxt = vx[i].first;
		while (x > nxt) {
			bndx[x--] = r;
		}
		r = vx[i].first;
	}
	//for (i = 0; i < 10; ++i) printf("%d ", bndx[i]);
	int safe = 0;
	for (i = 1; i <= n; ++i) {
		if (bndy[a[i]] < b[i]) ++safe;
		else v.push_back({ a[i],b[i] });
	}
	if (safe == n) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	int ans = inf;
	int mvx = 0;
	while (safe < n) {
		int mvy = -1;
		int nxt = inf;
		for (i = 0; i < v.size(); ++i) {
			int x = v[i].first, y = v[i].second;
			if (bndy[x] < y) continue;
			int mv = bndy[x] - y + 1;
			mvy = max(mvy, mv);
			nxt = min(nxt, bndx[x] - x + 1);
		}
		//printf("%d,%d\n",mvx,mvy);
		ans = min(ans, mvx + mvy);
		for (i = 0; i < v.size(); ++i) {
			int x = v[i].first, y = v[i].second;
			if (bndy[x] < y) continue;
			x += nxt;
			v[i] = { x,y };
			if (bndy[x] < y) ++safe;
		}
		mvx += nxt;
	}
	ans = min(ans, mvx);
	cout << ans;
	
 
	return 0;
}