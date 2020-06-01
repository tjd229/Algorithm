//line sweeping
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
vector<int> pos[4];
int it[4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		pos[1].clear(); pos[2].clear(); pos[3].clear();
		for (int i = 0; i < s.size(); ++i) {
			int d = s[i] - '0';
			pos[d].push_back(i);
		}
		it[1] = it[2] = it[3] = 0;
		if (pos[1].empty() || pos[2].empty() || pos[3].empty())
			cout << "0\n";
		else {
			int ans = 1e9;
			pos[1].push_back(1e9);
			pos[2].push_back(1e9);
			pos[3].push_back(1e9);
			for (int i = 0; i < s.size(); ++i) {
				int d = s[i] - '0';
				int r = 0;
				for (int k = 1; k <= 3; ++k) {
					if (k == d) continue;
					while ( it[k]<pos[k].size() && pos[k][it[k]] < i) ++it[k];			
					if (r < pos[k][it[k]]) r = pos[k][it[k]];
				}
				int len = r - i + 1;
				if (ans > len) ans = len;
			}
			cout << ans << "\n";
		}
	}
 
	return 0;
}