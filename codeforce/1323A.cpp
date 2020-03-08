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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int ans = -1;
		for (i = 1; i <= n && ans<0; ++i) {
			if ((a[i] & 1) == 0) {
				ans = i;
				break;
			}
		}
		if (ans < 0) {
			int sum = 0;
			vector<int> v;
			for (i = 1; i <= n; ++i) {
				if (a[i] & 1) sum += a[i], v.push_back(i);
				if (sum > 0 && (sum & 1) == 0) {
					break;
				}
			}
			if (sum > 0 && (sum & 1) == 0) {
				cout << v.size() << "\n";
				for (auto x : v)cout << x << " ";
				cout << "\n";
			}
			else cout << "-1\n";
		}
		else
			cout << 1 << "\n" << ans << "\n";
	}
 
	return 0;
}