//implementation
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
int limit[51];
int main() {
	int n, h, m;
	int i;
	cin >> n >> h >> m;
	for (i = 1; i <= n; ++i) limit[i] = h;
	while (m--) {
		int l, r, x; cin >> l >> r >> x;
		for (i = l; i <= r; ++i) limit[i] = min(x,limit[i]);
	}
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		ans += limit[i] * limit[i];
	}
	cout << ans;
	return 0;
}