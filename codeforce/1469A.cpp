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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int sz = s.size();
		if (sz & 1) {
			cout << "NO\n";
			continue;
		}
		if (s[0] == ')' || s[sz - 1] == '(') {
			cout << "NO\n";
			continue;
 
		}
 
		cout << "YES\n";
	}
 
	return 0;
}