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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		vector<int> v;
		for (i = 1; i <= n; ++i) {
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (k == 1) {
			if (v.size() > 1) cout << "-1\n";
			else cout << "1\n";
		}
		else {
			int diff = v.size();
			int m = 1;
			diff -= k;
			while (diff > 0) {
				++m;
				diff -= k - 1;
			}
			cout << m << "\n";
			
		}
	}
 
	return 0;
}
