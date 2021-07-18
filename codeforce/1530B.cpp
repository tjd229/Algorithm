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
int tbl[21][21];
int tbl2[21][21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j, h, w; cin >> h >> w;
		for (i = 1; i <= h; ++i) for (j = 1; j <= w; ++j) tbl[i][j] = tbl2[i][j] = 0;
		int cnt = 0, cnt2 = 0;
		for (i = 1; i <= w; i += 2) tbl[1][i]=tbl[h][i] = 1,cnt+=2;
		for (i = 3; i < h-1; i += 2)
			tbl[i][1] = tbl[i][w] = 1,cnt+=2;
 
		for (i = 1; i <= h; i += 2) tbl2[i][1] = tbl2[i][w] = 1, cnt2 += 2;
		for (i = 3; i < w-1; i += 2)
			tbl2[1][i] = tbl2[i][w] = 1, cnt2 += 2;
		if (cnt < cnt2) {
			for (i = 1; i <= h; ++i) {
				for (j = 1; j <= w; ++j)
					cout << tbl2[i][j];
				cout << "\n";
			}
		}
		else {
			for (i = 1; i <= h; ++i) {
				for (j = 1; j <= w; ++j)
					cout << tbl[i][j];
				cout << "\n";
			}
		}
		
	}
 
	return 0;
}