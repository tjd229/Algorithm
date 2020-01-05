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
string s[20], t[20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> s[i];
	for (int i = 0; i < m; ++i) cin >> t[i];
	int q; cin >> q;
	while (q--) {
		int y; cin >> y;
		--y;
		int rn = y % n, rm = y % m;
		cout << s[rn] << t[rm] << "\n";
	}
 
	return 0;
}