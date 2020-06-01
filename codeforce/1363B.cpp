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
char tgt[1000];
int dist(string &s) {
	int d = 0;
	for (int i = 0; i < s.size(); ++i)
		d += (s[i] != tgt[i]);
	return d;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		for (int i = 0; i < s.size(); ++i) tgt[i] = '0';
		int ans = dist(s);
		for (int i = 0; i < s.size(); ++i) {
			tgt[i] = '1';
			int d = dist(s);
			if (ans > d) ans = d;
		}
		for (int i = 0; i < s.size(); ++i) tgt[i] = '1';
		int d = dist(s);
		for (int i = 0; i < s.size(); ++i) {
			tgt[i] = '0';
			int d = dist(s);
			if (ans > d) ans = d;
		}
		cout << ans << "\n";
	}
 
	return 0;
}