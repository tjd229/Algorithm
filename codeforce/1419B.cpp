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
ll d[1000];
ll s[1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	d[1] = 1;
	s[1] = 1;
	ll base = 2;
	for (int i = 2; i <= 31; ++i) {
		d[i] = d[i - 1] + d[i - 1] + base * base;
		base += base;
		//cout << d[i] << endl;
		s[i] = s[i - 1] + d[i];
		//cout << s[i] << endl;
	}
	//cout << 1 000 000 000 000 000 000 << endl;
	//return 0;
	while (t--) {
		int i;
		ll x; cin >> x;
		int ans = 0;
		for (ans=2; ans < 32; ++ans) {
			if (s[ans] > x) {
				--ans;
				break;
			}
		}
		cout << ans << "\n";
	}
 
	return 0;
}