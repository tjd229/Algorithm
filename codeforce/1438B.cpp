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
		set<int> st;
		bool flag = 0;
		for (i = 1; i <= n; ++i) {
			int b; cin >> b;
			if (st.find(b) != st.end()) {
				flag = 1;
			}
			else st.insert(b);
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}