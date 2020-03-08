//math
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
int a[40002], b[40002];
ll bonus[40002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, m, k;
	ll ans = 0;
	cin >> n >> m >> k;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= m; ++i) cin >> b[i];
	vector<int> seg;
	int s = 0;
	for (i = 1; i <= n + 1; ++i) {
		if (a[i]) ++s;
		else if(s){
			seg.push_back(s);
			s = 0;
		}
	}
	for (auto x : seg) {
		int _x = x;
		while (x) {
			if (k%x == 0) {
				int d = k / x;
				if (d <= m) {
					bonus[d] += _x - x + 1;
				}
			}
			--x;
		}
	}
	s = 0;
	ll acc = 0;
	for (i = 1; i <= m; ++i) {
		if (b[i]) {
			++s;
			acc += bonus[s];
		}
		else {
			s = 0;
			acc = 0;
		}
		ans += acc;
	}
 
	cout << ans;
	return 0;
}