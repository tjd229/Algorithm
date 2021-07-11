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
		int i, n, a, b;
		set<int> st;
		cin >> n >> a >> b;
		ll base = 1;
		bool flag = 0;
		while (base <= n && flag==0) {
			ll diff = n - base;
			if (diff%b == 0) flag = 1;
			int mod = diff % b;
			if (st.find(mod) != st.end()) break;
			st.insert(mod);
			base *= a;
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
 
	return 0;
}