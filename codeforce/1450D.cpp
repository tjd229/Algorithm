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
int a[300001],h[300001];
vector<int> pos[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		set<int> st;
		for (i = 1; i <= n; ++i) {
			cin >> a[i]; h[i] = 0;
			pos[i].clear();
		}
		for (i = 1; i <= n; ++i) pos[a[i]].push_back(i);
		if (pos[1].empty()) {
			for (i = 1; i <= n; ++i) cout << 0;
		}
		else {
			for (auto x : pos[1]) st.insert(x);
			h[n] = 1; int lock = 1; int comp = 2;
			st.insert(0); st.insert(1 + n);
			for (int i = 2; i <= n; ++i,++comp) {
				int mx = 0;
				for (auto x : pos[i]) {
					auto it = st.lower_bound(x);
					int r = *it;
					int l = *prev(it);
					int len = r - l -1;
					if (mx < len) mx = len;
				//	printf("%d,%d\n",r,l);
				}
				//printf("%d\n",mx);
				if(mx==n-i+1 && lock<=i)
					h[n-i+1] = 1;
				else { //mx<n-i+1;
					int tgt = n + 1 - mx;
					if (lock < tgt) lock = tgt;
					h[n - i + 1] = 0;
				}
				for (auto x : pos[i]) st.insert(x);
			}
 
 
			for (int i = 1; i <= n; ++i)
				cout << h[i];
		}
		cout << "\n";
		
	}
 
	return 0;
}