//graph, djs, greedy
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
int p[200001];
int l[200001], r[200001];
int find(int a) {
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}
bool un(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	if (l[a] > l[b]) l[a] = l[b];
	if (r[a] < r[b]) r[a] = r[b];
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		p[i] = l[i] = r[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		un(u, v);
	}
	for (int src = 1; src <= n;) {
		int i;
		for (i = src; i <= r[find(src)]; ++i) {
			ans += un(i, src);
		}
		src = i;
	}
	cout << ans << "\n";
	return 0;
}
