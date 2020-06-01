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
		int a, b, c, d; cin >> a >> b >> c >> d;
		ll rest = b;
		if (rest < a) {
			int add = c - d;
			if (add <= 0) rest = -1;
			else {
				int need = a - rest;
				ll div = need / add;
				if (need%add) ++div;
				rest += div * c;
			}			
		}
		cout << rest << "\n";
	}
 
	return 0;
}