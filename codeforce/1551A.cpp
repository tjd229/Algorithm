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
		int n; cin >> n;
		
		int d = n / 3;
		int diff = n - d * 3;
		int c1 = d, c2 = d;
		if (diff == 2) ++c2;
		else if (diff == 1) ++c1;
		cout << c1 << " " << c2 << "\n";
 
	}
 
 
	return 0;
}