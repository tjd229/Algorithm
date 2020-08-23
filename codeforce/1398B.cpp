//greedy, game
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
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int cnt = 0;
		char last = -1;
		vector<int> v;
		for (auto c : s) {
			if (c == '1') ++cnt;
			else {
				v.push_back(cnt);
				cnt = 0;
			}
			last = c;
		}
		if (last == '1') v.push_back(cnt);
		sort(v.begin(), v.end());
		int score = 0;
		while (v.size()) {
			score += v.back(); v.pop_back();
			if (v.size()) v.pop_back();
		}
		cout << score << "\n";
		
	}
 
	return 0;
}