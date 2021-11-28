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
int w[1001][5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			for (j = 0; j < 5; ++j) cin >> w[i][j];
		}
		int f, s;
		bool flag = 0;
		for (f = 0; f < 5 && flag==0; ++f) {
			for (s = f + 1; s < 5 && flag==0; ++s) {
				int g1 = 0, g2 = 0;
				int any = 0;
				for (i = 1; i <= n; ++i) {
					if (w[i][f] && w[i][s]) ++any;
					else if (w[i][f] == 0 && w[i][s] == 0) break;
					else if (w[i][f]) ++g1;
					else ++g2;
				}
				//printf("%d,%d: %d,%d,%d\n",f,s,g1,g2,any);
				if (g1 + g2 + any != n) continue;
				int half = n >> 1;
				if (g1 < half) {
					int d = half - g1;
					any -= d;
					g1 += d;
				}
				if (g2 < half) {
					int d = half - g2;
					any -= d;
					g2 += d;
				}
				if (any != 0) continue;
				if (g1 != g2) continue;
				flag = 1;
 
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}