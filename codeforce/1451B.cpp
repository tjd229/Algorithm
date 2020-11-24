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
string s;
bool chk(int l, int r) {
	char piv = s[l];
	--l;
	while (l >= 0) {
		if (s[l] == piv) return 1;
		--l;
	}
	piv = s[r]; ++r;
	while (r < s.size()) {
		if (s[r] == piv) return 1;
		++r;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, q; cin >> n >> q >> s;
		while (q--) {
			int l, r; cin >> l >> r;
			if (chk(l - 1, r - 1)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
	return 0;
}