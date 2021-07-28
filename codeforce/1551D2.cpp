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
int tbl[111][111];
int clr(int i, int j,int v) {
	int val = tbl[i - 1][j] + 1; val %= 26;
	if (val == tbl[i][j - 1]) ++val;
	val %= 26;
	if (v && val == tbl[i + 1][j - 1]) ++val;
	return val % 26;
}
void print(int n,int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c = tbl[i][j] + 'a';
			cout << c;
		}
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	memset(tbl, -1, sizeof(tbl));
	while (t--) {
		int i, j;
		int n, m, k; cin >> n >> m >> k;
		int ix = 0;
		if (n & 1) {
			int line = m >> 1;
			int mx = n * line;
			if (n == 1) {
				if (line == k) {
					cout << "YES\n";
					for (j = 1; j <= m; j += 2) {
						int c = clr(1, j, 0);
						tbl[1][j] = tbl[1][j + 1] = c;
					}
					print(n, m);
				}
				else cout << "NO\n";
			}
			else if (mx < k) cout << "NO\n";
			else if (line > k) cout << "NO\n";
			else {
				k -= line;
				if (k & 1) cout << "NO\n";
				else {
					cout << "YES\n";
					for (j = 1; j <= m; j += 2) {
						int c = clr(1, j, 0);
						tbl[1][j] = tbl[1][j + 1] = c;
					}
					for (i = 2; i <= n; i += 2) {
						for (j = 1; j <= m; j += 2) {
							if (k > 0) {
								int c = clr(i, j, 0);
								tbl[i][j] = tbl[i][j + 1] = c;
								c = clr(i + 1, j, 0);
								tbl[i + 1][j] = tbl[i + 1][j + 1] = c;
								k -= 2;
							}
							else {
								int c = clr(i, j, 1);
								tbl[i][j] = tbl[i + 1][j] = c;
								c = clr(i, j + 1, 1);
								tbl[i][j + 1] = tbl[i + 1][j + 1] = c;
							}
						}
					}
					print(n, m);
				}
			}
		}
		else if (m & 1) {
			int line = m >> 1;
			int mx = n * line;
			if (m == 1 && k > 0) cout << "NO\n";
			else if (mx < k) cout << "NO\n";
			else if (k & 1) cout << "NO\n";
			else {
				cout << "YES\n"; //n>=2
				for (i = 1; i <= n;i+=2) {
					for (j = 1; j <= m;) {
						//if (k > 0 && (i & 1) && j + 1 <= m) {
						if (k > 0  && j + 1 <= m) {
							int c = clr(i, j,0);
							tbl[i][j] = tbl[i][j + 1] = c;
							c = clr(i + 1, j,0);
							tbl[i + 1][j] = tbl[i + 1][j + 1] = c;
							k -= 2;
							j += 2;
						}
						else {
							int c = clr(i, j,1);
							tbl[i][j] = tbl[i + 1][j] = c;
							++j;
						}
					}
				}
				print(n, m);
			}
 
		}
		else {
			if (k & 1) cout << "NO\n";
			else {
				cout << "YES\n";
				for (i = 1; i <= n; i += 2) {
					for (j = 1; j <= m; j += 2) {
						if (k > 0) {
							int c = clr(i, j,0);
							tbl[i][j] = tbl[i][j + 1] = c;
							c = clr(i + 1, j,0);
							tbl[i+1][j] = tbl[i+1][j + 1] = c;
							k -= 2;
						}
						else {
							int c = clr(i, j,1);
							tbl[i][j] = tbl[i+1][j] = c;
							c = clr(i, j+1,1);
							tbl[i][j+1] = tbl[i + 1][j+1] = c;
						}
					}
				}
				print(n, m);
			}
		}
	}
 
 
	return 0;
}
