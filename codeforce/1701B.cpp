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
		int i; int n; cin >> n;
		vector<int> p;
		int d = 2;
		set<int> st;
		for (i = 1; i <= n; ++i) st.insert(i);
		while (st.size()) {
			ll x = *st.begin();
			while (st.find(x)!=st.end()) {
				p.push_back(x); st.erase(x);
				x = x * d;
			}
		}
		cout << d << "\n";
		for (auto x : p) cout << x << " ";
		cout << "\n";
	}
 
 
	return 0;
}