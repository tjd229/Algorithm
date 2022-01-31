//implementation
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,n; 
		string s; cin >> n >> s;
		if (n == 2) {
			if (s[0] == s[1]) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if (n <= 2) cout << "YES\n";
		else cout << "NO\n";
	}
 
 
	return 0;
}