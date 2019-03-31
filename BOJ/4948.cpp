//math
#include <stdio.h>
int sieve[123456+123456+1];
int s[123456 + 123456 + 1];
int main() {
	int i, n;
	for (i = 2, n = 123456 + 123456; i <= n; ++i) {
		if (sieve[i]) continue;
		++s[i];
		for (long long j = (long long)i * i; j <= n; j += i) sieve[j] = 1;
	}
	for (i = 2; i <= n; ++i) s[i] += s[i - 1];
	for (; scanf("%d", &n) && n;)
		printf("%d\n",s[n+n]-s[n]);
	
	
	return 0;
}