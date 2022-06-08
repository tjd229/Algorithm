//string
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
int cnt[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int i, n; cin >> n;
		int nn = n + n;
		for (i = 0; i < 26; ++i) cnt[i] = 0;
		for (i = 1; i <= nn; ++i) {
			string t; cin >> t;
			for (auto c : t) {
				++cnt[c - 'a'];
			}
		}
		string s; cin >> s;
		for (auto c : s) ++cnt[c - 'a'];
		for (i = 0; i < 26; ++i) {
			if (cnt[i] & 1) {
				char ans = 'a' + i;
				cout << ans << "\n";
				break;
			}
		}
 
	}
 
 
	return 0;
}