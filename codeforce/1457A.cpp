//math, geometry
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, r, c; cin >> n>> m >> r >> c;
		int lx = m - c, rx = m - lx-1;
		int uy = n - r, dy = n - uy - 1;
		int ans = 0;
		ans += max(lx, rx) + max(uy, dy);
		cout << ans << "\n";
	}
 
	return 0;
}