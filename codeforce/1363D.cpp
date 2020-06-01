//bs
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
int c[1001];
vector<int> S[1001];
int use[1001];
int pwd[1001];
vector<int> remain;
int qry(int s,int e, bool r=0) {
	int sz = 0;
	for (int i = s; i <= e; ++i) sz += c[i];
	if (r) sz += remain.size();
	cout << "? " << sz << " ";
	for (int i = s; i <= e; ++i) {
		for (auto x : S[i])
			cout << x << " ";
	}
	if (r) {
		for (auto x : remain)
			cout << x << " ";
	}
	cout << endl;
	int x; cin >> x;
	return x;
}
int find_mx(int s,int e,int val) {
	if (s == e) return s;
	int m = (s + e) >> 1;
	int x = qry(s, m);
	if (val == x) return find_mx(s, m, val);
	else return find_mx(m + 1, e, val);
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int stamp = t + 1;
		remain.clear();
		for (int i = 1; i <= k; ++i) {
			cin >> c[i];
			S[i].clear();
			for (int j = 0; j < c[i]; ++j) {
				int e; cin >> e;
				S[i].push_back(e);
				use[e] = stamp;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (use[i] != stamp)
				remain.push_back(i);
		}
 
		if (k == 1) {
			int ans = qry(-1,0,1);
			cout << "! " << ans << endl;
			string res; cin >> res;
			continue;
		}
 
		int mx = qry(1, k, 1);
		int m = k >> 1;
		int l = qry(1,m);
		int top = 0;
		
		if (l == mx) top = find_mx(1,m,l);
		else top = find_mx(m + 1, k, mx);
 
		
		int sz = 0;
		vector<int> SS;
		for (int i = 1; i <= k; ++i) {
			if (i == top) continue;
			pwd[i] = mx;
			sz += c[i];
			for (auto e : S[i]) SS.push_back(e);
		}
		for (auto e : remain) SS.push_back(e);
		sz += remain.size();
 
		cout << "? " << sz << " ";		
		for (auto e : SS)
			cout << e << " ";		
		cout << endl;
 
		cin >> pwd[top];
 
		cout << "! ";
		for (int i = 1; i <= k; ++i) cout << pwd[i] << " ";
		cout << endl;
		
		string res; cin >> res;
	}
 
 
	return 0;
}