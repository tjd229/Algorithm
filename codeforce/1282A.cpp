//implementation
#include <stdio.h>
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int a, b, c, r; scanf("%d%d%d%d",&a,&b,&c,&r);	
		if (a > b) a ^= b ^= a ^= b;
		int ans = b - a ;
		int s = c - r, e = c + r;
		//printf("%d,%d|%d,%d\n",a,b,s,e);
		if (!(b<s || e<a )) {
			//printf("!\n");
			if (s < a) s = a;
			if (e > b) e = b;
			int len = e - s ;
			ans -= len;
		}
		printf("%d\n",ans);
	}
	return 0;
}