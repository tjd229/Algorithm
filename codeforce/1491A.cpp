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
int a[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n, q; cin >> n >> q;
	int cnt[2] = { 0 };
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			--cnt[a[x]];
			a[x] = 1 - a[x];
			++cnt[a[x]];
		}
		else {
			int k; cin >> k;
			if (k > cnt[1]) cout << "0\n";
			else cout << "1\n";
		}
	}
 
 
	return 0;
}