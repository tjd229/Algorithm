//math
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll a[200001], b[200001];
ll gcd(ll a, ll b) {//a<b
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main() {
	int i, n, m;
	for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i) scanf("%I64d",a+i);
	for (i = 1; i <= m; ++i) scanf("%I64d",b+i);
	if (n == 1) {
		for (i = 1; i <= m; ++i) printf("%I64d ",a[1]+b[i]);
	}
	else {
		vector<ll> d;
		sort(a + 1, a + 1 + n);
		for (i = 2; i <= n; ++i) d.push_back(a[i] - a[1]);
		sort(d.begin(), d.end());
		ll dgcd;
		if (d.size() == 1) dgcd = d[0];
		else {
			dgcd = gcd(d[0], d[1]);
			for (i = 2; i < d.size(); ++i) {
				ll a = dgcd, b = d[i];
				if (a > b) a ^= b ^= a ^= b;
				dgcd=gcd(a, b);
			}
		}
		for (i = 1; i <= m; ++i) {
			ll x = a[1] + b[i];
			ll y = dgcd;
			if (x > y) x ^= y ^= x ^= y;
			printf("%I64d ",gcd(x,y));
		}
	}
	return 0;
}
