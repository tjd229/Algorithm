//math
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
		int i, n; cin >> n;
		vector<pii > v;
		if (n > 8) {
			for (i = 9; i < n; ++i) v.push_back({ i,i + 1 });
			int x = n;
			while (x != 1) {
				v.push_back({n,8});
				x = x / 8 + ((x % 8) > 0);
			}
			for (i = 3; i < 8; ++i) v.push_back({ i,i + 1 });
			for (i = 0; i < 3; ++i) v.push_back({8,2});
		}
		else {
			for (i = 3; i < n; ++i) v.push_back({ i,i + 1 });
			int x = n;
			while (x != 1){
				v.push_back({n,2});
				x = x / 2 + ((x % 2) > 0);			
			}
		}
		cout << v.size() << "\n";
		for (auto p : v) cout << p.first << " " << p.second << "\n";
	}
 
	return 0;
}