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
int col[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int ans = 0;
		for (i = 0; i < n; ++i) col[i+1] = 0;
		string s; cin >> s;
		for (i = 0; i < n; ++i) {
			if (s[i] == '1') ++col[i + 1];
		}cin >> s;
		for (i = 0; i < n; ++i) {
			if (s[i] == '1') ++col[i + 1];
		}
		for (i = 1; i <= n;) {
			if (col[i] == 1) {
				ans += 2;
				++i;
			}
			else if (col[i] == 0) {
				if (i < n && col[i + 1] == 2) {
					ans += 2;
					i += 2;
				}
				else {
					ans += 1;
					++i;
				}
			}
			else {
				if (i < n && col[i + 1] == 0) {
					ans += 2;
					i += 2;
				}
				else ++i;
			}
		}
		cout << ans << "\n";
		
	}
 
	return 0;
}