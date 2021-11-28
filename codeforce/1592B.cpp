//implementation
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
int a[200001],b[200001];
int s[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, x; cin >> n >> x;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			s[i] = 0;
		}
		sort(b + 1, b + 1 + n);
		vector<int> v,rem; 
		for (i = 1; i <= n; ++i) {
			if (a[i] != b[i]) {
				v.push_back(i);
				s[i] = 1;
			}
		}
		for (i = 1; i <= n; ++i) s[i] += s[i - 1];
		bool flag = 1;
		for (i = 0; flag &&i < v.size(); ++i) {
			int left = 0, right = 0;
			if (v[i] > 1 && v[i] - 1 >= x) left = 1;
			if (v[i] < n && n - v[i] >= x) right = 1;
			if (left + right == 0) flag = 0;
 
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}