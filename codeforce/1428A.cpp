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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2)
			cout << "0\n";
		else if (x1 == x2 || y1 == y2) {
			int dx = x1 - x2;
			int dy = y1 - y2;
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			cout << dx + dy << "\n";
		}
		else {
			int dx = x1 - x2;
			int dy = y1 - y2;
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			cout << dx + dy + 2 << "\n";
		}
	}
 
	return 0;
}