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
#define ll long long 
#define pii pair<int,int>
using namespace std;
int h[101];
int n;
int roll() {
	int i;
	for (i = 1; i < n; ++i) {
		if (h[i] < h[i + 1])
			return i;
	}
	return n;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i,  k; cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> h[i];
		int ans = -1;
		while (k>0) {
			int stop = roll();
			if (stop == n) {
				ans = -1;
				break;
			}
			--k;
			++h[stop];
			ans = stop;
		}
		cout << ans << "\n";
		
	}
 
	return 0;
}