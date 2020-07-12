//math, greedy
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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int pos = 1;
		for (i = 1; i <= n; ++i) {
			if (pos && a[i] < 0) a[i] = -a[i];
			else if (pos == 0 && a[i] > 0) a[i] = -a[i];
			pos = 1 - pos;
		}
		for (i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << "\n";
	}
 
	return 0;
}
