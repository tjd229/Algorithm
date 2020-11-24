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
int acnt[26], bcnt[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		for (i = 0; i < 26; ++i) acnt[i] = bcnt[i] = 0;
		for (i = 0; i < n; ++i) {
			char c; cin >> c;
			acnt[c-'a']++;
		}
		for (i = 0; i < n; ++i) {
			char c; cin >> c;
			bcnt[c - 'a']++;
		}
		bool flag = 1;
		int stk = 0;
		for (i = 0; i < 26 && flag; ++i) {
			int mn = min(acnt[i], bcnt[i]);
			acnt[i] -= mn;
			bcnt[i] -= mn;
			stk += acnt[i];
			stk -= bcnt[i];
			if (stk < 0) flag = 0;
			if (acnt[i] % k || bcnt[i]%k) flag = 0;
		}
		if (acnt[25]) flag = 0;
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
 
	return 0;
}