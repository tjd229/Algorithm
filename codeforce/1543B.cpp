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
int a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		ll s = 0;
		for (i = 1; i <= n; ++i) cin >> a[i],s+=a[i];
		ll mean = s / n;
		ll r = s % n;
		ll mn = n - r;
		cout << mn * r << "\n";
		
	}
 
	return 0;
}