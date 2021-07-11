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
		int i, n; cin >> n;
		int nn = n + n;
		int odd = 0, even = 0;
		for (i = 1; i <= nn; ++i) {
			int a; cin >> a;
			if (a & 1) ++odd;
			else ++even;
		}
		if (odd == even) cout << "Yes\n";
		else cout << "No\n";
	}
 
 
	return 0;
}