//string, greedy
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
string s[100001];
bool chk(string &s) {
	int l = 0, r = s.size() - 1;
	while (l <= r) {
		if (s[l] != s[r]) return 0;
		++l; --r;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> s[i];
		bool flag = 0;
		for (i = 1; flag==0 &&i <= n; ++i) {
			flag |= chk(s[i]);
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			set<string> buck2, buck3;
			for (i = n; i > 0 && flag==0; --i) {
				if (s[i].size() == 2) {
					string t = s[i];
 
					if (buck2.find(t) != buck2.end())
						flag = 1;
					auto it = buck3.lower_bound(t);
					if (it != buck3.end()) {
						string p = *it;
						if (p[0] == t[0] && p[1] == t[1]) flag = 1;
					}
					reverse(t.begin(), t.end());
					buck2.insert(t);
				}
				else {
					string t = s[i];
					if (buck3.find(t) != buck3.end())
						flag = 1;
					reverse(t.begin(), t.end());
					buck3.insert(t);
					t = s[i];
					t.pop_back();
					if (buck2.find(t) != buck2.end())
						flag = 1;
				}
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
 
	return 0;
}