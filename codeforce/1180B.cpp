//greedy
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
int a[100001];
int main() {
	int i, n;
	vector<pii > order;
	cin >> n;
	int _n = (n >> 1) << 1;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		int aa = a[i];
		if (aa < 0) aa = -aa - 1;
		order.push_back({ aa,i });
	}
	sort(order.begin(), order.end());
	for (i = 0; i < _n; ++i) {
		int ix = order[i].second;
		if (a[ix] >= 0) a[ix] = -a[ix] - 1;
	}
	if (n & 1) {
		int ix = order.back().second;
		if (a[ix] < 0) a[ix] = -a[ix] - 1;
	}
	for (i = 1; i <= n; ++i) cout << a[i] << " ";

	return 0;
}