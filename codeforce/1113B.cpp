//math
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
int a[50001];
vector<int> d[101];
int ex[101];
int main() {
	int i, n;
	int j;
	int s = 0;
	int ans = 0;
	cin >> n;
	for (i = 2; i <= 100; ++i) {
		for (j = i+1; j <= 100; ++j) {
			if (j%i == 0) d[j].push_back(i);
		}
	}
	for (i = 1; i <= n; ++i) cin >> a[i], s += a[i],ex[a[i]]=1;
	sort(a + 1, a + 1 + n);
	ans = s;
	for (i = 1; i <= 100; ++i) {
		if (!ex[i]) continue;
		if (d[i].empty()) continue;
		for (auto x : d[i]) {
			int _s = s - (i + a[1]);
			_s += i / x + a[1] * x;
			if (ans > _s) ans = _s;
		}
	}

	cout << ans;
	return 0;
}
