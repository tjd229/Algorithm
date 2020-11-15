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
int a[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		int h = n >> 1;
		for (i = n; i > h; --i) cout << -a[i] << " ";
		for (i = h; i > 0; --i) cout << a[i] << " ";
		cout << "\n";
	}
 
	return 0;
}