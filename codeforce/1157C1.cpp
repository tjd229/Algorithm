//greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[200001];
int main() {
	vector<pii > L, R;
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	if (n == 1) {
		cout << 1 << "\nR";
	}
	else {
		int l, r;
		priority_queue<pii > q;
		vector<pii > ans;
		l = 1; r = n;
		q.push({ -a[l++],0 }); q.push({-a[r--],1});
		while (q.size()) {
			pii p = q.top(); q.pop();
			int x = -p.first;
			if (ans.size() && ans.back().first > x) continue;
			ans.push_back({x,p.second});
			if(l<=r)
				q.push({p.second? -a[r--]:-a[l++],p.second});
		}
		cout << ans.size() << endl;
		for (auto p : ans) {
			if (p.second) cout << "R";
			else cout << "L";
		}
	}
	return 0;
}