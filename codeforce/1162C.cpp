//math, game
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int cnt[100001];
int fi[100001], se[100001];
int main() {
	int i, n, k; cin >> n >> k;
	for (i = 1; i <= k; ++i) {
		int x; cin >> x;
		++cnt[x];
		if (0 == fi[x]) fi[x] = i;
		else se[x] = i;
	}
	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		if (cnt[i] < 1) ++ans;
	}
	for (i = 2; i <= n; ++i) {
		int t1 = fi[i - 1]; int t2 = se[i];
		if (t2 == 0) t2 = fi[i];
		if (cnt[i] * cnt[i - 1] == 0 || t1 >= t2) ++ans;// , printf("%d,%d\n", i - 1, i);
		t1 = fi[i]; t2 = se[i - 1];
		if (t2 == 0) t2 = fi[i-1];
		if (cnt[i] * cnt[i - 1] == 0 || t1 >= t2) ++ans;// , printf("%d,%d\n", i - 1, i);
	}
	cout << ans;
	return 0;
}