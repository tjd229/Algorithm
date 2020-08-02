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
		int n8 = (n-1) / 4 + 1;
		n -= n8;
		while (n ) {
			cout << "9";
			--n;
		}
		while (n8) {
			cout << "8";
			--n8;
		}
		cout << "\n";
	}
 
	return 0;
}