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
int a[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		int y = 0;
		int a = 0, b = 0;
		ll base = 1;
		while (a == 0 ) {
			if (a == 0) {
				if (x&base) {
					y += base;
					a = 1;
				}
			}
			base += base;
		}
		if (y == x) {
			base = 1;
			while (1) {
				if ((x&base) == 0) {
					y += base;
					break;
				}
				base += base;
			}
			
		}
		cout << y << "\n";
	}
 
 
	return 0;
}