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
int a[200001];
bool inv[200002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			inv[i] = (a[i] != i);
		}
		inv[n+1] = 0;
		int ans = 0;
		int len = 0;
		for (i = 1; i <= n+1; ++i) {
			if (inv[i]==0) {
				if (len > 0) ++ans;
				len = 0;
			}
			else ++len;
		}
		if (ans > 2) ans = 2;
		cout << ans << "\n";
	}
 
	return 0;
}