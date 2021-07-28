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
int r[50001][5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int top = 1;
		for (i = 1; i <= n; ++i) {
			for (int j = 0; j < 5; ++j) cin >> r[i][j];
		}
		for (i = 2; i <= n; ++i) {
			int win = 0;
			for (int j = 0; j < 5; ++j) {
				if (r[top][j] < r[i][j]) ++win;
			}
			if (win < 3) top = i;
		}
		for (i = 1; i <= n && top!=-1; ++i) {
			if (i == top) continue;
			int win = 0;
			for (int j = 0; j < 5; ++j) {
				if (r[top][j] <r[i][j]) ++win;
			}
			if (win < 3) top = -1;
		}
		cout << top << "\n";
	}
 
 
	return 0;
}