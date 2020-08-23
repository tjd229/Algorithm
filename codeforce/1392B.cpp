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
const ll inf = int(2e9) + 10;
ll a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, n; ll k;
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> a[i];
		ll d = -inf;
		for (i = 1; i <= n; ++i)
			if (d < a[i]) d = a[i];
		if (k) {
			--k;
			for (i = 1; i <= n; ++i) a[i] = d - a[i];
		}
		d = -inf;
		if (k) {
			--k;
			for (i = 1; i <= n; ++i)
				if (d < a[i]) d = a[i];
 
			for (i = 1; i <= n; ++i) a[i] = d - a[i];
		}
		d = -inf;
		if (k) {
			--k;
			for (i = 1; i <= n; ++i)
				if (d < a[i]) d = a[i];
			for (i = 1; i <= n; ++i) a[i] = d - a[i];
		}
		if (k & 1) {
			d = -inf;
			for (i = 1; i <= n; ++i)
				if (d < a[i]) d = a[i];
			for (i = 1; i <= n; ++i) a[i] = d - a[i];
 
		}
		for (i = 1; i <= n; ++i) cout << a[i] << " ";
		cout << "\n";
	}
 
	return 0;
}