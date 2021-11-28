//greedy, geometry
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
int a[200001], b[200001];
ll v[200001], h[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i; ll n; cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
			v[i] = h[i] = 0;
		}
		for (i = 1; i <= n; ++i) {
			int x = a[i], y = b[i];
			++v[x]; ++h[y];
		}
		ll ans = n * (n - 1)*(n - 2) / 6;
		for (i = 1; i <= n; ++i) {
			int x = a[i], y = b[i];
			ll d = (v[x] - 1)*(h[y] - 1);
			ans -= d;
		}
		cout << ans << "\n";
	}
 
	return 0;
}