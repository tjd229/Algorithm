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
		int i, n; string s; cin >> n >> s;
		int l = -1, r = -1;
		for (int i = 0; i < n && l == -1; ++i) {
			int na = 0, nb = 0;
			if (s[i] == 'a') ++na;
			else ++nb;
			for (int j = i + 1; j < n && l == -1; ++j) {
				if (s[j] == 'a') ++na;
				else ++nb;
				if (na == nb) {
					l = i, r = j;
				}
			}
		}
		if (l != -1) {
			++l; ++r;
		}
		cout << l << " " << r << "\n";
	}
 
	return 0;
}