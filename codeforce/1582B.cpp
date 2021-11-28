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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[61];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int cnt[2] = { 0 };
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 0) cnt[0]++;
			else if (a[i] == 1) cnt[1]++;
		}
		ll ans = 1LL << cnt[0];
		cout << ans * cnt[1] << "\n";
	}
 
 
	return 0;
}