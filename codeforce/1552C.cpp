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
int use[201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		vector<pii > p;
		vector<int> v;
		int nn = n + n;
		for (i = 1; i <= nn; ++i) use[i] = 0;
		for (i = 0; i < k; ++i) {
			int x, y; cin >> x >> y;
			use[x] = use[y] = 1;
			p.push_back({x,y});
		}
		for (i = 1; i <= nn; ++i) {
			if (use[i] == 0) v.push_back(i);
		}
		int r = v.size(); r >>= 1;
		for (i = 0; i < r; ++i) p.push_back({v[i],v[i+r]});
		int X = 0;
		for (i = 0; i < p.size(); ++i) {
			int x = p[i].first, y = p[i].second;
			for (int j = i + 1; j < p.size(); ++j) {
				int u = p[j].first, v = p[j].second;
				vector<pii > order = { {x,1},{y,1},{u,2},{v,2} };
				sort(order.begin(), order.end());
				if (order[1].second != order[0].second
					&& order[2].second != order[1].second
					&& order[3].second != order[2].second) ++X;
			}
		}
		cout << X << "\n";
	}
 
	return 0;
}