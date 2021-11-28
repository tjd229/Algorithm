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
int a[101];
bool chk(int x) {
	for (int i = 2; i*i <= x; ++i) {
		if (x%i == 0) return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int cum = 0;
		for (i = 1; i <= n; ++i) cin >> a[i],cum+=a[i];
		if (chk(cum)) {
			cout << n << "\n";
			for (i = 1; i <= n; ++i) cout << i << " ";
			cout << "\n";
		}
		else {
			int ban1 = 0, ban2 = 0;
			for (i = 1; i <= n; ++i) {
				if (chk(cum - a[i])) {
					ban1 = i;
					break;
				}
			}
			if (ban1 == 0) {
				for (i = 1; i <= n && ban1==0; ++i) {
					for (int j = i; j <= n && ban1==0; ++j) {
						if (chk(cum - a[i] - a[j])) {
							ban1 = i; ban2 = j;
						}
					}
				}
			}
			if (ban2 != 0) {
				cout << n-2 << "\n";
				for (i = 1; i <= n; ++i) {
					if (i == ban1) continue;
					if (i == ban2) continue;
					cout << i << " ";
				}
				cout << "\n";
			}
			else {
				cout << n - 1 << "\n";
				for (i = 1; i <= n; ++i) {
					if (i == ban1) continue;
					if (i == ban2) continue;
					cout << i << " ";
				}
				cout << "\n";
			}
		}
		
	}
 
 
	return 0;
}