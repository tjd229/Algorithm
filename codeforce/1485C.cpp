//math
#include <stdio.h>
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int x, y; scanf("%d%d",&x,&y);
		long long ans = 0;
		for (int d = 1; d < y; ++d) {
			long long mnb = d + 1;
			if ((mnb+1)*d > x) break;
			long long mxb = y;
			if ((mxb+1)*d > x) {
				mxb = x / d-1;
			}
			if (mnb > mxb) break;
			ans += mxb - mnb+1;
 
		}
		printf("%I64d\n",ans);
	}
 
	return 0;
}