//string
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
int scnt[26][100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		++scnt[c][i + 1];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j)
			scnt[j][i] += scnt[j][i - 1];
	}
	while (q--) {
		ll cnt = 0;
		int l, r; cin >> l >> r;
		for (int i = 0; i < 26; ++i) {
			int range = scnt[i][r] - scnt[i][l - 1];
			cnt += range * (i + 1);
		}
		cout << cnt << "\n";
	}
 
	return 0;
}