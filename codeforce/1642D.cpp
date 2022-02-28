//implementation
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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[501];
int _swap(int l,int r, vector<pii > &op,int pad) {
	int len = r - l + 1;
	for (int i = 0; i < len; ++i) {
		int c = a[l + i];
		int p = r+i+pad;
		op.push_back({p,c});
	}
	while (l < r) {
		a[l] ^= a[r] ^= a[l] ^= a[r];
		++l; --r;
	}
	return len+len;
}
int find(int x,int n) {
	for (int i = 1; i <= n; ++i) {
		if (a[i] == x) return i;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		map<int, int> mp;
		vector<int> tandem, tgt;
		vector<pii > op;
		for (i = 1; i <= n; ++i) {
			cin >> a[i]; ++mp[a[i]];
		}
		bool flag = 0;
		for (auto it : mp) {
			if (it.second & 1) {
				flag = 1;
				break;
			}
			int seq = mp[it.first] = it.second / 2;
			for (int i = 0; i < seq; ++i) tgt.push_back(it.first);
		}
		if (flag) {
			cout << "-1\n";
			continue;
		}
		int pad = 0;
		vector<int> stk = tgt;
		int h = n >> 1;
		for (i = n; stk.size(); --i) {
			if (a[i] != stk.back()) {
				int right = stk.back();
				int pos = find(right,i);
				int t0 = _swap(1, pos, op, pad); pad += t0;
				int t1 = _swap(1, i, op, pad); pad += t1;
				tandem.push_back(t0); tandem.push_back(t1);
			}
			stk.pop_back();
		}
		stk = tgt;
		for (; stk.size(); --i) {
			if (a[i] != stk.back()) {
				int right = stk.back();
				int pos = find(right, i);
				int t0 = _swap(1, pos, op,pad); pad += t0;
				int t1 = _swap(1, i, op,pad); pad += t1;
				tandem.push_back(t0); tandem.push_back(t1);
			}
			stk.pop_back();
		}
		tandem.push_back(n);
		int q = op.size();
		cout << q << "\n";
		for (auto p : op) {
			cout << p.first << " " << p.second << "\n";
		}
		int d = tandem.size();
		cout << d << "\n";
		for (auto x : tandem) cout << x << " ";
		cout << "\n";
	}
 
 
	return 0;
}