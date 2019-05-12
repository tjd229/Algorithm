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
int inv_world(vector<pii > &ans,int n) {
	int l, r;
	priority_queue<pii > q;
	l = 1; r = n;
	q.push({ -a[l++],1}); q.push({ -a[r--],0 });
	while (q.size()) {
		pii p = q.top(); q.pop();
		int x = -p.first;
		if (ans.size() && ans.back().first >= x) continue;
		ans.push_back({ x,p.second });
		if (l <= r)
			q.push({ p.second ? -a[l++] : -a[r--],p.second });
	}
}
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
		vector<pii > ans,ians;
		l = 1; r = n;
		q.push({ -a[l++],0 }); q.push({-a[r--],1});
		while (q.size()) {
			pii p = q.top(); q.pop();
			int x = -p.first;
			if (ans.size() && ans.back().first >= x) continue;
			ans.push_back({x,p.second});
			if(l<=r)
				q.push({p.second? -a[r--]:-a[l++],p.second});
		}
		bool inv = 0;
		inv_world(ians, n);
		if (ans.size() < ians.size()) inv = 1;
		if (inv) {
			cout<<ians.size()<<"\n";
			for (auto p : ians) {
				if (p.second)cout << "L";
				else cout << "R";
			}
		}
		else {
			cout << ans.size() << "\n";
			for (auto p : ans) {
				if (p.second)cout << "R";
				else cout << "L";
			}
		}
	}
	return 0;
}