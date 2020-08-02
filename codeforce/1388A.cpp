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
	vector<int> np = {6,10,14};
	int sum = 6 + 10 + 14;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n <= 30) cout << "NO\n";
		else {
			vector<int> ans;
			if (n == 36) {
				ans.push_back(6); ans.push_back(10);
				ans.push_back(5); ans.push_back(15);
			}
			else if (n == 40) {
				ans.push_back(6); ans.push_back(14);
				ans.push_back(5); ans.push_back(15);
 
			}
			else if (n == 44) {
				ans.push_back(6); ans.push_back(10);
				ans.push_back(13); ans.push_back(15);
 
			}
			else {
				ans = np;
				ans.push_back(n-sum);
			}
			cout << "YES\n";
			for (auto x : ans) cout << x << " ";
			cout << "\n";
		}
	}
 
	return 0;
}