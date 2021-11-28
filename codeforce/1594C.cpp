//greedy, math
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
int on[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; char c;
		string s; cin >> n >> c >> s;
		for (i = 1; i <= n; ++i) on[i] = 0;
		int diff = 0;
		for (auto si : s)
			diff += si != c;
		if (diff == 0)
			cout << "0\n";
		else if (diff == 1) {
			int pos = -1;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] != c) pos = i;
			}
			++pos;
			if (pos == n) cout << "1\n" << pos - 1 << "\n";
			else cout << "1\n" << pos + 1 << "\n";
		}
		else {
			vector<int> diff, r;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] != c) {
					diff.push_back(i + 1);
					on[i + 1] = 1;
				}
				else r.push_back(1 + i);
			}
			if (diff.back() + 1 <= n)
				cout << "1\n" << diff.back() + 1 << "\n";
			else {
				int one = 0;
				for (auto x : r) {
					int chk = 0;
					for (int pos = x; pos <= n && chk == 0; pos += x) {
						chk += on[pos];
					}
					if (chk == 0) {
						one = x;
						break;
					}
				}
				if (one)
					cout << "1\n" << one << "\n";
				else {
					cout << "2\n";
					cout << n << " " << n - 1 << "\n";
				}
			}
		}
 
	}
 
	return 0;
}