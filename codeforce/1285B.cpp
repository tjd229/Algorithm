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
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll l = 0, r = 0;
		bool fl = 0, fr = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (i = 1; i < n; ++i) {
			l += a[i];
			fl |= (l <= 0);
		}
		for (i = n; i > 1; --i) r+=a[i], fr |= (r <= 0);
		if (fl || fr) cout << "NO\n";
		else cout << "YES\n";
		
	}
 
	return 0;
}