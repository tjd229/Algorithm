//math
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <unordered_map>
#define ll long long 
#define pii pair<int,int>
using namespace std;
int main() {
	ll x, y, z; cin >> x >> y >> z;
	ll ans = x / z + y / z;
	ll debt = 0;
	x %= z; y %= z;
	
	ll tot = x + y;
	ll d= tot / z;
	if (d) {
		ans += d;
		ll p = d * z;
		ll a = p - x;
		ll b = p - y;
		debt = a < b ? a : b;
	}
	printf("%I64d %I64d",ans,debt);

	return 0;
}