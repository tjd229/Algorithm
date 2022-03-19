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
int decomp(int x,vector<int> &v) {
	int cnt = 0;
	int unq = 0;
	for (ll i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			ll val = 1; ++unq;
			while (x%i == 0) {
				x /= i; v.push_back(i);
			}
		}
	}
	if (x > 1) v.push_back(x),++unq;
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; int x, d; cin >> x >> d;
		int c = 0;
		int n = x;
		while (n%d == 0) {
			++c; n /= d;
		}
		if (c <= 1) cout << "NO\n";
		else {
			int r = n;
			vector<int> v; decomp(r, v);
			if (v.size() > 1) cout << "YES\n";
			else {
				v.clear();
				if (c < 3) cout << "NO\n";
				else {
					decomp(d, v);
					if (v.size() == 1) cout << "NO\n";
					else {
						if ( r*r == d && c==3)cout << "NO\n";
						else cout << "YES\n";
					}
				}
			}
			

		}
	}


	return 0;
}