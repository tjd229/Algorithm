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
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int cnt[26] = { 0 };
		for (auto c : s) {
			++cnt[c - 'a'];
		}
		vector<int > v;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] == 0) continue;
			if (cnt[i] > 2) cnt[i] = 2;
			v.push_back(cnt[i]);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		while (v.size()) {
			ans += v.back();
			v.pop_back();
		}
		cout << (ans >> 1) << "\n";
		
	}
 
 
	return 0;
}