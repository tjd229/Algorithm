//greedy, string
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
string word[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> word[i];
		int ans = 0;
		for (i = 0; i < 5; ++i) {
			vector<int> v;
			int pick = 0;
			for (int j = 1; j <= n; ++j) {
				int curr = 0;
				for (auto c : word[j]) {
					if (c == 'a' + i) ++curr;
				}
				int other = word[j].size() - curr;
				v.push_back(curr-other);
			}
			sort(v.begin(), v.end());
			int val = 0;
			while (v.size()) {
				if (val + v.back() > 0) {
					val += v.back(); v.pop_back();
					++pick;
				}
				else break;
			}
			if (ans < pick) ans = pick;
		}
		cout << ans << "\n";
		
	}
 
 
	return 0;
}
