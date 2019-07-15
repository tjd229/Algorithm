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
string tile[50000];
int col[50000];
int row[50000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int n, m; cin >> n >> m;
		int ans = n * m;
		for (int i = 0; i < n; ++i) {
			cin >> tile[i];
			row[i] = 0;
			for (auto c : tile[i]) {
				row[i] += c == '.';
			}
		}
		for (int j = 0; j < m; ++j) {
			col[j] = 0;
			for (int i = 0; i < n; ++i) {
				col[j] += tile[i][j] == '.';
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int need = col[j] + row[i] - (tile[i][j] == '.');
				if (ans > need) ans = need;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}