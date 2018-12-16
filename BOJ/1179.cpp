//dp

#include <stdio.h>
#define ll long long
ll kill(ll n, int m) {
	if (n == 1) return 0;
	else if (n < m) {
		return (kill(n - 1, m) + m) % n;
	}
	ll k = n / m;
	ll r = n % m; //shift
	ll n_ = kill(n-k,m) - r;
	if (n_ < 0) n_ += n - k;
	return n_ + n_ / (m - 1);
	
}
int main() {
	ll N;
	int M;
	scanf("%lld%d",&N,&M);
	printf("%lld",M==1? N:kill(N,M)+1);

	return 0;
}
