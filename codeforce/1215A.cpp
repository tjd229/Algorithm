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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;
	int n; cin >> n;
	int ans1, ans2=0;
	if (k1 > k2) {
		k1 ^= k2 ^= k1 ^= k2;
		a1 ^= a2 ^= a1 ^= a2;
	}
	int mn = (a1 ) * (k1-1) + (a2 ) * (k2-1);
	int r = n - mn;
	if (r < 0) r = 0;
	ans1 = r;
	int mx = a1 * k1;
	
	if (mx < n) {
		ans2 = a1;
		n -= mx;
		ans2 += n / k2;
	}
	else {
		ans2 = n / k1;
	}
	cout << ans1 << " " << ans2;
	return 0;
}