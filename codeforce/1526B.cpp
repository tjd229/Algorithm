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
		int x; cin >> x;
		if (x < 11) cout << "NO\n";
		else {
			bool flag = 0;
			for (int b = 0;flag==0; ++b) {
				int t2 = b * 111;
				if (t2 > x) break;
				int r = x - t2;
				if (r % 11 == 0) flag = 1;
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		}
	}
 
	return 0;
}