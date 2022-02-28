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
		map<int, int> mp;
		priority_queue<pii > q;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			++mp[a[i]];
		}
		for (auto it : mp) {
			q.push({it.second, it.first});
		}
		int str = n;
		vector<int> ans;
		for (i = 1; i <= n; ++i) {
			if (q.top().first == 1)
				ans.push_back(str);
			else {
				auto p = q.top(); q.pop();
				q.push({1,p.second});
				q.push({p.first-1,p.second});
				ans.push_back(str--);
			}
		}
		while (ans.size()) {
			cout << ans.back()<<" "; ans.pop_back();
		}
		cout << "\n";
	}
 
 
	return 0;
}