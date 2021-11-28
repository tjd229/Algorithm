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
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		set<int> st;
		vector<int> v;
		for (i = 1; i <= n; ++i) cin >> a[i],st.insert(a[i]);
		if (st.size() <= 2) cout << "YES\n";
		else {
			int l=1, r=n;
			bool flag = 1;
			while (l <= r) {
				if (a[l] != a[r]) {
					v.push_back(a[l]);
					v.push_back(a[r]);
					flag = 0;
					break;
				}
				++l; --r;
			}
			if (flag) cout << "YES\n";
			else {
				for (auto x : v) {
					deque<int> dq;
					for (i = 1; i <= n; ++i) {
						if (a[i] != x) dq.push_back(a[i]);
					}
					flag = 1;
					while (dq.size() > 1) {
						if (dq.front() != dq.back()) {
							flag = 0;
							break;
						}
						dq.pop_back(); dq.pop_front();
					}
					if (flag) break;
				}
				if (flag) cout << "YES\n";
				else cout << "NO\n";
			}
		}
		
	}
 
	return 0;
}