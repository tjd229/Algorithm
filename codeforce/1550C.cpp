//line sweeping, geometry
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
int a[200001];
inline int md(int x1, int y1, int x2, int y2) {
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	return dx + dy;
}
bool chk(int l,int r) {
	if (r - l + 1 > 4) return 0;
	if (r - l + 1 < 3) return 1;//1 or 2
	//3 or 4
	if (r - l + 1 >= 3) {
		int d[3] = { md(a[l],l,a[l + 1],l + 1), md(a[l],l,a[l + 2],l + 2), md(a[l + 1],l + 1,a[l + 2],l + 2) };
		sort(d, d + 3);
		//printf("%d,%d,%d\n", d[0], d[1], d[2]);
		if (d[2] == d[0] + d[1]) return 0;
	}
	if (r - l + 1 ==4) {
		int d[3] = { md(a[l+3],l+3,a[l + 1],l + 1), md(a[l+3],l+3,a[l + 2],l + 2), md(a[l + 1],l + 1,a[l + 2],l + 2) };
		sort(d, d + 3);
		//printf("%d,%d,%d\n",d[0],d[1],d[2]);
		if (d[2] == d[0] + d[1]) return 0;
		int dd[3] = { md(a[l + 3],l + 3,a[l ],l), md(a[l + 3],l + 3,a[l + 2],l + 2), md(a[l],l,a[l + 2],l + 2) };
		sort(dd, dd + 3);
		//printf("%d,%d,%d\n", dd[0], dd[1], dd[2]);
		if (dd[2] == dd[0] + dd[1]) return 0;
		int ddd[3] = { md(a[l + 3],l + 3,a[l],l), md(a[l + 3],l + 3,a[l + 1],l + 1), md(a[l],l,a[l + 1],l + 1) };
		sort(ddd, ddd + 3);
		//printf("%d,%d,%d\n", dd[0], dd[1], dd[2]);
		if (ddd[2] == ddd[0] + ddd[1]) return 0;
	}
	return 1;
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		ll ans = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int l = 1, r = 1;
		for (r = 1; r <= n; ++r) {
			while (chk(l, r) == 0) ++l;
			ans += r - l + 1;
		}
		cout << ans << "\n";
		
	}
 
	return 0;
}
