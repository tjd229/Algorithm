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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[1001][1001];
int c[1011][1011];
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1 ,0,0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j, n; cin >> n;
		int ans = 0;
		for (i = 1; i <= n; ++i) for (j = 1; j <= n; ++j) cin >> a[i][j];
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				int clr = 0;
				for (int k = 0; k < 4; ++k) {
					int x = j + dx[k],y=i+dy[k];
					clr += c[y][x] != 1 + t;
				}
				if (clr == 4) {
					for (int k = 0; k < 4; ++k) {
						int x = j + dx[k], y = i + dy[k];
						c[y][x] =1 + t;
					}
					ans ^= a[i][j];
				}
			}
		}
		cout << ans << "\n";
	}


	return 0;
}