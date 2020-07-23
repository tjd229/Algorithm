//math
#include <stdio.h>
int main() {
	int i, t;
	for (scanf("%d", &t); t--;) {
		int x, y, z; scanf("%d%d%d",&x,&y,&z);
		int a = 0, b = 0, c = 0;
		if (x == y && x > z) {
			a = x;
			b =c= z;			
		}
		else if (x == z && x > y) {
			b = x;
			a = c = y;
		}
		else if (y == z && y > x) {
			c = y;
			a = b = x;
		}
		else if (x == y && y == z) a = b = c = x;
		if (a == 0 || b == 0 || c == 0) printf("NO\n");
		else printf("YES\n%d %d %d\n",a,b,c);
		
		
	}
	return 0;
}
