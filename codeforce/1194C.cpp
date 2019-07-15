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
bool sub(string &a,string &b) { //chk a in b
	int i = 0;
	for (auto c : b) {
		if (i == a.size()) break;
		if (a[i] == c) ++i;
	}
	return i == a.size();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		char need[26] = { 0 };
		string s, t, p; cin >> s >> t >> p;
		for (auto c : t) 
			++need[c-'a'];
		for (auto c : s) --need[c - 'a'];
		for (auto c : p) {
			int d = c - 'a';
			if (need[d] > 0) --need[d];
		}
		bool flag = 1;
		for (int i = 0; i < 26 && flag; ++i) {
			if (need[i]) {
				flag = 0;
			}
		}
		if (!sub(s, t)) flag = 0;
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}