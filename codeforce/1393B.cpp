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
int cnt[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n,q; cin >> n;
	map<int, int> mp;
	priority_queue<pii > pq;
	for (i = 1; i <= n; ++i) {
		int a; cin >> a;
		++cnt[a];
		pq.push({cnt[a],a});
	}
	cin >> q;
	vector<pii > v;
	while (q--) {
		char cmd;
		int x;
		cin >> cmd >> x;
		if (cmd == '+') ++cnt[x];
		else --cnt[x];
		pq.push({cnt[x],x});
 
		while (pq.size() && v.size()<3) {
			pii p = pq.top(); pq.pop();
			x = p.second;
			if (cnt[x] != p.first) continue;
			int req = v.empty()? 4:2;
			int mn = min(req, cnt[x]);
			v.push_back({ x,mn }); cnt[x] -= mn;
			pq.push({cnt[x],x});		
 
		}
		/*for (auto p : v) {
			printf("%d,%d\n",p.first,p.second);
		}*/
		if (v.size() < 3) cout << "NO\n";
		else {
			if (v[0].second == 4 && v[1].second == 2 && v[2].second == 2)
				cout << "YES\n";
			else cout << "NO\n";
		}
		while (v.size()) {
			int add = v.back().second;
			x = v.back().first;
			v.pop_back();
			cnt[x] += add;
			pq.push({ cnt[x],x });
		}
 
	}
 
	return 0;
}