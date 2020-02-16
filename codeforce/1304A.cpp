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
		ll x, y, a, b; cin >> x >> y >> a >> b;
		ll d = y - x;
		ll ab = a + b;
		if (d%ab) {
			cout << "-1\n";
		}
		else
			cout << d / ab << "\n";
	}
 
	return 0;
}