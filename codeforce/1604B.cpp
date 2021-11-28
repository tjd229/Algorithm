//greedy, math
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
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		if (n & 1) {
			bool flag = 0;
			for (i = 2; flag ==0 &&i <= n; ++i) {
				if (a[i] <= a[i - 1]) flag = 1;
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "YES\n";
	}
 
 
	return 0;
}