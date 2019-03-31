//math
#include <stdio.h>
int sieve[1001];
int main() {
	int N, K, i;
	int P;
	for (scanf("%d%d", &N, &K), i = 2; i <= N; ++i) {
		if (sieve[i]) continue;
		P = i;
		sieve[P] = 1;
		if (--K == 0) break;
		for (P = i * i; P <= N; P += i) {
			if (sieve[P] == 0) {
				if (--K == 0) {
					i = N + 1;
					break;
				}
			}
			sieve[P] = 1;
		}
	}
	printf("%d",P);
	return 0;
}