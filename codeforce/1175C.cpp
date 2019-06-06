//line sweeping
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
ll a[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, T;
	cin >> T;
	while (T--) {
		ll mn = 2e9;//diff
		ll ix1, ix2;
		int n, k; cin >> n >> k;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		if (!k) cout << a[1] << endl;
		else {
			int l = 1, r = 1;
			while (r - l < k) ++r;
			for (; r <= n; ++r, ++l) {
				ll d = a[r] - a[l];
				if (d < mn) {
					mn = d;
					ix1 = l;
					ix2 = r;
				}
			}
			ll ans = (a[ix1] + a[ix2]) >> 1;
			if (mn & 1) ++ans;
			cout << ans << endl;
		}
		
	}
	
	return 0;
}