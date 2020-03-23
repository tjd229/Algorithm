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
ll a[4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll u, v;
	cin >> u >> v;
	if (u == 0 && v == 0) {
		cout << 0;
		return 0;
	}
	if (u == v) {
		cout << "1\n" << v;
		return 0;
	}
	if (u > v) {
		cout << -1;
		return 0;
	}
	if (u == 0 && v != 0) {
		if (v & 1) {
			cout << -1;
		}
		else {
			v >>= 1;
			cout << "2\n" << v << " " << v;
		}
		return 0;		
	}
	a[1] = u;
	ll r = v - u;
	if (r & 1) {
		cout << -1;
		return 0;
	}
	ll b = 1;
	int n = 1;
	while (r) {
		if (r&b) {
			ll bb = b >> 1;
			
			if (a[1] & bb) {
				n = 3;
				a[2] += bb;
				a[3] += bb;
			}
			else {
				if (n == 1) n = 2;
				a[2] += bb;
				a[1] += bb;
			}
			r -= b;
		}
		b += b;
	}
	cout << n << "\n";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
 
	return 0;
}