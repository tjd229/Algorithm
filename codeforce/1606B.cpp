//math
#include <iostream>
#include <string>
#define ll long long
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		if (n == 1) cout << "0\n";
		else {
			ll base = 1;
			ll h = 0;
			while (base <= k && base<n) {
				++h;
				base += base;
			}
			ll done = base;
			ll yet = n - done;
			if (yet > 0) {
				h += yet / k + ((yet % k) > 0);
			}
			cout << h << "\n";
		}
		
	}
 
 
	return 0;
}