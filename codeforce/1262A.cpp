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
	int t,i;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int b = 0, a = 2e9;
		for (i = 0; i < n; ++i) {
			int l, r; cin >> l >> r;
			if (a > r) a = r;
			if (b < l) b = l;
		}
		//printf("%d,%d\n",a,b);
		if (a > b) cout << 0 << "\n";
		else cout << b - a << "\n";
	}
 
	return 0;
}