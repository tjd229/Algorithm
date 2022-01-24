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
int a[300001];
int b[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int l, r, k; cin >> l >> r >> k;
		if (l == 1 && r == 1) cout << "NO\n";
		else {
			if (l == r) {
				cout << "YES\n";
				continue;
			}
			int len = r - l + 1;
			int odd = len >> 1;
			if ((len & 1) && (l & 1)) ++odd;
			int need = odd;
			if (need <= k) cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
 
	return 0;
}