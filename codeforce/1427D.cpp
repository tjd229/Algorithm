//implementation, djs
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
int c[53],d[53];
int p[53];
int sz[53];
int n;
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
bool dsu(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;
	p[b] = a;
	sz[a] += sz[b];
	return 1;
}
bool join() {
	for (int i = 1; i < n; ++i) {
		if (c[i] + 1 == c[i + 1]) dsu(c[i], c[i+1]);
	}
	return find(n) != 1;
}
int find_pos(int x) {
	for (int i = 1; i <= n; ++i) {
		if (c[i] == x) return i;
	}
	return -1;
}
void _shuffle(vector<int> &v) {
	int dix = 1;
	int cix = n;
	for (int i = v.size() - 1; i >= 0; --i) {
		int k = v[i];
		vector<int> stk;
		while (k--) stk.push_back(c[cix--]);
		while (stk.size()) d[dix++] = stk.back(), stk.pop_back();
	}
	for (int i = 1; i <= n; ++i) c[i] = d[i];
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i; cin >> n;
	for (i = 1; i <= n; ++i) cin >> c[i],p[i]=i,++sz[i];
	int dir = 1;
	for (i = 1; i < n && dir; ++i) {
		if (c[i] + 1 != c[i+1]) dir = 0;
	}
	if (dir) {
		cout << 0;
		return 0;
	}
	 dir = -1;
	for (i = 1; i < n && dir; ++i) {
		if (c[i] - 1 != c[1+i]) dir = 0;
	}
	if (dir) {
		cout << "1\n"<<n;
		for (i = 1; i <= n; ++i) cout << " 1";
		return 0;
	}
	vector<vector<int> > hist;
	while (join()) {
		vector<int> v;
		int tailtail = 1+n;
		int tail,mid;
		int piv;
		if (c[n] == n) {
			tailtail = find_pos(find(c[n]));
			piv = c[tailtail - 1];
		}
		else {
			piv = c[n];
		}
		tail = find_pos(find(piv));
		mid = find_pos(find(piv + 1));
		int tail_len = tailtail-tail;
		int mid_len = tail - mid;
		int tailtail_len = n + 1 - tailtail;
		if (mid == 1) {
			v = { mid_len,tail_len };
		}
		else {
			int head_len = n - tail_len - mid_len- tailtail_len;
			v = { head_len, mid_len,tail_len };			
		}
		if (tailtail_len>0) v.push_back(tailtail_len);
		
		_shuffle(v);
		//for (auto x : v) printf("%d\n",x);
		//cout << "\n";
		//for (i = 1; i <= n; ++i) printf("%d ",c[i]);
		//cout << "\n";
		//return 0;
		hist.push_back(v);
		//for (auto x : v) cout << x << " ";
		//int _; scanf("%d", &_);
	}
	cout << hist.size() << "\n";
	for (auto v : hist) {
		cout << v.size() << " ";
		for (auto x : v) cout << x << " ";
		cout << "\n";
	}
 
	return 0;
}