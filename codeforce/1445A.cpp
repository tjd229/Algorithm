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
int a[101], b[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, x; cin >> n >> x;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) cin >> b[i];
		sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n,[](const int a, const int b) {
			return a > b;
		});
		bool flag = 1;
		for (i = 1; i <= n; ++i) {
			if (a[i] + b[i] > x) flag = 0;
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
		
	}
 
	return 0;
}