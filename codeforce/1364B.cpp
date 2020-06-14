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
int p[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		deque<int> ans;
		for (int i = 1; i <= n; ++i) cin >> p[i];
		if (n == 2) {
			cout << "2\n";
			cout << p[1] << " " << p[2] << "\n";
		}
		else {
			ans.push_back(p[1]);
			for (int i = 2; i < n; ++i) {
				if (ans.back() < p[i] && p[i] < p[i + 1])//dd
					continue;
				if (ans.back() > p[i] && p[i] > p[i + 1])
					continue;
				ans.push_back(p[i]);
			}
			ans.push_back(p[n]);
			cout << ans.size() << "\n";
			while (ans.size()) {
				cout << ans.front() << " ";
				ans.pop_front();
			}
			cout << "\n";
		}
	}
 
	return 0;
}