//greedy, math
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
int b[500001];
int a[500001];
int lb[500001], rb[500001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; int n; cin >> n;
		vector<pii > evt;
		set<int> st;
		for (i = 1; i <= n; ++i) {
			cin >> b[i];
			lb[i] = i / (b[i] + 1) + 1;
			rb[i] = b[i]? i/b[i]:n;
 
			evt.push_back({ rb[i],i });
			st.insert(i);
		}
		sort(evt.begin(), evt.end());
		for (auto e : evt) {
			i = e.second;
			auto it = st.lower_bound(lb[i]);
			a[i] = *it; st.erase(it);
		}
		
		for (i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << "\n";
		/*for (i = 1; i <= n; ++i) cout << i/a[i] << " ";
		cout << "\n";*/
	}
 
 
	return 0;
}