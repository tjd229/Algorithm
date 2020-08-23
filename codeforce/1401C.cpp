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
int a[100001];
int gcd(int a, int b) {
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j,n; cin >> n;
		vector<int > order;
		vector<int> v;
		//set<int> st;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			order.push_back(a[i]);
			//st.insert(a[i]);
		}
		sort(order.begin(), order.end());
		int mn = order[0];
		for (auto x : order) {
			if (x%mn == 0) v.push_back(x);
		}
		int ix = 0;
		for (i = 0; i < n; ++i) {
			if (a[i] % mn == 0) a[i] = v[ix++];
		}
 
		bool flag = 1;
		for (i = 0; i < n && flag; ++i) {
			if (a[i] != order[i]) flag = 0;
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}