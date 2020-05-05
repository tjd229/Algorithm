//math, greedy
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
ll a[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	a[1] = 2;
	for (int i = 2; i <= 30; ++i) a[i] = a[i - 1] + a[i - 1];
	while (t--) {
		int n; cin >> n;
		int half = n >> 1;
		ll f = 0;
		ll s = 0;
		f = a[n];
		for (int i = 1; i <= half; ++i)
			s += a[n - i];
		for (int i = 1; i < half; ++i)
			f += a[i];
		cout << f - s << "\n";
	}
 
	return 0;
}