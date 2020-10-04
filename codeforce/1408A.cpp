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
int a[101], b[101], c[101];
int p[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i) cin >> b[i];
		for (i = 1; i <= n; ++i) cin >> c[i];
		p[1] = a[1];
		for (i = 2; i <= n; ++i) {
			p[i] = a[i];
			if (p[i] == p[i - 1]) p[i] = b[i];
			if (p[i] == p[i - 1]) p[i] = c[i];
		}
		if (p[1] == p[n] || p[n - 1] == p[n]) p[n] = a[n];
		if (p[1] == p[n] || p[n - 1] == p[n]) p[n] = b[n];
		if (p[1] == p[n] || p[n - 1] == p[n]) p[n] = c[n];
		for (i = 1; i <= n; ++i) cout << p[i] << " ";
		cout << "\n";
	}
 
	return 0;
}
