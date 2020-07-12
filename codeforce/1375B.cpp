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
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int a[302][302];
int b[302][302];
int n, m;
bool chk() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] > 4) return 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i][1] > 3) return 0;
		if (a[i][m] > 3) return 0;
	}
	for (int j = 1; j <= m; ++j) {
		if (a[1][j] > 3) return 0;
		if (a[n][j] > 3) return 0;
	}
	if (a[1][1] > 2 || a[1][m]>2 || a[n][1]>2 || a[n][m]>2) return 0;
	return 1;
}
void good() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = 4;
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i][1] = a[i][m] = 3;
	}
	for (int j = 1; j <= m; ++j) {
		a[1][j] = a[n][j] = 3;
	}
	a[1][1] = a[1][m] = a[n][1]  = a[n][m] = 2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j; cin >> n >> m;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) cin >> a[i][j];
		}
		if (chk() == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			good();
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= m; ++j) cout << a[i][j] << " ";
				cout << "\n";
			}
		}
	}
 
	return 0;
}
