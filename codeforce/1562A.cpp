//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int l, r; scanf("%d%d",&l,&r);
		int ans = r % l;
		int b = (r + 1) >> 1;
		if (l <= b && b <= r) {
			int a = b + b - 1;
			if (l <= a && a <= r && ans < a%b)
				ans = a % b;
		}
		printf("%d\n",ans);
	}
 
	return 0;
}