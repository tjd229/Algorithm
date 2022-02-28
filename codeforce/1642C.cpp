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
		int i, n,x; cin >> n>>x;
		for (i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + 1 + n);
		int ans = 0;
		multiset<ll> st;
		for (i = n; i > 0; --i) {
			ll m = a[i] * (ll)x;
			if (st.find(m) != st.end()) {
				auto it = st.find(m);
				st.erase(it);
			}
			else st.insert(a[i]);
		}
		
		cout <<st.size()<< "\n";
	}
 
 
	return 0;
}