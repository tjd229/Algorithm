//math
#include <stdio.h>
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		long long n; scanf("%I64d",&n);
		long long base = 2;
		bool flag = 1;
		while (flag && base <= n) {
			if (base == n) flag = 0;
			base += base;
		}
		printf("%s\n",flag? "YES":"NO");
	}
	return 0;
}