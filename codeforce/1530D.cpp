//greedy
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
int a[200001], b[200001];
int deg[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			deg[i] = 0;
		}
		for (i = 1; i <= n; ++i) {
			++deg[a[i]];
		}
		int k = 0; vector<int> seat;
		vector<int> r;
		for (i = 1; i <= n; ++i) {
			if (deg[i] == 0) ++k, seat.push_back(i);
		}
		for (i = 1; i <= n; ++i) {
			if (deg[a[i]] == 1) b[i] = a[i];
			else {
				--deg[a[i]];
				b[i] = seat.back();
				seat.pop_back();
			}
		}
		vector<int> v;
		for (i = 1; i <= n; ++i) {
			if (b[i] == i) {
				v.push_back(i);
			}
		}
		int sz = v.size();
		if (sz == 1) {
			int x = v[0];
			int wanna = a[x];
			int e = 0;
			for (i = 1; i <= n; ++i) {
				if (b[i] == wanna) {
					e = i;
					break;
				}
			}
			b[x] = a[x];
			b[e] = x;
		}
		else {
			for (i = 0; i < sz; ++i) {
				int x = v[i];
				int y = v[(i + 1) % sz];
				b[x] = y;
			}
		}
 
		k = n - k; cout << k << "\n";
		for (i = 1; i <= n; ++i) cout << b[i] << " ";
		cout << "\n";
 
	}
 
	return 0;
}
