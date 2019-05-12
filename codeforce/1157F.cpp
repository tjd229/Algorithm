//djs, greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int p[200005];
int sz[200005];
int l[200005], r[200005];
int a[200005],cnt[200005];
int find(int a) {
	if (p[a] != a)p[a] = find(p[a]);
	return p[a];
}
bool un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	sz[a] += sz[b];
	if (l[a] > l[b]) l[a] = l[b];
	if (r[a] < r[b]) r[a] = r[b];
	
	return 1;
}
int main() {
	int i, n;
	cin >> n;
	priority_queue<pii > q;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		sz[a[i]]++;
		cnt[a[i]]++;
	}
	for (i = 1; i <= 200000; ++i) {
		p[i] = l[i] = r[i] = i;
		if (sz[i]>1) q.push({sz[i],i});
	}
	if (q.empty()) {
		for (i = 1; i <= 200000; ++i) {
			if (cnt[i - 1] + cnt[i] == 2) {
				cout << 2 << "\n" << i << " " << i - 1;
				return 0;
			}
		}
		cout << 1 << "\n" << a[1];
		return 0;
	}
	while (q.size()>1) {
		auto p = q.top(); q.pop();
		int x = p.second;
		if (x != find(x)) continue;
		bool in = 0;
		if (sz[find(l[x] - 1)] > 1) in|=un(x, l[x] - 1);
		if (sz[find(r[x] + 1)] > 1) in|=un(x, r[x] + 1);
		if(in)q.push({sz[x],x});
	}
	int mx = 0;
	int pick = 0;
	for (i = 1; i <= 200000; ++i) {
		if (i != find(i)) continue;
		if (sz[i] <= 1) continue;
		int size = sz[i] + sz[l[i] - 1] + sz[r[i] + 1];
		
		if (mx < size) {
			mx = size;
			pick = i;
		}
	}
	cout << mx << "\n";
	//return 0;
	for (i = pick; i >= l[pick]; --i) {
		cout << i << " ";
		--cnt[i];
	}
	if (cnt[i]--) cout << i << " ";
	for (i = l[pick]; i < pick; ++i) {
		while (cnt[i]) {
			--cnt[i];
			cout << i << " ";
		}
	}
	for (i = pick; i <= r[pick]; ++i) {
		cout << i << " ";
		--cnt[i];
	}
	if (cnt[i]--) cout << i << " ";
	for (i = r[pick]; i >= pick; --i) {
		while (cnt[i]) {
			--cnt[i];
			cout << i << " ";
		}
	}
	return 0;
}