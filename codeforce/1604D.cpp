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
		
		if (x == y) cout << x << "\n";
		else if (x < y) {
			int d = y / x;
			int xx = d * x;
			int n = (xx + y) >> 1;
			cout << n << "\n";
 
			//cout << n%x << "\n";
			//cout << y%n << "\n";
		}
		else {
			ll n = (ll)x*y + y;
			cout << n << "\n";
		}
		
	}
 
 
	return 0;
}