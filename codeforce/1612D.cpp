//math, greedy
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
		ll a, b, x; cin >> a >> b>>x;
		if (a == x || b == x) cout << "YES\n";
		else {
			if (a > b) a ^= b ^= a ^= b;
			if (b < x) {
				cout << "NO\n";
				continue;
			}
			bool flag = 0;
			while (flag==0) {
				if (a > b) a ^= b ^= a ^= b;
				if (b < x) {
					break;
				}
				ll dist = b - a;
				if (dist > a) {
					ll delta = b - dist;
					if (delta == 0) break;
					ll r = dist % delta;
					if (x > a) {
						if (x%delta == r) {
							flag = 1;
						}
					}
 
					b = a; a = r;
				}
				else b = a, a = dist;
				//printf("%lld,%lld\n", a,b);
				if (b == x || a == x) flag = 1;
				if (a == 0 || b==0) break;
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		}
		
	}
 
	return 0;
}