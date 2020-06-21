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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 0;
		if (n == 2) ans = 1;
		else {
			if (n & 1) --n;
			ans = n >> 1;
		}
		cout << ans << "\n";
	}
 
	return 0;
}