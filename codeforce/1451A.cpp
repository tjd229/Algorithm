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
		if (n == 1) cout << "0\n";
		else if (n == 2) cout << "1\n";
		else if (n < 4) cout << "2\n";
		else if (n & 1) {
			cout << "3\n";
		}
		else cout << "2\n";
	}
 
	return 0;
}