//dp
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
int h[200001];
ll lo[200001], hi[200001];
bool intersect(ll s1,ll e1,ll s2,ll e2) {
	if (e1 < s2 || e2 < s1) return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n, k; cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> h[i];
		lo[1] = hi[1] = h[1];
		bool flag = 1;
		for (i = 2; i < n && flag; ++i) {
			lo[i] = h[i], hi[i] = h[i] + k - 1;
			//printf("%d,%lld,%lld\n", flag, lo[i], hi[i]);
			if (intersect(lo[i - 1], hi[i - 1] + k-1, lo[i], hi[i] + k-1)) {
				lo[i] = max(lo[i], lo[i - 1] - (k - 1));
				hi[i] = min(hi[i], hi[i-1]+k-1);
			}
			else flag = 0;
			//printf("!%d,%lld,%lld\n", flag, lo[i], hi[i]);
		}
		if (flag) {
			if (!intersect(lo[n - 1], hi[n - 1]+k-1, h[n], h[n] + k - 1)) flag = 0;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}