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
		int A, B; cin >> A >> B;
		if (B == 1) {
			cout << "NO\n";
		}
		else {
			if (B == 2) B += 2;
			cout << "YES\n";
			ll x = A, y = (ll)A * (B - 1);
			ll z = x + y;
			cout << x << " " << y << " " << z << "\n";
		}
	}
 
 
	return 0;
}