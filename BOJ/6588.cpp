//math
#include <stdio.h>
#include<vector>
#define ll long long
using namespace std;
int sieve[1000001];
vector<int> prime;
int a[1000001], b[1000001];
int main() {
	int i;
	for (i = 2; i <= 1000000; ++i) {
		if (sieve[i]) continue;
		prime.push_back(i);
		for (ll j = (ll)i*i; j <= 1000000; j += i) sieve[j] = 1;
	}
	for (i = 6; i <= 1000000; i += 2) {
		for (int j = 1; j < prime.size() && i-prime[j]>2; ++j) {

			if (sieve[i - prime[j]]==0) {
				a[i] = prime[j];
				b[i] = i - a[i];
				break;
			}
		}
	}
	for (int n; scanf("%d", &n) && n;) {
		if (a[n] + b[n]) printf("%d = %d + %d\n",n,a[n],b[n]);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}