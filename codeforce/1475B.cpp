//math
#include <stdio.h>
int main() {
	int t; scanf("%d",&t);
	while (t--) {
		int n; scanf("%d",&n);
		if (n < 2020) {
			printf("NO\n");
			continue;
		}
		int div = n / 2020;
		int r = n-div * 2020;
		
		printf("%s\n",div>=r? "YES":"NO");
	}
	return 0;
}