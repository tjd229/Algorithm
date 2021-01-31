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
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (n > k) {
			int ans;
			if (n%k == 0) ans = 1;
			else ans = 2;
			cout << ans << "\n";
		}
		else if (n == k) cout << "1\n";
		else {
			int ans = k / n;
			ans += (k % n) > 0;
			cout << ans  << "\n";
		}
	}
 
	return 0;
}