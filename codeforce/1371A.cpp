//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		if (n < 2) printf("1\n");
		else {
			int ans = n >> 1;
			ans += n & 1;
			printf("%d\n",ans);
		}
	}
	return 0;
}
