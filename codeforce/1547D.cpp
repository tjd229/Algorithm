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
int x[200001], y[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> x[i];
		if (n == 1) {
			cout << "0\n";
		}
		else {
			y[1] = 0;
			for (i = 2; i <= n; ++i) {
				y[i] = (x[i] | x[i - 1]) ^ x[i];
				x[i] ^= y[i];
			}
			for (i = 1; i <= n; ++i)
				cout << y[i] << " ";
			cout << "\n";
		}
	}
 
	return 0;
}
