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
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		ll ans = min(z1,y2);
		z1 -= ans; y2 -= ans;
		ans += ans; //*2
		int p = x1 + z1;
		int mn = min(p, z2);
		z2 -= mn;
		//printf("%lld,%d\n",ans,z2);
		ans -= z2 + z2;
		cout << ans << "\n";
		
	}
 
	return 0;
}