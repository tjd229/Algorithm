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
int a[51];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i]; s += a[i];
		}
		if (s == n) cout << "0\n";
		else if (s < n) cout << "1\n";
		else cout << s - n << "\n";
	}
 
 
	return 0;
}