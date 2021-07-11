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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int cnt[26] = { 0 };
		int pos[26] = { 0 };
		for (auto c : s) cnt[c - 'a']++;
		for (int i = 0; i < s.size(); ++i) pos[s[i] - 'a'] = i;
		bool flag = 1;
		for (int i = 0; flag &&i < s.size(); ++i) {
			if (cnt[i] != 1) flag = 0;
		}
		if (flag) {
			string t = "a";
			for (int i = 1; flag &&i < s.size(); ++i) {
				if (pos[i] > pos[i - 1]) t = t + (char)('a' + i);
				else t = (char)('a' + i) + t;
			}
			if (t != s) flag = 0;
		}
 
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}