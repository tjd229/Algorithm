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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int tbl[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j, n, m; cin >> n >> m;
		for (i = 1; i <= n; ++i) for (j = 1; j <= m; ++j) cin >> tbl[i][j];
		vector<int> v,order;
		for (j = 1; j <= m; ++j) {
			for (i = 1; i <= n; ++i) {
				int head; cin >> head;
				if (j == 1) {
					v.push_back(head);
				}
			}
		}
		int head = v[0];
		int col = -1;
		for (i = 1; i <= n && col<0; ++i) {
			for (j = 1; j <= m&& col<0; ++j) {
				if (head == tbl[i][j])
					col = j;
			}
		}
		for (auto x : v) {
			for (i = 1; i <= n; ++i) {
				if (tbl[i][col] == x) {
					order.push_back(i);
					break;
				}
			}
		}
		for (auto rix : order) {
			//printf("!%d\n",cix);
			for (j = 1; j <= m; ++j) cout << tbl[rix][j] << " ";
			cout << "\n";
		}
	}
 
	return 0;
}