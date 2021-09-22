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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int cnt[2] = { 0 };
		for (auto c : s) {
			if (c == '0') ++cnt[0];
			else ++cnt[1];
		}
		if (cnt[0] == 0) cout << "0\n";
		else if (cnt[1] == 0) cout << "1\n";
		else {
			bool flag = 1;
			vector<int> pos;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == '0') pos.push_back(i);
			}
			for (int i = 1; i < pos.size(); ++i) {
				if (pos[i - 1] != pos[i] - 1) flag = 0;
			}
			if (flag) cout << "1\n";
			else cout << "2\n";
		}
	}
 
	return 0;
}