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
#define ll unsigned long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q; cin >> q;
	while (q--) {
		ll n, m; cin >> n >> m;
		ll m10 = m * 10;
		ll ans = 0;
		ll d10 = 0;//ans?
		ll r = m % 10;
		ll d = r;
		for (int i = 0; i < 10; ++i) {
			d10 += d;
			d += r;
			d %= 10;
		}
		ll nd = n / m10;
		ll nr = n %m10;
		/*cout << d10 << endl;
		cout << nd << endl;
		cout << nr << endl;
		cout << r << endl;*/
		ans = d10 * nd; d10 = 0; d = m;
		while (d <= nr) {
			d10 += d%10;
			d += m;
		}
		ans += d10;
		cout << ans << "\n";
	}
 
	return 0;
}