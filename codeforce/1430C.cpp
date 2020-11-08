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
		if (n == 2) {
			cout << "2\n1 2\n";
		}
		else if (n == 3) {
			cout << "2\n1 3\n2 2\n";
		}
		else {
			vector<pii > ans;
			ans.push_back({n-2,n});
			ans.push_back({ n - 1,n - 1 });
			--n;
			while (n > 3) {
				ans.push_back({n-2,n});
				--n;
			}
			ans.push_back({ 1,3 });
			cout << "2\n";
			for (auto p : ans)
				cout << p.first << " " << p.second << "\n";
		}
	}
 
 
	return 0;
}