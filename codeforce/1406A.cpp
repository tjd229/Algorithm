//greedy
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
int cnt[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 0; i <= 100; ++i) cnt[i] = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			++cnt[a[i]];
		}
		int ans = 0;
		for (i = 0; i <= 100; ++i) {
			if (cnt[i] == 0) {
				ans += i;
				break;
			}
			--cnt[i];
		}
		for (i = 0; i <= 100; ++i) {
			if (cnt[i] == 0) {
				ans += i;
				break;
			}
			--cnt[i];
		}
		cout << ans << "\n";
	}
 
	return 0;
}
