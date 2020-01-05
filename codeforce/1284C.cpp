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
ll f[250001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	if (n == 1) cout << 1;
	else {
		ll ans = 0;
		f[0] = f[1] = 1;
		for (int i = 2; i <= n; ++i)
			f[i] = f[i - 1] * i%m;
		
		for (int i = 1; i <= n; ++i) {
			ll in = f[i];
			ll pos = n + 1 - i;//==min
			ll r = f[n - i];
			ll t = in * pos%m;
			t = t * pos%m;
			t = t * r%m;
			ans = (ans + t) % m;
			//cout << ans << endl;
		}
		cout << ans;
	}
 
	return 0;
}