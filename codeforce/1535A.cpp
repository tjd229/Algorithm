//implementation
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
int s[5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s[1] >> s[2] >> s[3] >> s[4];
		int mx1 = max(s[1], s[2]);
		int mx2 = max(s[3], s[4]);
		sort(s + 1, s + 1 + 4);
		bool flag = 0;
		if (mx1 > s[2] && mx2 > s[2]) flag = 1;
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}