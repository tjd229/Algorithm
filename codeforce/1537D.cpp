//math, game
#include <stdio.h>
 
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int n; scanf("%d",&n);
		if (n & 1) printf("Bob\n");
		else {
			if (n == (n&-n)) {
				int e = 0;
				while ((1 << e) != n) ++e;
				if(e&1)printf("Bob\n");
				else printf("Alice\n");
			}
			else printf("Alice\n");
		}
	}
	
	return 0;
}