//math
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int sieve[10000001];
vector<ll> p;
int main() {
	int i,ix=0; 
	ll A, B; scanf("%lld%lld", &A, &B);
	int l = -1;
	for (i = 2; i <= 10000000; ++i) {
		if (sieve[i]) continue;
		ll p2 = (ll)i*i;
		for (ll j = p2; j <= 10000000; j += i) sieve[j] = 1;
		while (1) {
			p.push_back(p2);
			if (p2 > 1e14 / i) break;
			p2 *= i;
		}
	}
	sort(p.begin(), p.end());
	for (i = 0; i < p.size() && B>=p[i]; ++i) {
		if (l < 0 && A <= p[i]) l = i;
		//printf("%lld\n",p[i]);
	}
	printf("%d",i-l);
	return 0;
}