//math, greedy
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
int vis[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,n; 
		cin >> n; 
		int mx = 0;
		for (i = 0; i < n; ++i) {
			vis[i] = 0;
			if (i - (i&-i) == 0) {
				if (mx < i) mx = i;
			}
		}
		int base = mx;
		vector<int> p,pre; int tic = 0;
		while (mx < n) {
			if (tic == 0) {
				p.push_back(mx-base);
				p.push_back(mx);
				vis[mx - base] = vis[mx] = 1;
			}
			else {
				p.push_back(mx);
				p.push_back(mx-base);
				vis[mx - base] = vis[mx] = 1;
			}
			tic = 1 - tic;
			++mx;
		}
		for (i = 0; i < n; ++i) {
			if (vis[i] == 0) pre.push_back(i);
		}
		for (auto x : pre) cout << x << " ";
		for (auto x : p) cout << x << " ";
		cout << "\n";
 
 
	}
 
 
	return 0;
}