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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll s = 0;
		ll p = 1;
		vector<ll> sum;
		while (n > s) {
			sum.push_back(p);
			s += p;
			p += p;
		}
		ll diff = s - n;
		sum.back() -= diff;
		sort(sum.begin(), sum.end());
		int d = sum.size() - 1;
		cout << d << "\n";
		for (int i = 1; i < d + 1; ++i)
			cout << sum[i] - sum[i - 1] << " ";
		cout << "\n";
	}
 
	return 0;
}