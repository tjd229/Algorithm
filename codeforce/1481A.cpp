//geometry

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
		int px, py; string s; cin >> px >> py >> s;
		int lx = 0, rx = 0, uy = 0, dy = 0;
		for (auto c : s) {
			if (c == 'U') ++uy;
			else if (c == 'D') --dy;
			else if (c == 'L')--lx;
			else ++rx;
		}
		if (lx <= px && px <= rx && dy <= py && py <= uy)
			cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}