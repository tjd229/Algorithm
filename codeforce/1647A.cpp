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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		vector<int> ans1, ans2;
		int x = n;
		int base = 2;
		while (x) {
			if (x - base < 0) break;
			x -= base;
			ans2.push_back(base);
			base ^= 3;
		}
		x = n; base = 1;
		while (x) {
			if (x - base < 0) break;
			x -= base;
			ans1.push_back(base);
			base ^= 3;
		}
		if (ans1.size() < ans2.size()) {
			for (auto d : ans2) cout << d;
		}
		else if (ans1.size() > ans2.size()) {
			for (auto d : ans1) cout << d;
		}
		else {
 
			for (auto d : ans2) cout << d;
		}
		cout << "\n";
	}
 
 
	return 0;
}