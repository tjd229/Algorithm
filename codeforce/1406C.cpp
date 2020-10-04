//graph
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
vector<int> edge[100001];
int sz[100001];
int val[100001];
int p[100001];
void dfs(int x, int from) {
	sz[x] = 1;
	for (auto nxt : edge[x]) {
		if (from == nxt) continue;
		dfs(nxt, x);
		p[nxt] = x;
		sz[x] += sz[nxt];
	}
}
int dfs2(int x, int from) {
	sz[x] = 1;
	int res = x;
	int mx = 0;
	for (auto nxt : edge[x]) {
		if (nxt == from) continue;
		int candi = dfs2(nxt, x);
		p[nxt] = x;
		sz[x] += sz[nxt];
		if (mx < sz[nxt]) {
			mx = sz[nxt];
			res = candi;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			sz[i] = 0; val[i] = 0;
			p[i] = 0;
			edge[i].clear();
		}
		for (i = 1; i < n; ++i) {
			int x, y; cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		dfs(1,0);
		for (i = 1; i <= n; ++i) {
			if (i == 1) val[i] = 0;
			else {
				val[i] = n - sz[i];
			}
			for (auto nxt : edge[i]) {
				if (nxt == p[i]) continue;
				val[i] = max(val[i], sz[nxt]);
			}
			//printf("%d:%d\n",i,val[i]);
		}
		int mn = 1e9;
		vector<int> cent;
		for (i = 1; i <= n; ++i) mn = min(mn, val[i]);
		for (i = 1; i <= n; ++i) {
			if (mn == val[i]) cent.push_back(i);
		}
		if (cent.size() == 1) {
			int x = 1;
			int y = edge[1][0];
			cout << x << " " << y << "\n";
			cout << x<< " " << y << "\n";
		}
		else {
			int x = cent[0], y = cent[1];
			int leafx = dfs2(x, y);
			//int leafy = dfs2(y, x);
			cout << leafx << " " << p[leafx] << "\n";
			cout << leafx << " " << y << "\n";
		}
 
	}
 
	return 0;
}
