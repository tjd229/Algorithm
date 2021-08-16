//dp
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
int d[101][2];
int c[101][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; string s; cin >> n >> s;
		d[0][0] = d[0][1] = 0;
		if (s[0] == 'R') d[0][1] = 1e9;
		else if (s[0] == 'B') d[0][0] = 1e9;
		for (i = 1; i < n; ++i) {
 
			if (d[i - 1][0] + 1 < d[i - 1][1]) {
				d[i][0] = d[i - 1][0] + 1;
				c[i][0] = 0;
			}
			else {
				d[i][0] = d[i - 1][1];
				c[i][0] = 1;
			}
			if (d[i - 1][1] + 1 < d[i - 1][0]) {
				d[i][1] = d[i - 1][1] + 1;
				c[i][1] = 1;
			}
			else {
				d[i][1] = d[i - 1][0];
				c[i][1] = 0;
			}
			if (s[i] == 'R') d[i][1] = 1e9;
			else if (s[i] == 'B') d[i][0] = 1e9;
 
		}
		int clr;
		if (d[n - 1][0] < d[n - 1][1]) clr = 0;
		else clr = 1;
		for (i = n - 1; i >= 0; --i) {
			s[i] = clr == 1 ? 'B' : 'R';
			clr = c[i][clr];
		}
		cout << s << "\n";
	}
 
 
	return 0;
}
