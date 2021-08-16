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
int p[3][100001];
 
int find(int a, int *p) {
	if (p[a] != a) p[a] = find(p[a], p);
	return p[a];
}
bool dsu(int a, int b, int *p) {
	a = find(a, p); b = find(b, p);
	if (a == b) return 0;
	//p[b] = a;
	return 1;
}
bool dsu2(int a, int b, int *p) {
	a = find(a, p); b = find(b, p);
	if (a == b) return 0;
	p[b] = a;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pii > ans;
	vector<int> D,M;
	int i, n, m1, m2; cin >> n >> m1 >> m2;
	for (i = 1; i <= n; ++i) p[0][i] = p[1][i] = i;
	for (i = 0; i < m1; ++i) {
		int u, v; cin >> u >> v;
		//dsu(u, v, p[0]);
		u = find(u, p[0]), v = find(v, p[0]);
		p[0][v] = u;
	}
	for (i = 0; i < m2; ++i) {
		int u, v; cin >> u >> v;
		//dsu(u, v, p[1]);
		u = find(u, p[1]), v = find(v, p[1]);
		p[1][v] = u;
	}
	int piv = 1;
	for (i = 1; i <= n; ++i) {
		if (piv == i) continue;
		int t1 = dsu(i, piv, p[0]), t2 = dsu(i, piv, p[1]);
 
		if (t1 && t2) {
			ans.push_back({ i,piv });
			int u = find(i, p[0]), v = find(piv, p[0]);
			p[0][v] = u;
			u = find(i, p[1]), v = find(piv, p[1]);
			p[1][v] = u;
		}
	}
	for (i = 1; i <= n; ++i) {
		if (piv == i) continue;
		int t1 = dsu(i, piv, p[0]), t2 = dsu(i, piv, p[1]);
		if (t1 && t2);
		else if (t1) D.push_back(i);
		else if (t2) M.push_back(i);
	}
 
	while (1) {
		while (D.size()) {
			int t1 = dsu(piv, D.back(), p[0]), t2 = dsu(piv, D.back(), p[1]);
			if (t1==0&&t2==0) D.pop_back();
			else break;
		}
		while (M.size()) {
			int t1 = dsu(piv, M.back(), p[0]), t2 = dsu(piv, M.back(), p[1]);
			if (t1==0&&t2==0) M.pop_back();
			else break;
		}
		if (D.empty() || M.empty()) break;
		dsu2(D.back(), M.back(), p[0]);
		dsu2(D.back(), M.back(), p[1]);
		ans.push_back({D.back(),M.back()});
		D.pop_back(); M.pop_back();
	}
 
	
	
	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << p.first << " " << p.second << "\n";
	}
 
	return 0;
}