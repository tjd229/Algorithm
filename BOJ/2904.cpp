//math
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int sieve[1000001];
vector<int> prime;
int cnt[101][78498];
int e[101];
ll _pow(ll b,int e) {
	ll res = 1;
	while (e) {
		if (e & 1) res *= b;
		b = b * b;
		e >>= 1;
	}
	return res;
}
int main() {
	int i,N;
	for (i = 2; i <= 1000000; ++i) {
		if (sieve[i]) continue;
		prime.push_back(i);
		for (ll j = (ll)i*i; j <= 1000000; j += i) sieve[j] = 1;
	}
	for (scanf("%d", &N), i = 1; i <= N; ++i) {
		scanf("%d",e+i);
		for (int j = 0; j < prime.size() && e[i]>1; ++j) {
			int p = prime[j];
			while (e[i] % p==0) {
				e[i] /= p;
				++cnt[i][j];
			}
		}
	}
	
	ll ans = 1; int op = 0;
	for (i = 0; i < 78498; ++i) {
		int tot = 0;
		for (int j = 1; j <= N; ++j) tot += cnt[j][i];
		tot /= N;
		for (int j = 1; j <= N; ++j) {
			if (tot > cnt[j][i]) op += tot - cnt[j][i];
		}
		ans *= _pow(prime[i],tot);
	}
	printf("%lld %d",ans,op);
	return 0;
}