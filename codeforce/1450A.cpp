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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; string a;
		cin >> n >> a;
		vector<char> b;
		int cnt = 0;
		for (auto c : a) {
			if (c == 't') ++cnt;
			else b.push_back(c);
		}
		for (auto c : b) cout << c;
		while (cnt--) cout << 't';
		cout << "\n";
	}
 
	return 0;
}