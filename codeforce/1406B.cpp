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
		int i, n; cin >> n;
		vector<int> p, m;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] >= 0) p.push_back(a[i]);
			else m.push_back(a[i]);
		}
		ll ans = 1;
		for (i = 1; i <= 5; ++i) ans *= a[i];
		if(p.size())
			sort(p.begin(), p.end());
		if (m.size()) sort(m.begin(), m.end());
 
		if (p.size() >= 5) {
			ll val = 1;
			for (i = 1; i <= 5; ++i) val *= p[p.size()-i];
			if (ans < val) ans = val;
		}
		if (p.size() >= 1 && m.size() >= 4) {
			ll val = 1;
			for (i = 1; i <= 1; ++i) val *= p[p.size() - i];
			for (i = 0; i < 4; ++i) val *= m[i];
			if (ans < val) ans = val;
			//cout << val << endl;
		}
		if (p.size() >= 3 && m.size() >= 2) {
			ll val = 1;
			for (i = 1; i <= 3; ++i) val *= p[p.size() - i];
			for (i = 0; i < 2; ++i) val *= m[i];
			if (ans < val) ans = val;
		}
		if (p.size() >= 4 && m.size() >= 1) {
			ll val = 1;
			for (i = 0; i < 4; ++i) val *= p[i];
			for (i = 1; i <= 1; ++i) val *= m[m.size() - i];
			if (ans < val) ans = val;
		}
		if (p.size() >= 2 && m.size() >= 3) {
			ll val = 1;
			for (i = 0; i < 2; ++i) val *= p[i];
			for (i = 1; i <= 3; ++i) val *= m[m.size() - i];
			if (ans < val) ans = val;
		}
		if (m.size() >= 5) {
			ll val = 1;
			for (i = 1; i <= 5; ++i) val *= m[m.size()-i];
			if (ans < val) ans = val;
		}
		cout << ans << "\n";
	}
 
	return 0;
}
