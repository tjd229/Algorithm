//math
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int sieve[1100001];
ll deno[1000000];
ll n, b;
int main() {
	ll i,j;
	ll ans =-1;
	vector<ll> facto,prime;
	scanf("%I64d%I64d",&n,&b);
	for (i = 2;i<=1000000;++i) {		
		if (sieve[i]) continue;
		//if (i*i > b) break;
		prime.push_back(i);
		for (j = i*i; j <= 1000000 ; j += i) sieve[j] = 1;
	}
	i = 0;
	for (auto p : prime) {
		if (p > b) break;
		if (b%p) continue;
		while (b%p == 0) {
			b /= p;
			++deno[i];
		}
		facto.push_back(p);
		++i;
	}
	if (b>1) facto.push_back(b), ++deno[i];
	i = 0;
	for (auto p : facto) {
		ll nume = 0;
		ll num = n;
		while (num) {
			nume += num / p;
			num /= p;
		}
		
		//printf("%lld:%lld/%lld\n", p,nume,deno[i]);
		nume /= deno[i++];
		if (ans<0 || ans>nume) ans = nume;
	}
	printf("%I64d",ans);
	return 0;
}
