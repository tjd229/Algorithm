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
int a[301];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, m; cin >>n>> m;
		int ans = 0;
		for (i = 1; i <= m; ++i) cin >> a[i];
		for (i = 1; i <= m; ++i) {
			for (int j = 1; j < i; ++j) {
				if (a[i] > a[j]) ++ans;
			}
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}