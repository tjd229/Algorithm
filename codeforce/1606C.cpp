//math, greedy
#include <iostream>
#include <string>
#define ll long long
using namespace std;
int a[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, n; int k;
		cin >> n >> k;
		for (i = 0; i < n; ++i) cin >> a[i];
		ll s = 0;
		ll base = 1; int e = 0;
		for (i = 0; i < n && k>0; ++i) {
			while (e < a[i]) {
				++e;
				base *= 10;
			}
			if (i + 1 < n) {
				int d = a[1 + i] - a[i];
				ll diff = 1;
				for (int j = 0; j < d; ++j) diff *= 10;
				--diff;
				if (diff > k) {
					s += (1 + k)*base;
					k = -1;
				}
				else {
					k -= diff;
					s += (diff)*base;
					if (k == 0)
						s += base * (1+diff);
				}
			}
			else
				s += (1 + k)*base;
			//cout << s << endl;
		}
		cout << s << "\n";
		
	}
 
 
	return 0;
}