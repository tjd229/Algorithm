//math, greedy
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
int a[2001];
int gcd(int a, int b) {
	if (a > b) a ^= b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int e = 0;
		int ans = 0;
		vector<int> v;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if ((a[i] & 1) == 0) ++e;
			else v.push_back(a[i]);
		}
		for (i = 0; i < e; ++i) ans += n - i - 1;
		for (i = 0; i < v.size(); ++i) {
			for (int j = i + 1; j < v.size(); ++j) {
				int d = gcd(v[i], v[j] + v[j]);
				if (d > 1) ++ans;
			}
		}
 
		cout << ans << "\n";
		
	}
 
 
	return 0;
}