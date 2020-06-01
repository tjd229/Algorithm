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
		int n, x; cin >> n >> x;
		vector<int> odd, even;
		for (int i = 1; i <= n; ++i) {
			int a; cin >> a;
			if (a & 1) odd.push_back(a);
			else even.push_back(a);
		}
		if (odd.empty()) {
			cout << "No\n";
			continue;
		}
		int sum = odd.back(); --x;
		odd.pop_back();
		while (x > 1 && odd.size() > 1) {
			x -= 2;
			sum += odd.back(); odd.pop_back();
			sum += odd.back(); odd.pop_back();
		}
		while (x && even.size()) {
			--x;
			sum += even.back(); even.pop_back();
		}
		if (x || (sum & 1) == 0)
			cout << "No\n";
		else cout << "Yes\n";
		
	}
	return 0;
}