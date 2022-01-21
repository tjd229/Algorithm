//math
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
int s[20][200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,t; cin >> t;
 
	for (int i = 0; i < 18; ++i) {
		int base = 1 << i;
		for (int j = 0; j < 200001; ++j) {
			s[i][j] = (base & j) > 0;
		}
		for (int j = 0; j < 200001; ++j) s[i][j] += s[i][j - 1];
	}
	while (t--) {
		int i, l, r; cin >> l >> r;
		if (l == r) cout << "0\n";
		else {
			int tot = r - l + 1;
			int ans = tot - 1;
			for (i = 0; i < 18; ++i) {
				int cnt = s[i][r] - s[i][l - 1];
				if (ans > tot - cnt) ans = tot - cnt;
			}
			cout << ans << "\n";
		}
	}
 
 
	return 0;
}