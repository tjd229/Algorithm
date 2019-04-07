//implementation
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
int c[300001];
int l[300001], r[300001];
int mn(int a, int b) {
	if (!a) return b;
	if (!b) return a;
	return a < b ? a : b;
}
int mx(int a, int b) {
	if (!a) return b;
	if (!b) return a;
	return a > b ? a : b;
}
int main() {
	int i, n;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> c[i];
		l[c[i]] = mn(l[c[i]], i);
		r[c[i]] = mx(r[c[i]], i);
	}
	vector<pii > L, R;//pos,c
	for (i = 1; i <= n; ++i) {
		if (l[i]) {
			L.push_back({ l[i],i });
			R.push_back({ -r[i],i });
		}
	}
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	pii l1 = L[0];
	pii r1 = R[0];
	int ans = 0;
	if (l1.second != r1.second) ans = max(ans, -r1.first - l1.first);
	if (R.size() > 1) {
		pii r2 = R[1];
		if (l1.second != r2.second) ans = max(ans, -r2.first - l1.first);
	}
	if (L.size() > 1) {
		pii l2 = L[1];
		if (l2.second != r1.second) ans = max(ans, -r1.first - l2.first);
	}
	if (L.size() > 1 && R.size()>1) {
		pii l2 = L[1];
		pii r2 = R[1];
		if (l2.second != r2.second) ans = max(ans, -r2.first - l2.first);
	}
	cout << ans;
	return 0;
}
