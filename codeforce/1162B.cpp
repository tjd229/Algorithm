//graph, greedy
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[55][55];
int b[55][55];
int aa[55][55];
int bb[55][55];
int n, m;
bool flag = 1;
void swap(int &a, int &b) {
	a ^= b ^= a ^= b;
}
void dfs(int i,int j,int c[55][55]) {
	if (j > m) {
		dfs(i+1,1,c);
		return;
	}
	if (i > n) return;
	if (!flag) return;
	int &ae = a[i][j]; int &be = b[i][j];
	if (ae < be) {
		if (c[i][j - 1] < ae && c[i - 1][j] < ae) {
			c[i][j] = ae;
			ae = 2e9;
		}
		else if (c[i][j - 1] < be && c[i - 1][j] < be) {
			c[i][j] = be;
			be = 2e9;
		}
		else {
			flag = 0;
			return;
		}
	}
	else {
		if (c[i][j - 1] < be && c[i - 1][j] < be) {
			c[i][j] = be;
			be = 2e9;
		}
		else if (c[i][j - 1] < ae && c[i - 1][j] < ae) {
			c[i][j] = ae;
			ae = 2e9;
		}
		else {
			flag = 0;
			return;
		}
	}
	dfs(i, j + 1, c);
}
int main() {
	int i, j; cin >> n >> m;
	for (i = 1; i <= n + 1; ++i) {
		for (j = 1; j <= m + 1; ++j) aa[i][j]=bb[i][j]=a[i][j] = b[i][j] = 2e9;
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) cin >> a[i][j];
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) cin >> b[i][j];
	}
	dfs(1, 1, aa);
	dfs(1, 1, bb);
	if (flag == 0) {
		cout << "Impossible";
		return 0;
	}
	
	for (i = 1; i <= n && flag; ++i) {
		for (j = 1; j <= m; ++j) {
			if (aa[i][j] >= aa[i + 1][j] || aa[i][j] >= aa[i][j + 1]
				|| bb[i][j] >= bb[i + 1][j] || bb[i][j] >= bb[i][j + 1]) {
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}