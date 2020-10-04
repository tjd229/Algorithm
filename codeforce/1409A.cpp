//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a, b; scanf("%d%d",&a,&b);
		int d = a - b;
		if (d < 0) d = -d;
		int ans = d / 10;
		ans += (d % 10) > 0;
		printf("%d\n",ans);
	}
 
	return 0;
}