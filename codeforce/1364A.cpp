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
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		ll sum = 0;
		vector<int> pos;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] % x) pos.push_back(i);
			sum += a[i];
		}
		if (sum%x) cout << n;
		else if (pos.empty()) cout << -1;
		else {
			int fr = pos[0];
			int bk = pos.back();
			int frl = n - fr;
			int bkl = n-(n + 1 - bk);
			int ans = frl < bkl ? bkl : frl;
			cout << ans;
		}
		cout << "\n";
	}
 
	return 0;
}