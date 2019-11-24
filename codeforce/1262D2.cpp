//st
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
const int LEAF = 1 << 18;
int st[LEAF + LEAF];
int a[200001];
int ans[200001];
int k[200001], pos[200001];
vector<int> q[200001];
void upd(int ix,int val) {
	while (ix > 1) {
		st[ix] += val;
		ix >>= 1;
	}
}
int kth(int ix,int k) {
	if (ix >= LEAF) return ix-LEAF;
	int l = ix + ix;
	int r = l + 1;
	if (st[l] >= k) return kth(l,k);
	return kth(r,k-st[l]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n,m;
	vector<pii > order;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		order.push_back({-a[i],i});
	}
	sort(order.begin(), order.end());
	//for (i = 1; i <= n; ++i) upd(i+LEAF, 1);
	cin >> m;
	for (i = 0; i < m; ++i) {
		cin >> k[i] >> pos[i];
		q[k[i]].push_back(i);
	}
	int s = 1;
	for (i = 0; i < n; ++i) {
		
		int loc = order[i].second;
		upd(LEAF + loc, 1);
		for (auto x : q[s]) {
			int loc = pos[x];
			ans[x] = a[kth(1, loc)];
		}
		++s;
	}
 
	
	for (i = 0; i < m; ++i)
		cout << ans[i] << "\n";
	return 0;
}