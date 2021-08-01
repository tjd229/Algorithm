//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		long long n; scanf("%I64d",&n);
		long long ans = 0;
		long long d,res;
		if (n <= 6) ans = 15;
		else if (n <= 8) ans = 20;
		else if (n <= 10) ans = 25;
		else {
			if (n & 1) ++n;
			ans = n * 2.5;
			
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}