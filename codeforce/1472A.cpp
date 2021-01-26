//math
#include <stdio.h>
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int w, h, n; scanf("%d%d%d",&w,&h,&n);
		int cnt = 1;
		while (cnt<n && (w & 1) == 0) {
			cnt += cnt;
			w >>= 1;
		}while (cnt < n && (h & 1) == 0) {
			cnt += cnt;
			h>>= 1;
		}
		printf("%s\n",cnt>=n? "YES":"NO");
	}
 
	return 0;
}