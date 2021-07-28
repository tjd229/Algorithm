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
		int n, m, k; cin >> n >> m >> k;
		if (n & 1) {
			int line = m >> 1;
			int mx = n * line;
			if (n == 1) {
				if (line == k) cout << "YES\n";
				else cout << "NO\n";
			}
			else if (mx < k) cout << "NO\n";
			else if (line > k) cout << "NO\n";
			else {
				k -= line;
				if (k & 1) cout << "NO\n";
				else cout << "YES\n";
			}
		}
		else if (m & 1) {
			int line = m >> 1;
			int mx = n * line;
			if (m == 1 && k > 0) cout << "NO\n";
			else if (mx < k) cout << "NO\n";
			else if (k & 1) cout << "NO\n";
			else cout << "YES\n";
 
		}
		else {
			if (k & 1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
 
 
	return 0;
}