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
		ll a, b; cin >> a >> b;
		if (a == b) {
			cout << "0 0\n";
		}
		else {
			if (a < b) a ^= b ^= a ^= b;
			ll d = abs(a - b);
			ll cnt = min(a, b);
			if (b%d) {
				ll r = b % d;
				cnt = min(cnt, r);
				cnt = min(cnt, d - r);
			}
			else cnt = 0;
			cout << d << " " << cnt << "\n";
		}
	}
 
	return 0;
}