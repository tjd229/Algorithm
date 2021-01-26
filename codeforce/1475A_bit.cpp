//math
#include <stdio.h>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		long long n; scanf("%I64d", &n);
		n -= (n&-n);
		printf("%s\n", n ? "YES" : "NO");
	}
	return 0;
}