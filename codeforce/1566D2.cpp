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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
int seat[300][300];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,j, n, m; cin >>n>> m;
		int ans = 0;
		int nm = n * m;
		vector<pii > v;
		for (i = 0; i < nm; ++i) {
			cin >> a[i];
			v.push_back({a[i],i});
		}
		for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) seat[i][j] = 0;
		sort(v.begin(), v.end());
		i = j = 0;
		set<pair<int, pii > > st;
		for (int k = 0; k < v.size(); ++k) {
			st.insert({ v[k].first,{i,-j} });
			++j;
			if (j == m) {
				j = 0; ++i;
			}
		}
		for (i = 0; i < nm; ++i) {
			auto it = st.lower_bound({ a[i] ,{0,-1000} });
			int val,col, row;
			row = it->second.first, col = it->second.second;
			col = -col;
			for (int j = 0; j < col; ++j) {
				if (seat[row][j]) ++ans;
			}
			seat[row][col] = 1;
			st.erase(it);
		}
 
		cout << ans << "\n";
	}
 
 
	return 0;
}