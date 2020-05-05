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
ll s[10001];
int a[10001];
void beautiful(vector<int> &v) {
	for (auto x : v) {
		
		cout << x << " ";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		set<int> st;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			st.insert(a[i]);
		}
		
		if (st.size() > k) {
			cout << "-1\n";
			continue;
		}
		ll sub = 0;
		int cnt = st.size();
		vector<int> v;
		for (auto it : st) {
			sub += it;
			v.push_back(it);
		}
		for (int i = cnt; i < k; ++i)
			v.push_back(*st.begin());
		cout << k * n << "\n";
		for (int i = 1; i <= n; ++i) {
			//cout << a[i] << " ";
			beautiful( v);
		}
		cout << "\n";
		
	}
 
	return 0;
}