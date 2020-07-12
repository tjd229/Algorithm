//math
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
		vector<int> v;
		for (ll i = 2; i*i <= n; ++i) {
			while (n%i == 0) {
				v.push_back(i);
				n /= i;
			}			
		}
		if (n > 1) v.push_back(n);
		if (v.size() == 1)
			cout << 1 << " " << n - 1 << "\n";
		else {
			ll base = 1;
			for (int i = 1; i < v.size(); ++i)
				base *= v[i];
			
			cout << base << " " << (v[0]-1) * base << "\n";
		}
	}
 
	return 0;
}