//graph
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
		int xa, ya, xb, yb, xf, yf; cin >> xa >> ya >> xb >> yb >> xf >> yf;
		if (xa == xb && xa==xf) {
			int d = abs(ya - yb);
			int l = ya, r = yb;
			if (l > r) l ^= r ^= l ^= r;
			if (l < yf && yf < r) d += 2;
			cout << d << "\n";
		}
		else if (ya == yb && ya == yf) {
			int d = abs(xa - xb);
			int l = xa, r = xb;
			if (l > r) l ^= r ^= l ^= r;
			if (l < xf && xf < r) d += 2;
			cout << d << "\n";
		}
		else {
			int d = abs(xa - xb) + abs(ya - yb);
			cout << d << "\n";
		}
	}
 
	return 0;
}