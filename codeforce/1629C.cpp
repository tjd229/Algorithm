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
int a[300001];
deque<int> pos[200011];
int n;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; cin >> n;
		vector<int> b;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) pos[a[i]].push_back(i);
		
		int k = 0;
		while (k < n) {
			int mex = 0;
			int nxt=++k;
			for (mex = 0;; ++mex) {
				if (pos[mex].empty()) break;
				nxt = max(pos[mex].front(),nxt);
			}
			for (i = 0; i <= mex; ++i) {
				while (pos[i].size() && pos[i].front() <= nxt)
					pos[i].pop_front();
				
			}
			k = nxt;
			int x = a[k];
			while (pos[x].size() && pos[x].front() <= k)
				pos[x].pop_front();
			b.push_back(mex);
		}
		cout << b.size() << "\n";
		for (auto x : b) cout << x << " ";
		cout << "\n";
		for (i = 0; i <= n; ++i) pos[i].clear();
	}
 
 
	return 0;
}