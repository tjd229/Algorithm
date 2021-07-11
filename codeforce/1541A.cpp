//greedy
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
		if (n == 2) {
			cout << "2 1\n";
		}
		else if (n == 3) {
			cout << "3 1 2\n";
		}
		else if (n & 1) {
			cout << "3 1 2 ";
			for (i = 4; i <= n; i += 2)
				cout << i + 1 << " " << i << " ";
			cout << "\n";
		}
		else {
			for(i=1;i<=n;i+=2)
				cout << i + 1 << " " << i << " ";
			cout << "\n";
		}
	}
 
 
	return 0;
}