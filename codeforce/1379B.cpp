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
		ll l, r, m; cin >> l >> r >> m;
		ll d = r - l;
		ll s = m - d, e = m + d;
		ll a, b=-1, c=-1;
		for (ll i = l; i <= r && c<0; ++i) {
			ll n = s / i;
			//printf("%lld,%lld\n",n,i);
			while (n*i <= e) {
				//printf("%lld,%lld,%lld(%lld)\n",i,l,r,n*i);
				if (n>0 && n*i >= s) {
					a = i;					
					ll diff = m-n * i;
					if (diff > 0) {
						c = l;
						b = l + diff;
					}
					else if (diff == 0) b = c = l;
					else {
						b = l;
						c = l - diff;
					}
					//
 
					break;
				}
				++n;
			}
			//printf("%lld,%lld,%lld\n", a,b,c);
		}
		cout << a << " " << b << " " << c << "\n";
	}
 
	return 0;
}