//dp
#include <stdio.h>
#include <map>
#define ll long long
using namespace std;
map<ll, ll> memo;
ll N;
int P, Q;
ll A(ll i) {
	if (i == 0) return 1;
	if (memo[i]) return memo[i];
	ll res = A(i / Q) + A(i / P);
	memo[i] = res;
	return res;
}
int main() {
	scanf("%lld%d%d",&N,&P,&Q);
	printf("%lld",A(N));
	return 0;
}