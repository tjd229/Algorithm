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
#include <tuple>
#include <numeric>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int a[100001];
ll gcd(ll a, ll b) {
	if (a > b) a^=b ^= a ^= b;
	if (a == 0) return b;//a<b
	return gcd(b%a, a);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; cin >> n;
		int mx = 0;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
			if (mx < a[i]) mx = a[i];
		}
		ll cum = 1;
		bool flag = 1;
		for (i = 1; i <= n && flag; ++i) {
			if (cum <= mx) {
				ll d = gcd(cum, 1 + i);
				cum = cum * (1 + i) / d;
				
			}
			if (a[i] % cum==0) flag = 0;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		
	}
 
 
	return 0;
}