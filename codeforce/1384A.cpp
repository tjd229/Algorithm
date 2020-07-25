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
int a[101];
string s[102];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int mx = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			mx = max(a[i], mx);
		}
		if (mx == 0) {
			s[1] = "a";
			for (i = 2; i <= n + 1; ++i) {
				s[i] = s[i - 1] == "a" ? "b" : "a";
			}
		}
		else {
			s[1] = ""; s[2] = "";
			for (i = 1; i <= mx; ++i) s[1] += 'a',s[2]+='a';
			for (i = a[1]; i <= mx; ++i) s[2][i] = 'b';
			
			for (i = 2; i <= n; ++i) {
				s[i + 1] = s[i];
				char diff = 'a';
				if (a[i] < mx) {
					diff = s[i][a[i]] + 1;
					if (diff >= 'z') diff = 'a';
				}
				for (int j = a[i]; j <= mx; ++j) s[i + 1][j] = diff;
			}
		}
		for (i = 1; i <= n + 1; ++i) cout << s[i] << "\n";
	}
 
	return 0;
}