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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		if ((x + y) & 1) cout << "-1 -1\n";
		else {
			int a = x >> 1, b = y >> 1;
			if (x & 1) ++a;
			cout << a << " " << b << "\n";
		}
	}
 
	return 0;
}