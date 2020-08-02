//graph, tp sort, greedy
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
int ind[200001];
ll a[200001];
int b[200001];
int bk[200001];
vector<int> edge[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	for (i = 1; i <= n; ++i) {
		cin >> b[i];
		if (b[i] > 0) {
			++ind[b[i]];
		}
	}
	queue<int> q;
	for (i = 1; i <= n; ++i) {
		if (ind[i] == 0) q.push(i);
	}
	
	while (q.size()) {
		int x = q.front(); q.pop();
		//printf("%d\n",x);
		if (b[x] == -1) continue;
		int nxt = b[x];
		if (a[x] < 0) bk[x] = 1;
		else a[nxt] += a[x];
		if (--ind[nxt] == 0) q.push(nxt);
	}
 
	for (i = 1; i <= n; ++i) {
		if (b[i] == -1) continue;
		int u = i, v = b[i];
		if (bk[i]) {
			u ^= v ^= u ^= v;
		}
		//printf("%d,%d\n",u,v);
		edge[u].push_back(v);
		++ind[v];
	}
	for (i = 1; i <= n; ++i) if (ind[i] == 0) q.push(i);
	vector<int> order;
	ll ans = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		//printf("%d\n", x);
		order.push_back(x);
		ans += a[x];
		for (auto nxt : edge[x]) {
			if (--ind[nxt] == 0) q.push(nxt);
		}
	}
	cout << ans << "\n";
	for (auto x : order) cout << x << " ";
 
	return 0;
}