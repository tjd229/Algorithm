//greedy, implementation
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
int c[100001];
int n, k;
int paint(int tgt) {
	int cnt = 0;
	for (int i = 1; i <= n;) {
		if (c[i] == tgt) ++i;
		else {
			i += k;
			++cnt;
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; cin >> n >> k;
		int mx = 0;
		int ans = n;
		for (i = 1; i <= n; ++i) {
			cin >> c[i];
			if (mx < c[i]) mx = c[i];
		}
		for (int tgt = 1; tgt <= mx; ++tgt) {
			int cnt = paint(tgt);
			if (ans > cnt) ans = cnt;
		}
		cout << ans << "\n";
	}
 
 
	return 0;
}