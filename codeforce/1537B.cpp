//greedy

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
		int i, j, n, m; cin >> n >> m >> i >> j;
		int x1, y1, x2, y2;
		x1 = y1 = 1;
		x2 = n, y2=m;
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	}
 
 
	return 0;
}