//math
#include <stdio.h>
#include <unordered_map>
#define ll long long
using namespace std;
unordered_map<int, int> mp;
int main() {
	int i, n, p, k;
	ll cnt = 0;
	for (scanf("%d%d%d", &n, &p, &k), i = 1; i <= n; ++i) {
		ll a; scanf("%I64d",&a);
		ll a4 = (a * a)%p;
		a4 = (a4 * a4)%p;
		ll val = a4 - (k * a)%p;
		while (val < 0) val += p;
		val %= p;
		cnt += mp[val];
		++mp[val];
	}
	printf("%I64d",cnt);
	return 0;
}